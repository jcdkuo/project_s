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

#ifndef __NDSL_SEARCH_H__
#define __NDSL_SEARCH_H__

#include "ndsl.h"

typedef enum {

    SEARCH_NAME     = 0,
    SEARCH_AGE      = 1,
    SEARCH_RETIRED  = 2,
    SEARCH_TITLE    = 3,
    SEARCH_UNKNOWN  = 4,

} ESearchType;

/* Enum and Structure */
typedef struct {

    int     iCommand;
    char    acRecvBuffer[MAX_RECVBUFFER_SIZE];

} TSearchInfo;

typedef struct {

    char    acName[MAX_RECVBUFFER_SIZE];

} TSearchName;

typedef struct {

    unsigned iAge;

} TSearchAge;

typedef struct {

    bool    bRetired;

} TSearchRetired;

typedef struct {

    TTitle  tTitle;

} TSearchTitle;

typedef struct {

    /* Search Result */
    bool        bResult;
    /* Request info handle */
    HANDLE      hSearchInfo;
    /* Initilizer handle */
    HANDLE      hInitilizer;

} TSearchHandler;

/* Functions */
SCODE SearchByName(HANDLE hObject, char *pcOutput, int iBufferSize);
SCODE SearchByAge(HANDLE hObject, char *pcOutput, int iBufferSize);
SCODE SearchByRetired(HANDLE hObject, char *pcOutput, int iBufferSize);
SCODE SearchByTitle(HANDLE hObject, char *pcOutput, int iBufferSize);

SCODE Parse_SearchName(HANDLE hObject, TSearchName *ptSN);
SCODE Parse_SearchAge(HANDLE hObject, TSearchAge *ptSA);
SCODE Parse_SearachRetired(HANDLE hObject, TSearchRetired *ptSR);
SCODE Parse_SearchTitle(HANDLE hObject, TSearchTitle *ptST);

SCODE Process_SearchName(HANDLE hObject, TSearchName *ptSN, TSearchResponse *ptSNRes);
SCODE Process_SearchAge(HANDLE hObject, TSearchAge *ptSA, TSearchResponse *ptSAResp);
SCODE Process_SearchRetired(HANDLE hObject, TSearchRetired *ptSR, TSearchResponse *ptSRRes);
SCODE Process_SearchTitle(HANDLE hObject, TSearchTitle *ptST, TSearchResponse *ptSTRes);

SCODE Compose_SearchResponse(TSearchResponse *ptRes, char *pcOutput, int iBufferSize);
SCODE Compose_SearchFault(char *pcOutput, int iBufferSize);

#endif //__NDSL_SEARCH_H__
