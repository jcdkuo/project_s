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

#ifndef __NDSL_COMMON_H__
#define __NDSL_COMMON_H__

#include "ndsl.h"

/* Enum and Structure */
typedef void *HANDLE;
typedef SCODE (*FNDSLProcess)(HANDLE hObject, char *pcOutput, int iBufferSize);
typedef struct
{

    /* Action name */
    char *pcMethodName;
    /* Fucntion to handle the action */
    FNDSLProcess pfnProcess;

} TNDSLMethod;

typedef enum _classtype
{

    CLASS_TEACHER = 0,
    CLASS_SENIOR = 1,
    CLASS_JUNIOR = 2,
    CLASS_TOTAL = 3,

} EJobType;

typedef enum
{

    INFO_FIRSTNAME = 0,
    INFO_LASTNAME = 1,
    INFO_AGE = 2,

} EInfoType;

typedef enum
{

    COM_NTUST = 0,
    COM_VIVOTEK = 1,
    COM_DELTA = 2,
    COM_UBNT = 3,

} ECompanyPool;

typedef enum
{

    STATUS_IN_SCHOOL = 1,
    STATUS_IN_SERVICE = 2,
    STATUS_RETIREMENT = 3,

} EJobStatus;

typedef struct _name
{

    char acFirstName[MAX_STRING_SIZE];
    char acLastName[MAX_STRING_SIZE];

} TName;

typedef struct _title
{

    char acJobName[MAX_STRING_SIZE];
    int iSeniority;

} TTitle;

typedef struct
{

    char acCompanyName[MAX_STRING_SIZE];
    char acLocation[MAX_STRING_SIZE];

} TCompanayInfo;

typedef struct
{

    char acRetireFrom[MAX_STRING_SIZE];
    char acHome[MAX_STRING_SIZE];

} TRetirement;

typedef struct _person
{

    TName tName;
    unsigned int iAge;
    TTitle tTitle;
    

} TPerson;

typedef struct
{

    int iNDSLNum;
    TPerson atPerson[MAX_PERSON_NUM];

} TNDSL;

typedef struct _personalinfo
{

    const char *cpcFirstName;
    const char *cpcLastName;
    unsigned int iAge;
    EJobStatus eJobStatus;
    EJobType eJobType;
    int iSeniority;
    const char *cpcJobName;
    const char *cpcJobLocation;

} TPersonalInfo;

/* Functions */
SCODE NDSL_Initialize(TNDSL *ptNDSL);

#endif //__NDSL_COMMON_H__
