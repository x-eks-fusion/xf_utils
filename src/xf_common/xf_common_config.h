/**
 * @file xf_common_config_internal.h
 * @author catcatBlue (catcatblue@qq.com)
 * @brief 预定义.
 * xf_attr.h 等头文件通过包含本文件减少对其余外部文件的直接依赖. 如: `xfconfig.h`.
 * @version 1.0
 * @date 2024-06-19
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_COMMON_CONFIG_H__
#define __XF_COMMON_CONFIG_H__

/* ==================== [Includes] ========================================== */

#include "../xf_utils_internal_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/**
 * @brief 是否使能错误码值到字符串的查找表(`XF_OK`->"XF_OK").
 */
#if !defined(XF_COMMON_ERR_TO_NAME_LOOKUP_DISABLE) || (XF_COMMON_ERR_TO_NAME_LOOKUP_DISABLE)
#   define XF_COMMON_ERR_TO_NAME_LOOKUP_IS_ENABLE (0)
#else
#   define XF_COMMON_ERR_TO_NAME_LOOKUP_IS_ENABLE (1)
#endif

/**
 * @brief 是否使用 xf_attr中的宏
 *
 */
#if !defined(XF_ATTRIBUTE_ENABLE) || (XF_ATTRIBUTE_ENABLE)
#   define XF_ATTRIBUTE_IS_ENABLE (1)
#else
#   define XF_ATTRIBUTE_IS_ENABLE (0)
#endif

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* __XF_COMMON_CONFIG_H__ */
