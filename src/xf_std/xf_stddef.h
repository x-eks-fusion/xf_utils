/**
 * @file xf_stddef.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief
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


#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

#if (XF_STDDEF_IS_ENABLE == 0)

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef long     int                    ptrdiff_t;      /*!< 指针比较大小类型 */

typedef long unsigned int size_t;


/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // XF_STDDEF_IS_ENABLE

#endif // __XF_STDDEF_H__
