/**
 * @file xf_log_config.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-06-28
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_UTILS_LOG_CONFIG_H__
#define __XF_UTILS_LOG_CONFIG_H__

/* ==================== [Includes] ========================================== */

#include "../xf_utils_internal_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

#if !defined(XF_STDIO_ENABLE) || (XF_STDIO_ENABLE)
#   define XF_STDIO_IS_ENABLE (1)
#else
#   define XF_STDIO_IS_ENABLE (0)
#endif

#if XF_STDIO_IS_ENABLE
#   include <stdio.h>
#endif

#if !defined(XF_LOG_DUMP_ENABLE) || (XF_LOG_DUMP_ENABLE)
#   define XF_LOG_DUMP_IS_ENABLE (1)
#else
#   define XF_LOG_DUMP_IS_ENABLE (0)
#endif

#ifndef XF_LOG_LEVEL
#   define XF_LOG_LEVEL XF_LOG_INFO
#endif

#if (XF_LOG_LEVEL < 0) || (XF_LOG_LEVEL > 6)
#   error "log level must between 0 to 6"
#endif

// log 对接打印函数， 简化版对接。
#if !defined(xf_log_printf)
#   define xf_log_printf(format, ...) printf(format, ##__VA_ARGS__)
#endif

// log 对接打印二进制的后端，默认使用xf_log_printf打印
#if !defined(xf_log_dump_printf)
#   define xf_log_dump_printf(format, ...) xf_log_printf(format, ##__VA_ARGS__)
#endif

// log对接, 如果不独立对接xf_log_level，则会调用xf_log_printf实现
#if !defined(xf_log_level) && defined(xf_log_printf)
#define xf_log_level(level, tag, format, ...) xf_log_printf("%c-%s[:%d(%s)]: "format"\n", #level[7], tag, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#endif

/* log优先使用xf_log_level作为自己的对接方式，如果没有则使用xf_log_printf*/

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_UTILS_LOG_CONFIG_H__
