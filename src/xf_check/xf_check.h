/**
 * @file xf_check.h
 * @author catcatBlue (catcatblue@qq.com)
 * @brief 运行时检查宏。
 * @version 1.0
 * @date 2024-06-25
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_CHECK_H__
#define __XF_CHECK_H__

/* ==================== [Includes] ========================================== */

#include "../xf_common/xf_common.h"
#include "../xf_utils_log/xf_utils_log.h"
#include "xf_check_config.h"

/**
 * @ingroup group_xf_utils_user
 * @defgroup group_xf_utils_user_check xf_check
 * @brief 运行时检查宏。
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/**
 * @brief XF_RETURN_VOID、XF_ACTION_NO 是在 XF_CHECK 无需返回的情况使用：
 *
 * @code{c}
 * XF_CHECK(timer == NULL , XF_RETURN_VOID, TAG, "timer == NULL");
 * XF_CHECK_ACTION_RETURN(port_in == NULL, port_out, XF_ACTION_NO);
 * @endcode
 *
 * @name XF_CHECK_NO_ACTION
 * @{
 */
#define XF_RETURN_VOID
#define XF_ACTION_NO
/**
 * End of XF_CHECK_NO_ACTION
 * @}
 */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#if XF_CHECK_IS_ENABLE || XF_ASSERT_IS_ENABLE
/**
 * @brief 检查条件(condition)，成立则执行(action)，并 return (retval).
 *
 * @param condition 判断条件。
 * @param retval 条件成立时的返回值。
 * @param action 条件成立时的执行的动作。
 * @return retval 等同于参数 `retval`，可以为空。
 */
#   define XF_CHECK_ACTION_RETURN(condition, retval, action) \
        do { \
            if (condition) { \
                do {action} while (0); \
                return retval; \
            } \
        } while (0)
#else
#   define XF_CHECK_ACTION_RETURN(condition, retval, action)
#endif

#if XF_CHECK_IS_ENABLE || XF_ASSERT_IS_ENABLE
/**
 * @brief 检查条件(condition)，成立则执行(action)，并跳转到(label).
 *
 * @param condition 判断条件。
 * @param label 条件成立时，跳转到的标签。
 * @param action 条件成立时的执行的动作。
 */
#   define XF_CHECK_ACTION_GOTO(condition, label, action) \
        do { \
            if (condition) { \
                do {action} while (0); \
                goto label; \
            } \
        } while (0)
#else
#   define XF_CHECK_ACTION_GOTO(condition, retval, action)
#endif

#if XF_CHECK_IS_ENABLE
/**
 * @brief xfusion 检查宏（条件 @b 成立 时则输出日志后返回）。
 *
 * - XF_CHECK*: 条件 @b 成立 时执行。
 *
 * @param condition 判断条件。
 * @param retval 条件 @b 成立 时的返回值。
 * @param tag 日志标签。
 * @param format 用户格式化字符串。
 * @param ... 可变参数。
 * @return retval 等同于参数 `retval`，可以为空。
 */
#   define XF_CHECK(condition, retval, tag, format, ...) \
        XF_CHECK_ACTION_RETURN( \
            !!(condition), retval, \
            XF_LOGE((tag), format, ##__VA_ARGS__); \
        )

/**
 * @brief xfusion 检查宏（条件 @b 成立 时则输出日志后跳转）。
 *
 * @param condition 判断条件。
 * @param label 条件 @b 成立 时，跳转到的标签。
 * @param tag 日志标签。
 * @param format 用户格式化字符串。
 * @param ... 可变参数。
 */
#   define XF_CHECK_GOTO(condition, label, tag, format, ...) \
        XF_CHECK_ACTION_GOTO( \
            !!(condition), label, \
            XF_LOGE((tag), format, ##__VA_ARGS__); \
        )
#else
#   define XF_CHECK(condition, retval, tag, format, ...)       do { (void)tag; } while (0)
#   define XF_CHECK_GOTO(condition, label, tag, format, ...)   do { (void)tag; } while (0)
#endif

#if XF_ASSERT_IS_ENABLE
/**
 * @brief xfusion 断言宏（条件 @b 不成立 时则输出日志后返回）。
 *
 * - XF_ASSERT*: 条件 @b 不成立 时执行。
 *
 * @param condition 判断条件。
 * @param retval 条件 @b 不成立 时的返回值。
 * @param tag 日志标签。
 * @param format 用户格式化字符串。
 * @param ... 可变参数。
 * @return retval 等同于参数 `retval`，可以为空。
 */
#   define XF_ASSERT(condition, retval, tag, format, ...) \
        XF_CHECK_ACTION_RETURN( \
            !(condition), retval, \
            XF_LOGE((tag), format, ##__VA_ARGS__); \
        )

/**
 * @brief xfusion 断言宏（条件 @b 不成立 时则输出日志后跳转）。
 *
 * @param condition 判断条件。
 * @param label 条件 @b 不成立 时，跳转到的标签。
 * @param tag 日志标签。
 * @param format 用户格式化字符串。
 * @param ... 可变参数。
 */
#   define XF_ASSERT_GOTO(condition, label, tag, format, ...) \
        XF_CHECK_ACTION_GOTO( \
            !(condition), label, \
            XF_LOGE((tag), format, ##__VA_ARGS__); \
        )
#else
#   define XF_ASSERT(condition, retval, tag, format, ...)      do { (void)tag; } while (0)
#   define XF_ASSERT_GOTO(condition, label, tag, format, ...)  do { (void)tag; } while (0)
#endif

#if XF_ERROR_CHECK_IS_ENABLE
/**
 * @brief xfusion 错误检查宏（表达式 @b 不等于 `XF_OK` 时则调用 `XF_CHECK_ERROR_HANDLER`）。
 *
 * @param expression 返回值类型为 `xf_err_t` 的表达式。\n
 *                   如果 expression 不为 `XF_OK`, 则调用 `XF_CHECK_ERROR_HANDLER`.
 */
#   define XF_ERROR_CHECK(expression) \
        do { \
            xf_err_t __err = (expression); \
            if (unlikely((__err) != XF_OK)) { \
                XF_LOGE("xf_check", "An error occurred: " XSTR(expression != XF_OK)); \
                XF_CHECK_ERROR_HANDLER \
            } \
        } while (0)
#else
#   define XF_ERROR_CHECK(expression)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

/**
 * End of group_xf_utils_user_check
 * @}
 */

#endif /* __XF_CHECK_H__ */
