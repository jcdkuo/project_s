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
		   "        ndsl3 -c conig_file [-d] [-h]\n"
		   "Options:\n"
		   "	-c [config_file] The configuration file, default is /etc/conf.d/config_onvif/config_onvifstoraged.xml\n"
		   "	-d Daemonize\n"
		   "	-h Show this help\n\n"
		   );
	exit(1);
}

int main(int argc, char *argv[])
{
    int     iCh = 0;
    TNDSL   tNDSL;
    SCODE   sReturn = S_OK;

	while ((iCh = getopt(argc, argv, "c:dh")) != -1) 
	{
		switch (iCh) {
		case 'c':
			//pcConfFile = optarg;
			break;
		case 'd':
			//daemon(0,0);
			break;
		case 'h':
			usage();
			break;
		default:
			usage();
		}
	}

    // Initialization
    if ((sReturn = NDSL_Initialize(&tNDSL)) != S_OK)
        return ERROR_INITIALIZATION_FAILED;

    return 0;
}


