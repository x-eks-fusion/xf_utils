/**
 * @file xf_stdlib.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 * 
 */

#ifndef __XF_STDLIB_H__
#define __XF_STDLIB_H__

/* ==================== [Includes] ========================================== */

#include "xf_std_config.h"

#if XF_STDLIB_IS_ENABLE
#   include <stdlib.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

#define xf_malloc(x)                   xf_user_malloc(x)
#define xf_free(x)                     xf_user_free(x)

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_STDLIB_H__
