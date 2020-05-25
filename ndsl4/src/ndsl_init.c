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

#include "ndsl.h"

#define SPACE   HasEmptySpace
#define DATA    StillHasData

/* Static Functions */
static bool HasEmptySpace(int iIndex);
static bool StillHasData(int iIndex);
static SCODE GetPerson(TPerson *ptPerson, int iIndex);
static SCODE GetName(TName *ptName, int iIndex);
static SCODE GetAge(unsigned int *piAge, int iIndex);
static SCODE GetJobStatus(bool *pbStatus, int iIndex);
static SCODE GetTitle(TTitle *ptTitle, int iIndex);
static SCODE GetCompany(TCompany *ptCompany, int iIndex);

TPersonRawData g_szPerson[] = {
    { "Jimmy",  "Chiu", 67, STATUS_RETIREMENT,  TYPE_TEACHER,   30, COM_NTUST},
    { "Jerry",  "Kuo",  43, STATUS_IN_SERVICE,  TYPE_SENIOR,    13, COM_ALPHA},
    { "Sophie", "Wang", 26, STATUS_IN_SERVICE,  TYPE_JUNIOR,    2,  COM_BETA},
    { "Kent",   "Chen", 38, STATUS_IN_SERVICE,  TYPE_SENIOR,    12, COM_OMEGA},
    { "Goku",   "Son",  47, STATUS_IN_SERVICE,  TYPE_GENIUS,    36, COM_JUMP},
    { "Jerry",  "Wang", 26, STATUS_RETIREMENT,  TYPE_GENIUS,    8,  COM_FAIRY},
    { NULL,     NULL,   0,  0,                  0,              0,  0},
};

TNnVPair g_atJobType[] = {
    {"Professor",       TYPE_TEACHER},
    {"Senior Engineer", TYPE_SENIOR},
    {"Junior Engineer", TYPE_JUNIOR},
    {"Fighter",         TYPE_GENIUS},
    {"Unknown",         TYPE_UNKNOWN},
};

TNnVPair g_atCompany[] = {
    {"NTUST",           COM_NTUST},
    {"ALPHA.com",       COM_ALPHA},
    {"BETA Inc.",       COM_BETA},
    {"OMEGA CO.",       COM_OMEGA},
    {"Jump Comics",     COM_JUMP},
    {"Fairyland",       COM_FAIRY},
    {"Unknown",         COM_UNKNOWN},
};

SCODE NDSL_Initialize(TNDSL *ptNDSL)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptNDSL, "ptNDSL") != S_OK);

    TNDSL *ptInitNDSL = ptNDSL;
    int iPerson = 0;

    // Sanitize
    memset(ptInitNDSL, 0, sizeof(TNDSL));

    // Initialize
    while (SPACE(iPerson) && DATA(iPerson))
    {
        // Person Information
        RETURN_SFAIL_IF(GetPerson(&ptInitNDSL->atPerson[iPerson], iPerson) != S_OK);

        // Person Count
        iPerson++;
    }

    // Total number of Persons
    ptInitNDSL->iNDSLNum = iPerson;

#ifdef INIT
    INITIAL("\n%s:%d iNDSLNum = %d\n\n", __func__, __LINE__, ptInitNDSL->iNDSLNum);
#endif

    // Show Info
#ifdef INIT
    INITIAL("%s:%d [Show all raw data]\n\n", __func__, __LINE__);
    RETURN_SFAIL_IF_NOT(NDSL_Show(ptInitNDSL) == S_OK);
    INITIAL("%s:%d [EOF]\n\n", __func__, __LINE__);
#endif

    return S_OK;
}

static bool HasEmptySpace(int iIndex)
{
    return (iIndex < MAX_PERSON_NUM)?TRUE:FALSE;
}

static bool StillHasData(int iIndex)
{
    return (g_szPerson[iIndex].cpcFirstName != NULL)?TRUE:FALSE;
}

static SCODE GetPerson(TPerson *ptPerson, int iIndex)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptPerson, "ptPerson") != S_OK);
    RETURN_SFAIL_IF((iIndex < 0) || (iIndex > MAX_PERSON_NUM));

#ifdef INIT
    INITIAL("\n%s:%d GetPerson Index: %d\n", __func__, __LINE__, iIndex);
