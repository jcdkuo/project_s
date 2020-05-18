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

SCODE SearchByName(HANDLE hObject, char *pcOutput, int iBufferSize)
{
    TSearchName     tSN;
    TSearchResponse tSNRes;
    SCODE           sRet = S_OK;

    printf("%s:%d \n", __func__, __LINE__);

    // Parse
    sRet = Parse_SearchName(hObject, &tSN);

    // Process
    if (sRet == S_OK)
        sRet = Process_SearchName(hObject, &tSN, &tSNRes);

    // Compose
    if (sRet == S_OK)
        //Compose_SearchResponse(&tSNRes, pcOutput, iBufferSize);
        NDSL_Show(&tSNRes);
    else
        Compose_SearchFault(pcOutput, iBufferSize);

    return S_OK;
}

SCODE SearchByAge(HANDLE hObject, char *pcOutput, int iBufferSize)
{
    TSearchAge      tSA;
    TSearchResponse tSARes;
    SCODE           sRet = S_OK;

    printf("%s:%d \n", __func__, __LINE__);

    // Parse
    sRet = Parse_SearchAge(hObject, &tSA);

    // Process
    if (sRet == S_OK)
        sRet = Process_SearchAge(hObject, &tSA, &tSARes);

    // Compose
    if (sRet == S_OK)
        //Compose_SearchResponse(&tSARes, pcOutput, iBufferSize);
        NDSL_Show(&tSARes);
    else
        Compose_SearchFault(pcOutput, iBufferSize);

    return S_OK;
}

SCODE SearchByRetired(HANDLE hObject, char *pcOutput, int iBufferSize)
{
    TSearchRetired  tSR;
    TSearchResponse tSRRes;
    SCODE           sRet = S_OK;

    printf("%s:%d \n", __func__, __LINE__);

    // Parse
    sRet = Parse_SearachRetired(hObject, &tSR);

    // Process
    if (sRet == S_OK)
        sRet = Process_SearchRetired(hObject, &tSR, &tSRRes);

    // Compose
   if (sRet == S_OK)
        Compose_SearchResponse(&tSRRes, pcOutput, iBufferSize);
    else
        Compose_SearchFault(pcOutput, iBufferSize);

    return S_OK;
}

SCODE SearchByTitle(HANDLE hObject, char *pcOutput, int iBufferSize)
{
    TSearchTitle    tST;
    TSearchResponse tSTRes;
    SCODE           sRet = S_OK;

    printf("%s:%d \n", __func__, __LINE__);

    // Parse
    sRet = Parse_SearchTitle(hObject, &tST);

    // Process
    if (sRet == S_OK)
        sRet = Process_SearchTitle(hObject, &tST, &tSTRes);

    // Compose
   if (sRet == S_OK)
        Compose_SearchResponse(&tSTRes, pcOutput, iBufferSize);
    else
        Compose_SearchFault(pcOutput, iBufferSize);

    return S_OK;
}

/* Parse functions */
SCODE Parse_SearchName(HANDLE hObject, TSearchName *ptSN)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptSN, "ptSN") != S_OK);

    TSearchHandler  *ptSearch   = (TSearchHandler *)hObject;
    TSearchInfo     *ptInfo     = (TSearchInfo *)ptSearch->hSearchInfo;

    snprintf(ptSN->acName, MAX_RECVBUFFER_SIZE, "%s", ptInfo->acRecvBuffer);

    printf("%s:%d ptSN->acName = %s\n", __func__, __LINE__, ptSN->acName);

    return S_OK;
}

SCODE Parse_SearchAge(HANDLE hObject, TSearchAge *ptSA)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptSA, "ptSA") != S_OK);

    TSearchHandler  *ptSearch   = (TSearchHandler *)hObject;
    TSearchInfo     *ptInfo     = (TSearchInfo *)ptSearch->hSearchInfo;

    ptSA->iAge = atoi(ptInfo->acRecvBuffer);

    printf("%s:%d ptSA->iAge = %d\n", __func__, __LINE__, ptSA->iAge);

    return S_OK;
}

