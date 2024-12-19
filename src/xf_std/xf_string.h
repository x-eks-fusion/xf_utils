/**
 * @file xf_string.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief xf_utils 对标准库 string.h 的封装。
 * @version 0.1
 * @date 2024-06-28
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_STRING_H__
#define __XF_STRING_H__

/* ==================== [Includes] ========================================== */

#include "xf_std_config.h"

#if XF_STRING_IS_ENABLE
#   include <string.h>
#endif

/**
 * @cond XFAPI_USER
 * @ingroup group_xf_utils_std
 * @defgroup group_xf_utils_std_string xf_string
 * @brief 对标准库 string.h 的封装。
 * @endcond
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

#define xf_memset(ptr, value, size)    xf_user_memset((void*)(ptr), (value), (size))
#define xf_bzero(ptr, size)            xf_memset((void*)(ptr), 0, (size))
#define xf_memcpy(dest, src, n)        xf_user_memcpy((dest), (src), (n))
#define xf_memcmp(dest, src, n)        xf_user_memcmp((dest), (src), (n))
#define xf_strcmp(dest, src)           xf_user_strcmp((dest), (src))

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

/**
 * End of group_xf_utils_std_string
 * @}
 */

#endif // __XF_STRING_H__
