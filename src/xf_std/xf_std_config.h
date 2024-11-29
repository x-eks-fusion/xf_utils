/**
 * @file xf_std_config.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-06-28
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_STD_CONFIG_H__
#define __XF_STD_CONFIG_H__

/* ==================== [Includes] ========================================== */

#include "../xf_utils_internal_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

#if !defined(XF_STDDEF_ENABLE) || (XF_STDDEF_ENABLE)
#   define XF_STDDEF_IS_ENABLE     (1)
#else
#   define XF_STDDEF_IS_ENABLE     (0)
#endif

#if !defined(XF_STDINT_ENABLE) || (XF_STDINT_ENABLE)
#   define XF_STDINT_IS_ENABLE     (1)
#else
#   define XF_STDDEF_IS_ENABLE     (0)
#endif

#if !defined(XF_STDBOOL_ENABLE) || (XF_STDBOOL_ENABLE)
#   define XF_STDBOOL_IS_ENABLE     (1)
#else
#   define XF_STDBOOL_IS_ENABLE     (0)
#endif

/**
 * @name xf_stdlib_configuration
 * xf_stdlib 配置.
 * @{
 */

#if !defined(XF_STDLIB_ENABLE) || (XF_STDLIB_ENABLE)
#   define XF_STDLIB_IS_ENABLE     (1)
#else
#   define XF_STDLIB_IS_ENABLE     (0)
#endif

#ifndef xf_user_malloc
#   define xf_user_malloc(x) malloc(x)
#endif

#ifndef xf_user_free
#   define xf_user_free(x) free(x)
#endif

/**
 * End of xf_stdlib_configuration
 * @}
 */

/**
 * @name xf_string_configuration
 * xf_string 配置.
 * @{
 */

#if !defined(XF_STRING_ENABLE) || (XF_STRING_ENABLE)
#   define XF_STRING_IS_ENABLE     (1)
#else
#   define XF_STRING_IS_ENABLE     (0)
#endif

#ifndef xf_user_memcpy
#   define xf_user_memcpy(dest, src, n)   memcpy(dest, src, n)
#endif

#ifndef xf_user_memcmp
#   define xf_user_memcmp(dest, src, n)   memcmp(dest, src, n)
#endif

#ifndef xf_user_memset
#   define xf_user_memset(ptr, value, size) memset((ptr), (value), (size))
#endif

/**
 * End of xf_string_configuration
 * @}
 */

/**
 * @name xf_stdio_configuration
 * xf_stdio 配置.
 * @{
 */

#if !defined(XF_STDIO_ENABLE) || (XF_STDIO_ENABLE)
#   define XF_STDIO_IS_ENABLE     (1)
#else
#   define XF_STDIO_IS_ENABLE     (0)
#endif

#ifndef xf_user_sprintf
#   define xf_user_sprintf(dest, format, ...)  sprintf(dest, format, ##__VA_ARGS__)
#endif

#ifndef xf_user_snprintf
#   define xf_user_snprintf(dest, size, format, ...)    snprintf(dest, size, format, ##__VA_ARGS__)
#endif

#ifndef xf_user_vsprintf
#   define xf_user_vsprintf(dest, format, ap)           vsprintf(dest, format, ap)
#endif

#ifndef xf_user_vsnprintf
#   define xf_user_vsnprintf(dest, size, format, ap)    vsnprintf(dest, size, format, ap)
#endif

#ifndef xf_user_sscanf
#   define xf_user_sscanf(source, format, ...)          sscanf(source, format, ##__VA_ARGS__)
#endif

/**
 * End of xf_stdio_configuration
 * @}
 */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_STD_CONFIG_H__
