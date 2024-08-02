/**
 * @file xf_common.h
 * @author catcatBlue (catcatblue@qq.com)
 * @brief 通用头文件.
 * @version 1.0
 * @date 2024-06-18
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_COMMON_H__
#define __XF_COMMON_H__

/* ==================== [Includes] ========================================== */

#include "xf_common_config.h"

#include "xf_predef.h"
#include "xf_version.h"
#include "xf_attr.h"
#include "xf_err.h"
#include "xf_bit_defs.h"
#include "xf_list.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

#if !(defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L))
#error "XF 需要 C99 或以上版本的编译器支持！"
#endif

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* __XF_COMMON_H__ */
