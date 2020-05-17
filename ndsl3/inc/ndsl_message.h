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

#ifndef __NDSL_MESSAGE_H__
#define __NDSL_MESSAGE_H__

typedef struct {

    /* Config file path */
    char        *pcConfFile;
    /* Request info handle */
    HANDLE      hSearchInfo;
    /* Initilizer handle */
    HANDLE      hInitilization;
    /* Output */
    char        acSendBuffer[MAX_SENDBUFFER_SIZE];
} TMessageHandler;


#endif // __NDSL_MESSAGE_H__