SCODE Parse_SearachRetired(HANDLE hObject, TSearchRetired *ptSR)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptSR, "ptSR") != S_OK);

    ptSR->bRetired = TRUE;

    printf("%s:%d ptSR->bRetired = %d\n", __func__, __LINE__, (int)ptSR->bRetired);

    return S_OK;
}

SCODE Parse_SearchTitle(HANDLE hObject, TSearchTitle *ptST)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptST, "ptST") != S_OK);

    TSearchHandler  *ptSearch   = (TSearchHandler *)hObject;
    TSearchInfo     *ptInfo     = (TSearchInfo *)ptSearch->hSearchInfo;

    snprintf(ptST->tTitle.acName, MAX_STRING_SIZE, "%s", ptInfo->acRecvBuffer);

    printf("%s:%d ptST->tTitle.acName = %s\n", __func__, __LINE__, ptST->tTitle.acName);

    return S_OK;
}

/* Process functions */
SCODE Process_SearchName(HANDLE hObject, TSearchName *ptSN, TSearchResponse *ptSNRes)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptSN, "ptSN") != S_OK);
    RETURN_SFAIL_IF(checkNull(__func__, ptSNRes, "ptSNRes") != S_OK);

    TSearchHandler  *ptSearch   = (TSearchHandler *)hObject;
    TNDSL           *ptInit     = (TNDSL *)ptSearch->hInitilizer;
    char            acFullName[MAX_RECVBUFFER_SIZE];
    int             iIndex;

    memset(ptSNRes, 0, sizeof(TSearchResponse));

    for (iIndex = 0; iIndex < ptInit->iNDSLNum; iIndex++)
    {
        snprintf(acFullName, MAX_RECVBUFFER_SIZE, "%s %s",
            ptInit->atPerson[iIndex].tName.acFirstName, ptInit->atPerson[iIndex].tName.acLastName);

        printf("%s:%d acFullName = %s\n", __func__, __LINE__, acFullName);
        printf("%s:%d acFirstName = %s\n", __func__, __LINE__, ptInit->atPerson[iIndex].tName.acFirstName);
        printf("%s:%d acLastName = %s\n", __func__, __LINE__, ptInit->atPerson[iIndex].tName.acLastName);

        if ((stringCompare(ptSN->acName, acFullName) == S_OK) ||
            (stringCompare(ptSN->acName, ptInit->atPerson[iIndex].tName.acFirstName) == S_OK) ||
            (stringCompare(ptSN->acName, ptInit->atPerson[iIndex].tName.acLastName) == S_OK))
        {
            memcpy(&ptSNRes->atPerson[ptSNRes->iNDSLNum], &ptInit->atPerson[iIndex], sizeof(TPerson));
            ptSNRes->iNDSLNum++;
        }
    }

    return S_OK;
}

SCODE Process_SearchAge(HANDLE hObject, TSearchAge *ptSA, TSearchResponse *ptSARes)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptSA, "ptSA") != S_OK);
    RETURN_SFAIL_IF(checkNull(__func__, ptSARes, "ptSARes") != S_OK);

    TSearchHandler  *ptSearch   = (TSearchHandler *)hObject;
    TNDSL           *ptInit     = (TNDSL *)ptSearch->hInitilizer;
    int             iIndex;

    memset(ptSARes, 0, sizeof(TSearchResponse));

    for (iIndex = 0; iIndex < ptInit->iNDSLNum; iIndex++)
    {
        if (ptInit->atPerson[iIndex].iAge > ptSA->iAge)
        {
            memcpy(&ptSARes->atPerson[ptSARes->iNDSLNum], &ptInit->atPerson[iIndex], sizeof(TPerson));
            ptSARes->iNDSLNum++;
        }
    }
printf("%s:%d \n", __func__, __LINE__);
    return S_OK;
}

