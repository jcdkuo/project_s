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

SCODE GetRequest(TSearchInfo *ptSearch, int iSearchType, char *optarg)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptSearch, "ptSearch") != S_OK);
    RETURN_SFAIL_IF(iSearchType < 0);

#ifdef TRACECODE
    TRACE(__func__, __LINE__);
#endif

    switch (iSearchType)
    {
        case SEARCH_NAME:
            ComposeSearchByName(ptSearch, optarg);
            break;
        case SEARCH_AGE:
            ComposeSearchByAge(ptSearch, optarg);
            break;
        case SEARCH_RETIRED:
            ComposeSearchByRetired(ptSearch);
            break;
        case SEARCH_TITLE:
            ComposeSearchByTitle(ptSearch, optarg);
            break;
        case SEARCH_UNKNOWN:
            // No related information
            WARN("\n%s:%d Not Support!\n\n", __func__, __LINE__);
            break;
        default:
            WARN("\n%s:%d Wrong Job Status!\n\n", __func__, __LINE__);
    }

    return S_OK;
}

SCODE ComposeSearchByName(TSearchInfo *ptSearch, char *pszName)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptSearch, "ptSearch") != S_OK);
    RETURN_SFAIL_IF(checkNull(__func__, pszName, "pszName") != S_OK);

    ptSearch->iCommand = SEARCH_NAME;
    snprintf(ptSearch->acRecvBuffer, MAX_RECVBUFFER_SIZE, "%s", pszName);

#ifdef DEBUG
    DBPRINT("%s:%d ptSearch->acRecvBuffer = %s\n", __func__, __LINE__, ptSearch->acRecvBuffer);
#endif

    return S_OK;
}

SCODE ComposeSearchByAge(TSearchInfo *ptSearch, char *pszAge)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptSearch, "ptSearch") != S_OK);
    RETURN_SFAIL_IF(checkNull(__func__, pszAge, "pszAge") != S_OK);

    ptSearch->iCommand = SEARCH_AGE;
    snprintf(ptSearch->acRecvBuffer, MAX_RECVBUFFER_SIZE, "%s", pszAge);

#ifdef DEBUG
    DBPRINT("%s:%d ptSearch->acRecvBuffer = %s\n", __func__, __LINE__, ptSearch->acRecvBuffer);
#endif

    return S_OK;
}

SCODE ComposeSearchByRetired(TSearchInfo *ptSearch)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptSearch, "ptSearch") != S_OK);

    ptSearch->iCommand = SEARCH_RETIRED;

#ifdef DEBUG
    DBPRINT("%s:%d ptSearch->iCommand = %d\n", __func__, __LINE__, ptSearch->iCommand);
#endif

    return S_OK;
}

SCODE ComposeSearchByTitle(TSearchInfo *ptSearch, char *pszJobName)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptSearch, "ptSearch") != S_OK);
    RETURN_SFAIL_IF(checkNull(__func__, pszJobName, "pszJobName") != S_OK);

    ptSearch->iCommand = SEARCH_TITLE;
    snprintf(ptSearch->acRecvBuffer, MAX_RECVBUFFER_SIZE, "%s", pszJobName);

#ifdef DEBUG
    DBPRINT("%s:%d ptSearch->acRecvBuffer = %s\n", __func__, __LINE__, ptSearch->acRecvBuffer);
#endif

    return S_OK;
}
