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

#ifdef INITIAL_0
static SCODE GetPersonByIndex(TPerson *ptPerson, int iIndex);
#endif

#ifndef INITIAL_2
static SCODE GetNameByIndex(TName *ptName, int iIndex);
static SCODE GetTitleByIndex(TTitle *ptTitle, int iIndex);
static SCODE GetAgeByIndex(unsigned int *piAge, int iIndex);
#endif


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

#ifdef INITIAL_0
SCODE NDSL_Initialize(TNDSL *ptNDSL)
{
    RETURN_SFAIL_IF_NULL(ptNDSL);

    TNDSL   *ptInitNDSL = ptNDSL;
    int     iNDSLIndex;

    // Sanitize
    memset(ptInitNDSL, 0, sizeof(TNDSL));

    RETURN_SFAIL_IF(CLASS_TOTAL > MAX_PERSON_NUM);

    printf("\n%s:%d\n\n", __func__, __LINE__);
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
#endif

#ifdef INITIAL_1
SCODE NDSL_Initialize(TNDSL *ptNDSL)
{
    RETURN_SFAIL_IF_NULL(ptNDSL);
    
    TNDSL   *ptInitNDSL = ptNDSL;
    int     iNDSLIndex;

    // Sanitize
    memset(ptInitNDSL, 0, sizeof(TNDSL));

    RETURN_SFAIL_IF(CLASS_TOTAL > MAX_PERSON_NUM);

    printf("\n%s:%d\n\n", __func__, __LINE__);
    for (iNDSLIndex = 0; iNDSLIndex < CLASS_TOTAL; iNDSLIndex++)
    {
        // Initialize
        RETURN_SFAIL_IF_NOT(GetNameByIndex(&ptInitNDSL->atPerson[iNDSLIndex].tName, iNDSLIndex) == S_OK);
        RETURN_SFAIL_IF_NOT(GetTitleByIndex(&ptInitNDSL->atPerson[iNDSLIndex].tTitle, iNDSLIndex) == S_OK);
        RETURN_SFAIL_IF_NOT(GetAgeByIndex(&ptInitNDSL->atPerson[iNDSLIndex].iAge, iNDSLIndex) == S_OK);

        // Person Count
        ptInitNDSL->iNDSLNum++;
        //printf("%s:%d iNDSLNum = %s\n", __func__, __LINE__, ptInitNDSL->iNDSLNum);

    }

    return S_OK;
}
#endif

#ifdef INITIAL_2
SCODE NDSL_Initialize(TNDSL *ptNDSL)
{
    RETURN_SFAIL_IF_NULL(ptNDSL);

    TNDSL   *ptInitNDSL = ptNDSL;
    int     iNDSLIndex;

    // Sanitize
    memset(ptInitNDSL, 0, sizeof(TNDSL));

    RETURN_SFAIL_IF(CLASS_TOTAL > MAX_PERSON_NUM);

#ifdef SOPHIE_VER
    printf("\n%s:%d *** Sophie version ***\n\n", __func__, __LINE__);
#else
    printf("\n%s:%d *** Jerry version ***\n\n", __func__, __LINE__);
#endif

    for (iNDSLIndex = 0; iNDSLIndex < CLASS_TOTAL; iNDSLIndex++)
    {
        // Initialize
#ifdef SOPHIE_VER

        TPerson *ptPerson = &ptInitNDSL->atPerson[iNDSLIndex];

        // Get Name
        snprintf(ptPerson->tName.acFirstName, MAX_STRING_SIZE, "%s", g_atNDSLInfo[iNDSLIndex].cpcFirstName);
        snprintf(ptPerson->tName.acLastName, MAX_STRING_SIZE, "%s", g_atNDSLInfo[iNDSLIndex].cpcLastName);

        // Get Job Info
        snprintf(ptPerson->tTitle.acJobName, MAX_STRING_SIZE, "%s", g_pszJobName[iNDSLIndex]);
        ptPerson->tTitle.iSeniority = g_iSeniority[iNDSLIndex];

        // Get Age
        ptPerson->iAge = g_atNDSLInfo[iNDSLIndex].iAge;

#else // JERRY_VER

        // Get Name
        snprintf(ptInitNDSL->atPerson[iNDSLIndex].tName.acFirstName, MAX_STRING_SIZE, "%s", g_atNDSLInfo[iNDSLIndex].cpcFirstName);
        snprintf(ptInitNDSL->atPerson[iNDSLIndex].tName.acLastName, MAX_STRING_SIZE, "%s", g_atNDSLInfo[iNDSLIndex].cpcLastName);

        // Get Job Info
        snprintf(ptInitNDSL->atPerson[iNDSLIndex].tTitle.acJobName, MAX_STRING_SIZE, "%s", g_pszJobName[iNDSLIndex]);
        ptInitNDSL->atPerson[iNDSLIndex].tTitle.iSeniority = g_iSeniority[iNDSLIndex];

        // Get Age
        ptInitNDSL->atPerson[iNDSLIndex].iAge = g_atNDSLInfo[iNDSLIndex].iAge;
#endif
        // Person Count
        ptInitNDSL->iNDSLNum++;
        //printf("%s:%d iNDSLNum = %s\n", __func__, __LINE__, ptInitNDSL->iNDSLNum);

    }

    return S_OK;
}
#endif

#ifdef INITIAL_0
static SCODE GetPersonByIndex(TPerson *ptPerson, int iIndex)
{
    RETURN_SFAIL_IF_NULL(ptPerson);
    RETURN_SFAIL_IF((iIndex < 0) || (iIndex > CLASS_TOTAL));

    RETURN_SFAIL_IF_NOT(GetNameByIndex(&ptPerson->tName, iIndex) == S_OK);
    RETURN_SFAIL_IF_NOT(GetTitleByIndex(&ptPerson->tTitle, iIndex) == S_OK);
    RETURN_SFAIL_IF_NOT(GetAgeByIndex(&ptPerson->iAge, iIndex) == S_OK);

    return S_OK;
}
#endif

#ifndef INITIAL_2
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
#endif
