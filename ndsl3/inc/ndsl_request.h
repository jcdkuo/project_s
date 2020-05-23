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

#ifndef __NDSL_REQUEST_H__
#define __NDSL_REQUEST_H__

#include "ndsl.h"

SCODE GetRequest(TSearchInfo *ptSearch, int iSearchType, char *optarg);
SCODE ComposeSearchByName(TSearchInfo *ptSearch, char *pszName);
SCODE ComposeSearchByAge(TSearchInfo *ptSearch, char *pszAge);
SCODE ComposeSearchByRetired(TSearchInfo *ptSearch);
SCODE ComposeSearchByTitle(TSearchInfo *ptSearch, char *pszJobName);

#endif // __NDSL_REQUEST_H__