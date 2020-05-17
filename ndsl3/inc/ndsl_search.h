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

#endif //__NDSL_SEARCH_H__