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

#include "ndsl_common.h"

static SCODE GetPersonByIndex(TPerson *ptPerson, int iIndex);
static SCODE GetNameByIndex(TName *ptName, int iIndex);
static SCODE GetTitleByIndex(TTitle *ptTitle, int iIndex);
static SCODE GetAgeByIndex(unsigned int *piAge, int iIndex);


TNnVPair g_atNDSLInfo[] = {
    [CLASS_TEACHER]   = {"Jimmy",   "Chiu", 67},
    [CLASS_SENIOR]    = {"Jerry",   "Kuo",  43},
    [CLASS_JUNIOR]    = {"Sophie",  "Wang", 26},
    [CLASS_TOTAL]     = {NULL,      NULL,   0},
};

char *g_pszJobName[] = {
    [CLASS_TEACHER]   = "Professor",
    [CLASS_SENIOR]    = "Supervisor",
    [CLASS_JUNIOR]    = "Engineer",
    [CLASS_TOTAL]     = NULL,
};

int g_iSeniority[] = {
    [CLASS_TEACHER]   = 30,
    [CLASS_SENIOR]    = 13,
    [CLASS_JUNIOR]    = 2,
    [CLASS_TOTAL]     = 0,   
};

SCODE NDSL_Initialize(TNDSL *ptNDSL)
{
    RETURN_SFAIL_IF_NULL(ptNDSL);
    
    TNDSL   *ptInitNDSL = ptNDSL;
    int     iNDSLIndex;

    // Sanitize
    memset(ptInitNDSL, 0, sizeof(TNDSL));

    RETURN_SFAIL_IF(CLASS_TOTAL > MAX_PERSON_NUM);

    for (iNDSLIndex = 0; iNDSLIndex < CLASS_TOTAL; iNDSLIndex++)
    {
        // Initialize
        RETURN_SFAIL_IF_NOT(GetPersonByIndex(&ptInitNDSL->atPerson[iNDSLIndex], iNDSLIndex) == S_OK);
        
        // Person Count
        ptInitNDSL->iNDSLNum++;
        //printf("%s:%d iNDSLNum = %s\n", __func__, __LINE__, ptInitNDSL->iNDSLNum);

    }

    return S_OK;
}

static SCODE GetPersonByIndex(TPerson *ptPerson, int iIndex)
{
    RETURN_SFAIL_IF_NULL(ptPerson);
    RETURN_SFAIL_IF((iIndex < 0) || (iIndex > CLASS_TOTAL));

    RETURN_SFAIL_IF_NOT(GetNameByIndex(&ptPerson->tName, iIndex) == S_OK);
    RETURN_SFAIL_IF_NOT(GetTitleByIndex(&ptPerson->tTitle, iIndex) == S_OK);
    RETURN_SFAIL_IF_NOT(GetAgeByIndex(&ptPerson->iAge, iIndex) == S_OK);

    return S_OK;
}

static SCODE GetNameByIndex(TName *ptName, int iIndex)
{
    RETURN_SFAIL_IF_NULL(ptName);
    RETURN_SFAIL_IF((iIndex < 0) || (iIndex > CLASS_TOTAL));

    snprintf(ptName->acFirstName, MAX_STRING_SIZE, "%s", g_atNDSLInfo[iIndex].cpcFirstName);
    snprintf(ptName->acLastName, MAX_STRING_SIZE, "%s", g_atNDSLInfo[iIndex].cpcLastName);

    //printf("%s:%d ptName->acFirstName = %s\n", __func__, __LINE__, ptName->acFirstName);
    return S_OK;
}

static SCODE GetTitleByIndex(TTitle *ptTitle, int iIndex)
{
    RETURN_SFAIL_IF_NULL(ptTitle);
    RETURN_SFAIL_IF((iIndex < 0) || (iIndex > CLASS_TOTAL));
    
    snprintf(ptTitle->acJobName, MAX_STRING_SIZE, "%s", g_pszJobName[iIndex]);
    ptTitle->iSeniority = g_iSeniority[iIndex];

    //printf("%s:%d ptTitle->acJobName = %s\n", __func__, __LINE__, ptTitle->acJobName);
    return S_OK;
}

static SCODE GetAgeByIndex(unsigned int *piAge, int iIndex)
{
    RETURN_SFAIL_IF_NULL(piAge);
    RETURN_SFAIL_IF((iIndex < 0) || (iIndex > CLASS_TOTAL));
    
    *piAge = g_atNDSLInfo[iIndex].iAge;
    
    return S_OK;
}

