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
 *  | SOPHIE INC.                                                    |
 *  +-----------------------------------------------------------------+
 */

#ifndef __PERSON_COMMON_H__
#define __PERSON_COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "ndsl_define.h"

/* Enum and Structure */
typedef struct _NnVPair
{
    const   char*   cpcFirstName;
    const   char*   cpcLastName;
    unsigned int    iAge;

} TNnVPair;

typedef enum _classtype {

    CLASS_TEACHER   = 0,
    CLASS_SENIOR    = 1,
    CLASS_JUNIOR    = 2,
    CLASS_TOTAL     = 3,

} EClassType;

typedef enum {

    INFO_FIRSTNAME  = 0,
    INFO_LASTNAME   = 1,
    INFO_AGE        = 2,

} EInfoType;

typedef struct _name {

    char    acFirstName[MAX_STRING_SIZE];
    char    acLastName[MAX_STRING_SIZE];

} TName;

typedef struct _title {
    
    char    acJobName[MAX_STRING_SIZE];
    int     iSeniority;

} TTitle;

typedef struct _person {

    TName           tName;
    TTitle          tTitle;
    unsigned int    iAge;
    
} TPerson;

typedef struct {

    int         iNDSLNum;
    TPerson     atPerson[MAX_PERSON_NUM];

} TNDSL;

/* Functions */
SCODE NDSL_Initialize(TNDSL *ptNDSL);

#endif //__PERSON_COMMON_H__
