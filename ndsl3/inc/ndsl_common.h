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

#ifndef __NDSL_COMMON_H__
#define __NDSL_COMMON_H__

#include "ndsl.h"

/* Enum and Structure */
typedef struct {

    const char  *cpcName;
    int         iValue;

} TNnVPair;

typedef void *HANDLE;
typedef SCODE (*FNDSLProcess)(HANDLE hObject, char *pcOutput, int iBufferSize);

typedef struct {

    /* Action name */
    char            *pcMethodName;
    /* Fucntion to handle the action */
    FNDSLProcess    pfnProcess;

} TNDSLMethod;

typedef enum _classtype {

    TYPE_TEACHER    = 0,
    TYPE_SENIOR     = 1,
    TYPE_JUNIOR     = 2,
    TYPE_UNKNOWN    = 3,

} EJobType;

typedef enum {

    INFO_FIRSTNAME  = 0,
    INFO_LASTNAME   = 1,
    INFO_AGE        = 2,

} EInfoType;

typedef enum {

    COM_NTUST       = 0,
    COM_ALPHA       = 1,
    COM_BETA        = 2,
    COM_OMEGA       = 3,
    COM_UNKNOWN     = 4,

} ECompanyPool;

typedef enum {

    STATUS_IN_SCHOOL    = 1,
    STATUS_IN_SERVICE   = 2,
    STATUS_RETIREMENT   = 3,
    STATUS_UNKNOWN      = 4,

} EJobStatus;

typedef struct _name {

    char    acFirstName[MAX_STRING_SIZE];
    char    acLastName[MAX_STRING_SIZE];

} TName;

typedef struct _title {

    char    acName[MAX_STRING_SIZE];
    int     iSeniority;

} TTitle;

typedef struct {

    char    acName[MAX_STRING_SIZE];

} TCompany, TRetiredFrom;

typedef struct _person {

    TName           tName;
    unsigned int    iAge;
    bool            bRetired;
    TTitle          tTitle;
    TCompany        tCompany;

} TPerson;

typedef struct {

    int         iNDSLNum;
    TPerson     atPerson[MAX_PERSON_NUM];

} TNDSL;

/* Functions */
SCODE checkNull(const char *pCaller, const void *pCheckTarget, const char *pCheckName);
SCODE stringCompare(char *pcString1, char *pcString2);

#endif //__NDSL_COMMON_H__
