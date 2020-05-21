/* 
 *  Copyright (c) 2020-2030 Sophie Inc. All rights reserved.
 *
 *  +-----------------------------------------------------------------+
 *  | THIS SOFTWARE IS FURNISHED UNDER A LICENSE AND MAY ONLY BE USED |
 *  | AND COPIED IN ACCORDANCE WITH THE TERMS AND CONDITIONS OF SUCH  |
 *  | A LICENSE AND WITH THE INCLUSION OF THE THIS COPY RIGHT NOTICE. |
 *  | THIS SOFTWARE OR ANY OTHER COPIES OF THIS SOFTWARE MAY NOT BE   |
 *  | PROVIDED OR OTHERWISE MADE AVAILABLE TO ANY OTHER PERSON. THE   |
 *  | OWNERSHIP AND TITLE OF THIS SOFTWARE IS NOT TRANSFERRED.        |
 *  |                                                                 |
 *  | THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT   |
 *  | ANY PRIOR NOTICE AND SHOULD NOT BE CONSTRUED AS A COMMITMENT BY |
 *  | SOPHIE INC.                                                     |
 *  +-----------------------------------------------------------------+
 */

#include "ndsl.h"

void usage(void)
{
	printf("\nUsage:\n"
		   "        ndsl3 -[n|a|t] arg [-r] [-h]\n"
		   "Options:\n"
		   "	-n Search by Name\n"
           "	-a Search by Age (older than)\n"
		   "	-r Search by Retirement\n"
		   "	-t Search by Job Title\n"
		   "	-h Show this help\n\n"
		   );
	exit(1);
}

int main(int argc, char *argv[])
{
    int             iCh = 0;
    TSearchInfo     tSearchInfo;
    TNDSL           tNDSL;
    TMessageHandler tMsgHandler;
    SCODE           sReturn = S_OK;

    // Do not input any argument
    if (argc == 1) usage();

    memset(&tSearchInfo, 0, sizeof(TSearchInfo));

	while ((iCh = getopt(argc, argv, "n:a:t:rdh")) != -1) 
	{
		switch (iCh) {
		case 'n':
            GetRequest(&tSearchInfo, SEARCH_NAME, optarg);
			break;
		case 'a':
            GetRequest(&tSearchInfo, SEARCH_AGE, optarg);       
			break;
		case 'r':
            GetRequest(&tSearchInfo, SEARCH_RETIRED, NULL);
			break;
		case 't':
            GetRequest(&tSearchInfo, SEARCH_TITLE, optarg);
			break;
		case 'h':
			usage();
			break;
        case '?': /* Error handle: Mainly missing arg or illegal option */
            fprintf(stderr, "Illegal option:-%c\n", isprint(optopt)?optopt:'#');
            usage();
            break;
		default:
            usage();
		}
	}

    // Initialization
    if ((sReturn = NDSL_Initialize(&tNDSL)) != S_OK)
    {
        ERROR("%s:%d %s\n", __func__, __LINE__, INITIALIZATION_FAILED);
        return ERROR_INITIALIZATION_FAILED;
    }

    // Prepare Handler
    tMsgHandler.hSearchInfo = (HANDLE)(&tSearchInfo);
    tMsgHandler.hInitilizer = (HANDLE)(&tNDSL);

    // Handle message
    if ((sReturn = HandleMessage(&tMsgHandler)) != S_OK)
    {
        ERROR("%s:%d %s\n", __func__, __LINE__, HANDLE_MESSAGE_FAILED);
        return ERROR_HANDLE_MESSAGE_FAILED;
    }

    // Output XML format results
    if (strlen(tMsgHandler.acSendBuffer) != 0)
        printf("\n%s:%d %s\n\n", __func__, __LINE__, tMsgHandler.acSendBuffer);

    return 0;
}


