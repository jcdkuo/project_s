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

static TNDSLMethod  g_tNDSLMethodMapping[] = {

    {SEARCH_NAME,       SearchByName},
    {SEARCH_AGE,        SearchByAge},
    {SEARCH_RETIRED,    SearchByRetired},
    {SEARCH_TITLE,      SearchByTitle},

    {SEARCH_UNKNOWN,    NULL}
};

SCODE HandleMessage(TMessageHandler *ptMsg)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptMsg, "ptMsg") != S_OK);

    int             iMethod = 0, iSearch = -1, iBufferSize;
    char            *pcOutput = ptMsg->acSendBuffer;
    TSearchInfo     *ptSearch = (TSearchInfo *)ptMsg->hSearchInfo;
    TSearchHandler  tSearchHandler;

    memset(&tSearchHandler, 0, sizeof(TSearchHandler));

#ifdef TRACECODE
    TRACE(__func__, __LINE__);
#endif

    tSearchHandler.hSearchInfo  = ptMsg->hSearchInfo;
    tSearchHandler.hInitilizer  = ptMsg->hInitilizer;
    iBufferSize                 = sizeof(ptMsg->acSendBuffer);
    iSearch                     = ptSearch->iCommand;

    for (iMethod = 0; g_tNDSLMethodMapping[iMethod].pfnProcess != NULL; iMethod++)
    {
        if (g_tNDSLMethodMapping[iMethod].iCommandType == iSearch)
        {
            return g_tNDSLMethodMapping[iMethod].pfnProcess((HANDLE)&tSearchHandler, pcOutput, iBufferSize);
        }
    }

    /* Command not support */
    RETURN_SFAIL_IF(g_tNDSLMethodMapping[iMethod].iCommandType == SEARCH_UNKNOWN);

    return S_OK;
}
