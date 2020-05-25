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

#ifndef __NDSL_DEBUG_H__
#define __NDSL_DEBUG_H__

#define CLEAR           "\033[m"
#define RED             "\033[0;32;31m"
#define LIGHT_RED       "\033[1;31m"
#define GREEN           "\033[0;32;32m"
#define LIGHT_GREEN     "\033[1;32m"
#define BLUE            "\033[0;32;34m"
#define LIGHT_BLUE      "\033[1;34m"
#define DARY_GRAY       "\033[1;30m"
#define CYAN            "\033[0;36m"
#define LIGHT_CYAN      "\033[1;36m"
#define PURPLE          "\033[0;35m"
#define LIGHT_PURPLE    "\033[1;35m"
#define BROWN           "\033[0;33m"
#define YELLOW          "\033[1;33m"
#define LIGHT_GRAY      "\033[0;37m"
#define WHITE           "\033[1;37m"

#define TRACE(file, line)                               printf(LIGHT_GRAY"[TRACE][%s][%d]\n"CLEAR, file, line)
#define ERROR(fmt, args...)                             printf(RED"[ERROR] "fmt""CLEAR, ##args)
#define WARN(fmt, args...)                              printf(YELLOW"[WARNING] "fmt""CLEAR, ##args)
#define INFO(fmt, args...)                              printf(LIGHT_CYAN"[INFO] "fmt""CLEAR, ##args)
#define DBPRINT(fmt, args...)                           printf(BLUE"[DEBUG] "fmt""CLEAR, ##args)
#define INITIAL(fmt, args...)                           printf(LIGHT_GREEN"[INITIAL] "fmt""CLEAR, ##args)
#define USERDEF1(fmt, args...)                          printf(PURPLE"[USERDEF1] "fmt""CLEAR, ##args)
#define USERDEF2(fmt, args...)                          printf(PURPLE"[USERDEF2] "fmt""CLEAR, ##args)
#define USERDEF3(fmt, args...)                          printf(LIGHT_RED"[USERDEF3] "fmt""CLEAR, ##args)

#endif // __NDSL_DEBUG_H__
