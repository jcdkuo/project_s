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

#include "ndsl.h"

/* Static Functions */
static SCODE GetPersonByIndex(TPerson *ptPerson, int iIndex);
static SCODE GetNameByIndex(TName *ptName, int iIndex);
static SCODE GetTitleByIndex(TTitle *ptTitle, int iIndex);
static SCODE GetAgeByIndex(unsigned int *piAge, int iIndex);
static SCODE NDSL_Show(TNDSL *ptNDSL);

TPersonRawData g_szPerson[] = {
    {"Jimmy", "Chiu", 67, STATUS_RETIREMENT, TYPE_TEACHER, 30, COM_NTUST},
    {"Jerry", "Kuo", 43, STATUS_IN_SERVICE, TYPE_SENIOR, 13, COM_ALPHA},
    {"Sophie", "Wang", 26, STATUS_IN_SERVICE, TYPE_JUNIOR, 2, COM_BETA},
    {"Kent", "Chen", 38, STATUS_IN_SERVICE, TYPE_SENIOR, 12, COM_OMEGA},
    {NULL, NULL, 0, 0, 0, 0, 0},
};

TNnVPair g_atJobType[] = {
    {"Professor", TYPE_TEACHER},
    {"Senior Engineer", TYPE_SENIOR},
    {"Junior Engineer", TYPE_JUNIOR},
    {"Unknown", TYPE_UNKNOWN},
};

TNnVPair g_atCompany[] = {
    {"NTUST", COM_NTUST},
    {"ALPHA", COM_ALPHA},
    {"BETA", COM_BETA},
    {"OMEGA", COM_OMEGA},
    {"Unknown", COM_UNKNOWN},
};

SCODE NDSL_Initialize(TNDSL *ptNDSL)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptNDSL, "ptNDSL") != S_OK);

    TNDSL *ptInitNDSL = ptNDSL;
    int iIndex = 0;

    // Sanitize
    memset(ptInitNDSL, 0, sizeof(TNDSL));
    printf("\n%s:%d iNDSLNum = %d\n\n", __func__, __LINE__, ptInitNDSL->iNDSLNum);

    // Initialize
    while ((ptInitNDSL->iNDSLNum < MAX_PERSON_NUM) && (g_szPerson[ptInitNDSL->iNDSLNum].cpcFirstName != NULL))
    {
        // Get Name
        snprintf(ptInitNDSL->atPerson[ptInitNDSL->iNDSLNum].tName.acFirstName, MAX_STRING_SIZE, "%s", g_szPerson[ptInitNDSL->iNDSLNum].cpcFirstName);
        snprintf(ptInitNDSL->atPerson[ptInitNDSL->iNDSLNum].tName.acLastName, MAX_STRING_SIZE, "%s", g_szPerson[ptInitNDSL->iNDSLNum].cpcLastName);

        // Get Age
        ptInitNDSL->atPerson[ptInitNDSL->iNDSLNum].iAge = g_szPerson[ptInitNDSL->iNDSLNum].iAge;

        // Get Job Status
        switch (g_szPerson[ptInitNDSL->iNDSLNum].eJobStatus)
        {
        case STATUS_IN_SERVICE:
            ptInitNDSL->atPerson[ptInitNDSL->iNDSLNum].bRetired = FALSE;
            break;
        case STATUS_RETIREMENT:
            ptInitNDSL->atPerson[ptInitNDSL->iNDSLNum].bRetired = TRUE;
            break;
        case STATUS_IN_SCHOOL:
        case STATUS_UNKNOWN:
            // No related information
        default:
            printf("\n%s:%d Wrong Job Status!\n\n", __func__, __LINE__);
        }

        // Get Job Type
        for (iIndex = 0; iIndex < TYPE_UNKNOWN; iIndex++)
        {
            if (g_szPerson[ptInitNDSL->iNDSLNum].eJobType == g_atJobType[iIndex].iValue)
            {
                snprintf(ptInitNDSL->atPerson[ptInitNDSL->iNDSLNum].tTitle.acName, MAX_STRING_SIZE, "%s", g_atJobType[iIndex].cpcName);
            }
        }

        // Get Seniority
        ptInitNDSL->atPerson[ptInitNDSL->iNDSLNum].tTitle.iSeniority = g_szPerson[ptInitNDSL->iNDSLNum].iSeniority;

        // Get Company
        for (iIndex = 0; iIndex < COM_UNKNOWN; iIndex++)
        {
            if (g_szPerson[ptInitNDSL->iNDSLNum].eCompany == g_atCompany[iIndex].iValue)
            {
                snprintf(ptInitNDSL->atPerson[ptInitNDSL->iNDSLNum].tCompany.acName, MAX_STRING_SIZE, "%s", g_atCompany[iIndex].cpcName);
            }
        }

        // Person Count
        ptInitNDSL->iNDSLNum++;
    }

    printf("\n%s:%d iNDSLNum = %d\n\n", __func__, __LINE__, ptInitNDSL->iNDSLNum);

    // Show Info
    RETURN_SFAIL_IF_NOT(NDSL_Show(ptInitNDSL) == S_OK);

    return S_OK;
}

static SCODE NDSL_Show(TNDSL *ptNDSL)
{
    RETURN_SFAIL_IF_NULL(ptNDSL);
    RETURN_SFAIL_IF(ptNDSL->iNDSLNum < 0);

    int iIndex;

    for (iIndex = 0; iIndex < ptNDSL->iNDSLNum; iIndex++)
    {
        printf("--- %d ---\n", (iIndex + 1));
        printf("Name     : %s %s\n", ptNDSL->atPerson[iIndex].tName.acFirstName, ptNDSL->atPerson[iIndex].tName.acLastName);
        printf("Age      : %d\n", ptNDSL->atPerson[iIndex].iAge);

        if (ptNDSL->atPerson[iIndex].bRetired == TRUE)
            printf("Status   : Retirement\n");
        else
            printf("Status   : Not Retired\n");

        printf("Job      : %s\n", ptNDSL->atPerson[iIndex].tTitle.acName);
        printf("Seniority: %d\n", ptNDSL->atPerson[iIndex].tTitle.iSeniority);
        printf("Company  : %s\n", ptNDSL->atPerson[iIndex].tCompany.acName);
        printf("\n");
    }

    return S_OK;
}
