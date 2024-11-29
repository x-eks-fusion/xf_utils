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

/**
 * @cond XFAPI_USER
 * @ingroup group_xf_utils_common
 * @defgroup group_xf_utils_common_attribute xf_attribute
 * @brief 编译器属性。用于屏蔽不同编译器属性的区别。
 * @endcond
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/**
 * @see https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html
 * @note 此部分是基于gnu的拓展属性，使用时务必考虑如果编译器无法支持gnu特性情况
 */

#if XF_ATTRIBUTE_IS_ENABLE

#if defined(__GNUC__)
#   if !defined(__weak)
/**
 * @brief 弱声明符号。
 * 被 __weak 修饰的符号（变量或函数）
 * 可以被 **没有** 用 __weak 修饰的符号覆盖或重定义。
 */
#       define __weak __attribute__((weak))
#   endif
#else
#   define __weak
#endif

#if defined(__GNUC__)
#   if !defined(__used)
/**
 * @brief 编辑器不会优化掉被 __used 修饰的符号，
 * 即使在代码中即使没有使用到该符号。
 */
#       define __used __attribute__((used))
#   endif
#else
#   define __used
#endif

#if defined(__GNUC__)
#   if !defined(__aligned)
/**
 * @brief 指定变量或结构体的对齐方式（单位字节）。
 *
 * @param x 对齐到的字节数。
 */
#       define __aligned(x) __attribute__((aligned(x)))
#   endif
#else
#   define __aligned(x)
#   warning "__aligned has no effect !"
#endif

#if defined(__GNUC__)
#   if !defined(__section)
/**
 * @brief 指定函数或变量的段位置，如 data 或 bss。
 *
 * @param x 目标段名。
 */
#       define __section(x) __attribute__((section(x)))
#   endif
#else
#   define __section(x)
#endif

#if defined(__GNUC__)
#   if !defined(likely)
/**
 * @brief 分支预测，优化条件为 @b 真 的可能性更大的情况。
 *
 * @param x 判断语句，且真的可能性更大。
 */
#       define likely(x) __builtin_expect(!!(x), 1)
#   endif
#else
#   define likely(x) (x)
#endif

#if defined(__GNUC__)
#   if !defined(unlikely)
/**
 * @brief 分支预测，优化条件为 @b 假 的可能性更大的情况。
 *
 * @param x 判断语句，且假的可能性更大。
 */
#       define unlikely(x) __builtin_expect(!!(x), 0)
#   endif
#else
#   define unlikely(x) (x)
#endif

#if defined(__GNUC__)
#   if !defined(__packed)
/**
 * @brief 取消结构体在编译过程中的优化对齐，按照实际占用字节数进行对齐。
 */
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

/**
 * End of group_xf_utils_common_attribute
 * @}
 */

#endif /* __XF_ATTR_H__ */
