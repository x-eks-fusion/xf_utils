/**
 * @file xf_stdlib.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief xf_utils 对标准库 stdlib.h 的封装。
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

/**
 * @cond XFAPI_USER
 * @ingroup group_xf_utils_std
 * @defgroup group_xf_utils_std_stdlib xf_stdlib
 * @brief 对标准库 stdlib.h 的封装。
 * @endcond
 * @{
 */

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

/**
 * End of group_xf_utils_std_stdlib
 * @}
 */

#endif // __XF_STDLIB_H__
