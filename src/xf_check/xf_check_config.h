/**
 * @file xf_check_config.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-06-28
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_CHECK_CONFIG_H__
#define __XF_CHECK_CONFIG_H__

/* ==================== [Includes] ========================================== */

#include "../xf_utils_internal_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/**
 * @brief XF_ERROR_CHECK 的结果。如果不对接则为无限死循环
 * 
 */
#ifndef XF_CHECK_ERROR_HANDLER
#   define XF_CHECK_ERROR_HANDLER while(1);
#endif

/**
 * @brief 是否使能 check 系列的检查
 * 
 */
#if !defined(XF_CHECK_ENABLE) || (XF_CHECK_ENABLE)
#define XF_CHECK_IS_ENABLE          (1)
#else
#define XF_CHECK_IS_ENABLE          (0)
#endif

/**
 * @brief 是否使能 XF_ERROR_CHECK 检查
 * 
 */
#if !defined(XF_ASSERT_ENABLE) || (XF_ASSERT_ENABLE)
#define XF_ASSERT_IS_ENABLE          (1)
#else
#define XF_ASSERT_IS_ENABLE          (0)
#endif

/**
 * @brief 
 * 
 */
#if !defined(XF_ERROR_CHECK_ENABLE) || (XF_ERROR_CHECK_ENABLE)
#define XF_ERROR_CHECK_IS_ENABLE          (1)
#else
#define XF_ERROR_CHECK_IS_ENABLE          (0)
#endif

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_CHECK_CONFIG_H__

