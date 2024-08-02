/**
 * @file xf_attr.h
 * @author catcatBlue (catcatblue@qq.com)
 * @brief 编译属性.
 * @version 1.0
 * @date 2024-06-18
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_ATTR_H__
#define __XF_ATTR_H__

/* ==================== [Includes] ========================================== */

#include "xf_common_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/**
 * @see https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html
 * @note 此部分是基于gnu的拓展属性，使用时务必考虑如果编译器无法支持gnu特性情况
 */

#if XF_ATTRIBUTE_IS_ENABLE

/**
 * @brief 弱声明符号。
 * 被 __weak 修饰的符号（变量或函数）
 * 可以被 **没有** 用 __weak 修饰的符号覆盖或重定义。
 */

#if defined(__GNUC__)
#   if !defined(__weak)
#       define __weak __attribute__((weak))
#   endif
#else
#   define __weak
#endif


/**
 * @brief 编辑器不会优化掉被 __used 修饰的符号，
 * 即使在代码中即使没有使用到该符号。
 */
#if defined(__GNUC__)
#   if !defined(__used)
#       define __used __attribute__((used))
#   endif
#else
#   define __used
#endif

/**
 * @brief 指定变量或结构体的对齐方式（单位字节）。
 */
#if defined(__GNUC__)
#   if !defined(__aligned)
#       define __aligned(x) __attribute__((aligned(x)))
#   endif
#else
#   define __aligned(x)
#   warning "__aligned has no effect !"
#endif


/**
 * @brief 指定函数或变量的段位置，如 data 或 bss。
 *
 * @note section 属性并非在所有平台上都可用。
 */
#if defined(__GNUC__)
#   if !defined(__section)
#       define __section(x) __attribute__((section(x)))
#   endif
#else
#   define __section(x)
#endif

/**
 * @brief 分支预测，x 为真的可能性更大。
 */
#if defined(__GNUC__)
#   if !defined(likely)
#       define likely(x) __builtin_expect(!!(x), 1)
#   endif
#else
#   define likely(x) (x)
#endif

/**
 * @brief 分支预测，x 为假的可能性更大。
 */
#if defined(__GNUC__)
#   if !defined(unlikely)
#       define unlikely(x) __builtin_expect(!!(x), 0)
#   endif
#else
#   define unlikely(x) (x)
#endif

/**
 * @brief 取消结构在编译过程中的优化对齐，
 * 按照实际占用字节数进行对齐（一般不使用）。
 */
#if defined(__GNUC__)
#   if !defined(__packed)
#       define __packed __attribute__((packed))
#   endif
#else
#   define __packed
#   warning "__packed has no effect !"
#endif

#endif // XF_ATTRIBUTE_IS_ENABLE

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* __XF_ATTR_H__ */
