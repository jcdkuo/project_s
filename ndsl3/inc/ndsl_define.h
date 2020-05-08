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

#ifndef __PERSON_DEFINE_H__
#define __PERSON_DEFINE_H__

typedef unsigned int SCODE;
#define S_OK    (SCODE) (0)
#define S_FAIL  (SCODE) (-1)

#define TRUE    1
#define FALSE   0

#define MAX_STRING_SIZE 32
#define MAX_PERSON_NUM  10

#define RETURN_SOK_IF(expr) if (expr) return S_OK;
#define RETURN_SOK_IF_NOT(expr) if (!expr) return S_OK;

#define RETURN_SFAIL_IF_NULL(expr) \
    if (expr == NULL){ \
    return S_FAIL;  \
}

#define RETURN_SFAIL_IF(expr) \
    if (expr){ \
    printf("[%s] failed %s:%d\n", __func__, __FILE__, __LINE__); \
    return S_FAIL;  \
}

#define RETURN_SFAIL_IF_NOT(expr) \
    if (!(expr)){ \
    printf("[%s] failed %s:%d\n", __func__, __FILE__, __LINE__); \
    return S_FAIL;  \
}

#define ERROR_INITIALIZATION_FAILED (-1)
#define ERROR_SHOW_MESSAGE_FAILED   (-2)

#endif //__PERSON_DEFINE_H__

