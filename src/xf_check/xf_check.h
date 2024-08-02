/**
 * @file xf_check.h
 * @author catcatBlue (catcatblue@qq.com)
 * @brief
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
 */
#define XF_RETURN_VOID
#define XF_ACTION_NO

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#if XF_CHECK_IS_ENABLE || XF_ASSERT_IS_ENABLE
/**
 * @brief 检查条件(condition)，成立则执行(action)，并return (retval)
 */
#define XF_CHECK_ACTION_RETURN(condition, retval, action)   \
    do { \
        if (condition) { \
            do {action} while (0); \
            return retval; \
        } \
    } while (0)
#else
#define XF_CHECK_ACTION_RETURN(condition, retval, action)
#endif


#if XF_CHECK_IS_ENABLE || XF_ASSERT_IS_ENABLE
/**
 * @brief 检查条件(condition)，成立则执行(action)，并跳转到(label)
 */
#define XF_CHECK_ACTION_GOTO(condition, label, action) \
    do { \
        if (condition) { \
            do {action} while (0); \
            goto label; \
        } \
    } while (0)
#else
#define XF_CHECK_ACTION_GOTO(condition, retval, action)
#endif

/**
 * @brief 关于 XF_CHECK* 和 XF_ASSERT*
 *  - XF_CHECK*: 条件成立时执行。
 *  - XF_ASSERT*: 条件不成立时执行。
 */
#if XF_CHECK_IS_ENABLE
#define XF_CHECK(condition, retval, tag, format, ...) \
    XF_CHECK_ACTION_RETURN( \
        !!(condition), retval, \
        XF_LOGE((tag), format, ##__VA_ARGS__); \
    )

#define XF_CHECK_GOTO(condition, label, tag, format, ...) \
    XF_CHECK_ACTION_GOTO( \
        !!(condition), label, \
        XF_LOGE((tag), format, ##__VA_ARGS__); \
    )
#else
#define XF_CHECK(condition, retval, tag, format, ...)       (void)tag
#define XF_CHECK_GOTO(condition, label, tag, format, ...)   (void)tag
#endif

#if XF_ASSERT_IS_ENABLE
#define XF_ASSERT(condition, retval, tag, format, ...) \
    XF_CHECK_ACTION_RETURN( \
        !(condition), retval, \
        XF_LOGE((tag), format, ##__VA_ARGS__); \
    )


#define XF_ASSERT_GOTO(condition, label, tag, format, ...) \
    XF_CHECK_ACTION_GOTO( \
        !(condition), label, \
        XF_LOGE((tag), format, ##__VA_ARGS__); \
    )

#else
#define XF_ASSERT(condition, retval, tag, format, ...)      (void)tag
#define XF_ASSERT_GOTO(condition, label, tag, format, ...)  (void)tag
#endif

#if XF_ERROR_CHECK_IS_ENABLE
/**
 * @brief 检查错误.
 */
#define XF_ERROR_CHECK(expression) \
    do { \
        xf_err_t __err = (expression); \
        if (unlikely((__err) != XF_OK)) { \
            XF_LOGE("xf_check", "An error occurred: " XSTR(expression != XF_OK)); \
            XF_CHECK_ERROR_HANDLER \
        } \
    } while (0)
#else
#define XF_ERROR_CHECK(expression)
#endif

#ifdef __cplusplus
}
#endif

#endif /* __XF_CHECK_H__ */
