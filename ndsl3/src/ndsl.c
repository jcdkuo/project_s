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

static SCODE NDSL_Show(TNDSL *ptNDSL);

int main()
{
    TNDSL   tNDSL;
    SCODE   sReturn = S_OK;

    // Initialization
    NDSL_Initialize(&tNDSL);

    if (sReturn != S_OK) return ERROR_INITIALIZATION_FAILED;

    // Show Info
    sReturn = NDSL_Show(&tNDSL);
    if (sReturn != S_OK) return ERROR_SHOW_MESSAGE_FAILED;

    return 0;
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
        printf("Job      : %s\n", ptNDSL->atPerson[iIndex].tTitle.acJobName);
        printf("Seniority: %d\n", ptNDSL->atPerson[iIndex].tTitle.iSeniority);
        printf("\n");
    }
    
    return S_OK;
}