#endif

    RETURN_SFAIL_IF(GetName(&ptPerson->tName, iIndex) != S_OK);
    RETURN_SFAIL_IF(GetAge(&ptPerson->iAge, iIndex) != S_OK);
    RETURN_SFAIL_IF(GetJobStatus(&ptPerson->bRetired, iIndex) != S_OK);
    RETURN_SFAIL_IF(GetTitle(&ptPerson->tTitle, iIndex) != S_OK);
    RETURN_SFAIL_IF(GetCompany(&ptPerson->tCompany, iIndex) != S_OK);

    return S_OK;
}

static SCODE GetName(TName *ptName, int iIndex)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptName, "ptName") != S_OK);
    RETURN_SFAIL_IF((iIndex < 0) || (iIndex > MAX_PERSON_NUM));

    snprintf(ptName->acFirstName, MAX_STRING_SIZE, "%s", g_szPerson[iIndex].cpcFirstName);
    snprintf(ptName->acLastName, MAX_STRING_SIZE, "%s", g_szPerson[iIndex].cpcLastName);

#ifdef INIT
    INITIAL("%s:%d ptName->acFirstName = %s\n", __func__, __LINE__, ptName->acFirstName);
    INITIAL("%s:%d ptName->acLastName = %s\n", __func__, __LINE__, ptName->acLastName);
#endif

    return S_OK;
}

static SCODE GetAge(unsigned int *piAge, int iIndex)
{
    RETURN_SFAIL_IF(checkNull(__func__, piAge, "piAge") != S_OK);
    RETURN_SFAIL_IF((iIndex < 0) || (iIndex > MAX_PERSON_NUM));

    *piAge = g_szPerson[iIndex].iAge;

#ifdef INIT
    INITIAL("%s:%d *piAge = %d\n", __func__, __LINE__, *piAge);
#endif

    return S_OK;
}

static SCODE GetJobStatus(bool *pbStatus, int iIndex)
{
    RETURN_SFAIL_IF(checkNull(__func__, pbStatus, "pbStatus") != S_OK);
    RETURN_SFAIL_IF((iIndex < 0) || (iIndex > MAX_PERSON_NUM));

    switch (g_szPerson[iIndex].eJobStatus)
    {
        case STATUS_IN_SERVICE:
            *pbStatus = FALSE;
            break;
        case STATUS_RETIREMENT:
            *pbStatus = TRUE;
            break;
        case STATUS_IN_SCHOOL:
        case STATUS_UNKNOWN:
            // No related information
            printf("\n%s:%d Not Support!\n\n", __func__, __LINE__);
            break;
        default:
            printf("\n%s:%d Wrong Job Status!\n\n", __func__, __LINE__);
            break;
    }

#ifdef INIT
    INITIAL("%s:%d *pbStatus = %d\n", __func__, __LINE__, (int)*pbStatus);
#endif

    return S_OK;
}

static SCODE GetTitle(TTitle *ptTitle, int iIndex)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptTitle, "ptTitle") != S_OK);
    RETURN_SFAIL_IF((iIndex < 0) || (iIndex > MAX_PERSON_NUM));

    int iType = 0;

    for (iType = 0; iType < TYPE_UNKNOWN; iType++)
    {
        if (g_szPerson[iIndex].eJobType == g_atJobType[iType].iValue)
        {
            snprintf(ptTitle->acName, MAX_STRING_SIZE, "%s", g_atJobType[iType].cpcName);
        }
    }

    ptTitle->iSeniority = g_szPerson[iIndex].iSeniority;

#ifdef INIT
    INITIAL("%s:%d ptTitle->acName = %s\n", __func__, __LINE__, ptTitle->acName);
    INITIAL("%s:%d ptTitle->iSeniority = %d\n", __func__, __LINE__, ptTitle->iSeniority);
#endif

    return S_OK;
}

static SCODE GetCompany(TCompany *ptCompany, int iIndex)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptCompany, "ptCompany") != S_OK);
    RETURN_SFAIL_IF((iIndex < 0) || (iIndex > MAX_PERSON_NUM));

    int iCompany = 0;

    for (iCompany = 0; iCompany < COM_UNKNOWN; iCompany++)
    {
        if (g_szPerson[iIndex].eCompany == g_atCompany[iCompany].iValue)
        {
            snprintf(ptCompany->acName, MAX_STRING_SIZE, "%s", g_atCompany[iCompany].cpcName);
        }
    }

#ifdef INIT
    INITIAL("%s:%d ptCompany->acName = %s\n", __func__, __LINE__, ptCompany->acName);
#endif

    return S_OK;
}