SCODE Process_SearchRetired(HANDLE hObject, TSearchRetired *ptSR, TSearchResponse *ptSRRes)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptSR, "ptSR") != S_OK);
    RETURN_SFAIL_IF(checkNull(__func__, ptSRRes, "ptSRRes") != S_OK);

    TSearchHandler  *ptSearch   = (TSearchHandler *)hObject;
    TNDSL           *ptInit     = (TNDSL *)ptSearch->hInitilizer;
    int             iIndex;

    memset(ptSRRes, 0, sizeof(TSearchResponse));

    for (iIndex = 0; iIndex < ptInit->iNDSLNum; iIndex++)
    {
        if (ptSR->bRetired == ptInit->atPerson[iIndex].bRetired)
        {
            memcpy(&ptSRRes->atPerson[ptSRRes->iNDSLNum], &ptInit->atPerson[iIndex], sizeof(TPerson));
            ptSRRes->iNDSLNum++;
        }
    }

    return S_OK;
}

SCODE Process_SearchTitle(HANDLE hObject, TSearchTitle *ptST, TSearchResponse *ptSTRes)
{
    RETURN_SFAIL_IF(checkNull(__func__, ptST, "ptST") != S_OK);
    RETURN_SFAIL_IF(checkNull(__func__, ptSTRes, "ptSTRes") != S_OK);

    TSearchHandler  *ptSearch   = (TSearchHandler *)hObject;
    TNDSL           *ptInit     = (TNDSL *)ptSearch->hInitilizer;
    int             iIndex;

    memset(ptSTRes, 0, sizeof(TSearchResponse));

    for (iIndex = 0; iIndex < ptInit->iNDSLNum; iIndex++)
    {
        if (stringCompare(ptST->tTitle.acName, ptInit->atPerson[iIndex].tTitle.acName) == S_OK)
        {
            memcpy(&ptSTRes->atPerson[ptSTRes->iNDSLNum], &ptInit->atPerson[iIndex], sizeof(TPerson));
            ptSTRes->iNDSLNum++;
        }
    }

    return S_OK;
}

/* Compose functions */
SCODE Compose_SearchResponse(TSearchResponse *ptRes, char *pcOutput, int iBufferSize)
{
    int         iResult = 0, iIndex = 0;
    TPerson     *ptPerson;

printf("%s:%d \n", __func__, __LINE__);
    for (iIndex = 0; iIndex < ptRes->iNDSLNum; iIndex++)
    {
        ptPerson = &ptRes->atPerson[iIndex];

        iResult += snprintf(pcOutput + iResult, iBufferSize - iResult - 1, "<xml>");
        iResult += snprintf(pcOutput + iResult, iBufferSize - iResult - 1, "<%s id=%d>", "NDSL", iIndex);

        iResult += snprintf(pcOutput + iResult, iBufferSize - iResult - 1, "<Name>%s %s</Name>",
                            ptPerson->tName.acFirstName, ptPerson->tName.acLastName);
        iResult += snprintf(pcOutput + iResult, iBufferSize - iResult - 1, "<Age>%d</Age>", ptPerson->iAge);

        iResult += snprintf(pcOutput + iResult, iBufferSize - iResult - 1, "<JobTitile Retired=%d>", (int)ptPerson->bRetired);
        iResult += snprintf(pcOutput + iResult, iBufferSize - iResult - 1, "<Name>%s</Name>", ptPerson->tTitle.acName);
        iResult += snprintf(pcOutput + iResult, iBufferSize - iResult - 1, "<Seniority>%d</Seniority>", ptPerson->tTitle.iSeniority);
        iResult += snprintf(pcOutput + iResult, iBufferSize - iResult - 1, "</JobTitile>");

        iResult += snprintf(pcOutput + iResult, iBufferSize - iResult - 1, "<Company>%s</Company>", ptPerson->tCompany.acName);

        iResult += snprintf(pcOutput + iResult, iBufferSize - iResult - 1, "</%s>","NDSL");
        iResult += snprintf(pcOutput + iResult, iBufferSize - iResult - 1, "</xml>");
    }

printf("%s:%d \n", __func__, __LINE__);
    return S_OK;
}

SCODE Compose_SearchFault(char *pcOutput, int iBufferSize)
{

    return S_OK;
}
