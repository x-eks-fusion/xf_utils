/**
 * @file xf_predef.h
 * @author catcatBlue (catcatblue@qq.com)
 * @brief 预定义宏.
 * @version 1.0
 * @date 2024-06-19
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_PREDEF_H__
#define __XF_PREDEF_H__

/* ==================== [Includes] ========================================== */

#include "xf_common_config.h"

/**
 * @ingroup group_xf_utils_user_common
 * @defgroup group_xf_utils_user_common_predef xf_predef
 * @brief 预定义宏. 如 UNUSED, STR, xf_offsetof, xf_container_of.
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

#if !defined(__FILENAME__)
#if defined(__GNUC__)
/**
 * @brief 获取不含路径的文件名。
 */
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') \
                        ? (__builtin_strrchr(__FILE__, '/') + 1) \
                        : (__FILE__))
#else
#define __FILENAME__ __FILE__
#endif /* defined(__GNUC__) */
#endif /* !defined(__FILENAME__) */

/**
 * @brief 空引脚值。当引脚无需使用时填入。
 */
#ifndef NC
#define NC              (-1)
#endif

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifndef UNUSED
/**
 * @brief 未使用的变量通过 UNUSED 防止编译器警告。
 */
#define UNUSED(x)                       do { (void)(x); } while(0)
#endif

#ifndef CONCAT
/**
 * @brief 拼接。
 */
#define CONCAT(a, b)                    a##b
#endif

#ifndef CONCAT3
/**
 * @brief 拼接 3 个参数。
 */
#define CONCAT3(a, b, c)                a##b##c
#endif

#if !defined(XCONCAT)
/**
 * @brief 展开拼接。
 * 与 CONCAT 相比，此宏会先展开宏后拼接。
 */
#define XCONCAT(a, b)                   CONCAT(a, b)
#endif

#if !defined(XCONCAT3)
/**
 * @brief 展开拼接 3 个参数。
 * 与 CONCAT3 相比，此宏会先展开宏后拼接。
 */
#define XCONCAT3(a, b, c)               CONCAT3(a, b, c)
#endif

#ifndef STR
/**
 * @brief 字符串化。
 * 见：https://gcc.gnu.org/onlinedocs/gcc-3.4.3/cpp/Stringification.html
 */
#define STR(x)                          #x
#endif

#ifndef XSTR
/**
 * @brief 参数字符串化。
 * 见：https://gcc.gnu.org/onlinedocs/gcc-3.4.3/cpp/Stringification.html
 */
#define XSTR(x)                         STR(x)
#endif

#ifndef xf_offsetof
/**
 * @brief xf_offsetof - 返回结构成员相对于结构开头的字节偏移量。
 *
 * @param type 结构体的类型名。
 * @param member 结构中成员的名称。
 * @return size_t 结构成员相对于结构开头的字节偏移量。
 */
#define xf_offsetof(type, member) ((size_t)&((type *)0)->member)
#endif

#ifndef xf_container_of
/**
 * @brief xf_container_of - 通过结构体成员变量地址获取结构体的地址.
 *
 * @param ptr 指向成员的指针。
 * @param type 结构体类型。
 * @param member 结构中成员的名称。
 *
 * @return 结构体的地址。
 *
 * 示例如下：
 * @code{c}
 * typedef struct {
 *     int member1;
 *     char member2;
 *     float member3;
 * } struct_test_t;
 *
 * int main()
 * {
 *     struct_test_t stru = {
 *         .member1 = 0x12345678,
 *         .member2 = 0xAB,
 *         .member3 = -123.456f,
 *     };
 *     char *p_member2 = &stru.member2;
 *     struct_test_t *p_stru = xf_container_of(p_member2, struct_test_t, member2);
 *     if ((p_stru->member1 != (int)0x12345678)
 *             || (p_stru->member2 != (char)0xAB)
 *             || ((p_stru->member3 - (-123.456f)) > 1e-6f)) {
 *         printf("xf_container_of error!\n");
 *     } else {
 *         printf("xf_container_of ok!\n");
 *     }
 * }
 * @endcode
 */
#define xf_container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - xf_offsetof(type, member)))
#endif

#ifndef ARRAY_SIZE
/**
 * @brief ARRAY_SIZE - 获取数组 arr 中的元素数量。
 *
 * @param arr 待求的数组。(必须是数组，此处不进行判断)
 *
 * @return 数组元素个数。
 */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif

/**
 * End of group_xf_utils_user_common_predef
 * @}
 */

#endif /* __XF_PREDEF_H__ */
