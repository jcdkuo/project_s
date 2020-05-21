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

SCODE checkNull(const char *pCaller, const void *pCheckTarget, const char *pCheckName)
{
    if (pCheckTarget == NULL)
    {
        printf("[%s] Bad arguments. %s is NULL\n", pCaller, pCheckName);
        return S_FAIL;
    }
    return S_OK;
}

SCODE stringCompare(char *pcString1, char *pcString2)
{
    RETURN_SFAIL_IF_NULL(pcString1);
    RETURN_SFAIL_IF_NULL(pcString2);

    if (strlen(pcString1) == strlen(pcString2))
    {
        if (strncmp(pcString1, pcString2, strlen(pcString1)) == 0)
        {
            return S_OK;
        }
    }
    return S_FAIL;
}

SCODE strCaseCompare(char *pcString1, char *pcString2)
{
    RETURN_SFAIL_IF_NULL(pcString1);
    RETURN_SFAIL_IF_NULL(pcString2);

    if (strlen(pcString1) == strlen(pcString2))
    {
        if (strncasecmp(pcString1, pcString2, strlen(pcString1)) == 0)
        {
            return S_OK;
        }
    }
    return S_FAIL;
}

SCODE NDSL_Show(TNDSL *ptNDSL)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptNDSL, "ptNDSL") != S_OK);
    RETURN_SFAIL_IF(ptNDSL->iNDSLNum < 0);

#ifdef TRACECODE
    TRACE(__func__, __LINE__);
#endif

    int iIndex;

    for (iIndex = 0; iIndex < ptNDSL->iNDSLNum; iIndex++)
    {
        INFO("\n");
        INFO("--- %d ---\n", (iIndex + 1));
        INFO("Name     : %s %s\n", ptNDSL->atPerson[iIndex].tName.acFirstName, ptNDSL->atPerson[iIndex].tName.acLastName);
        INFO("Age      : %d\n", ptNDSL->atPerson[iIndex].iAge);

        if (ptNDSL->atPerson[iIndex].bRetired == TRUE)
            INFO("Status   : Retirement\n");
        else
            INFO("Status   : Not Retired\n");

        INFO("Job      : %s\n", ptNDSL->atPerson[iIndex].tTitle.acName);
        INFO("Seniority: %d\n", ptNDSL->atPerson[iIndex].tTitle.iSeniority);
        INFO("Company  : %s\n", ptNDSL->atPerson[iIndex].tCompany.acName);
        INFO("\n");
    }

    return S_OK;
}
