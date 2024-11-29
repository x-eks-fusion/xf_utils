/**
 * @file xf_stddef.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief xf_utils 对标准库 stddef.h 的封装。
 * @version 0.1
 * @date 2024-07-09
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_STDDEF_H__
#define __XF_STDDEF_H__

/* ==================== [Includes] ========================================== */

#include "xf_std_config.h"

#if XF_STDDEF_IS_ENABLE
#include <stddef.h>
#endif

/**
 * @ingroup group_xf_utils_user_std
 * @defgroup group_xf_utils_user_std_stddef xf_stddef
 * @brief 对标准库 stddef.h 的封装。
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#if (XF_STDDEF_IS_ENABLE == 0)

/* ==================== [Defines] =========================================== */

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef long     int                    ptrdiff_t;      /*!< 指针比较大小类型 */

typedef long unsigned int               size_t;

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#endif // XF_STDDEF_IS_ENABLE

#ifdef __cplusplus
} /* extern "C" */
#endif

/**
 * End of group_xf_utils_user_std_stddef
 * @}
 */

#endif // __XF_STDDEF_H__
