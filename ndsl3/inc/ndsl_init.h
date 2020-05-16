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

#ifndef __NDSL_INIT_H__
#define __NDSL_INIT_H__

#include "ndsl.h"

/* Enum and Structure */
typedef struct _personalinfo {

    const char      *cpcFirstName;
    const char      *cpcLastName;
    unsigned int    iAge;
    EJobStatus      eJobStatus;
    EJobType        eJobType;
    int             iSeniority;
    ECompanyPool    eCompany;

} TPersonRawData;

/* Functions */
SCODE NDSL_Initialize(TNDSL *ptNDSL);

#endif //__NDSL_INIT_H__
