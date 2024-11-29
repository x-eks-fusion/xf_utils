/**
 * @file xf_utils_log.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief xf_utils 的 log 封装。
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_UTILS_LOG_H__
#define __XF_UTILS_LOG_H__

/* ==================== [Includes] ========================================== */

#include "xf_utils_log_config.h"
#include "../xf_common/xf_common.h"

/**
 * @cond XFAPI_USER
 * @ingroup group_xf_utils
 * @defgroup group_xf_utils_log xf_utils_log
 * @brief 日志宏的封装。
 * @endcond
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

#define XF_LOG_NONE             (0)
#define XF_LOG_USER             (1)
#define XF_LOG_ERROR            (2)
#define XF_LOG_WARN             (3)
#define XF_LOG_INFO             (4)
#define XF_LOG_DEBUG            (5)
#define XF_LOG_VERBOSE          (6)

#if XF_LOG_DUMP_IS_ENABLE

#define XF_DUMP_HEAD_BIT        (0) /*!< flags_mask 中表头的标志位 */
#define XF_DUMP_ASCII_BIT       (1) /*!< flags_mask 中 ASCII 的标志位 */
#define XF_DUMP_ESCAPE_BIT      (2) /*!< flags_mask 中带有转义字符的标志位 */
#define XF_DUMP_TAIL_BIT        (3) /*!< flags_mask 中表尾的标志位 */

#define XF_DUMP_BIT(nr)         BIT(nr)

#define XF_DUMP_TABLE           (XF_DUMP_BIT(XF_DUMP_HEAD_BIT) | XF_DUMP_BIT(XF_DUMP_TAIL_BIT))

/* 只输出 16 进制格式数据 */
#define XF_DUMP_FLAG_HEX_ONLY           (XF_DUMP_TABLE)
/* 输出 16 进制格式数据并带有 ASCII 字符 */
#define XF_DUMP_FLAG_HEX_ASCII          (XF_DUMP_BIT(XF_DUMP_ASCII_BIT) | XF_DUMP_TABLE)
/* 输出 16 进制格式数据、 ASCII 字符、转义字符，其余输出 16 进制原始值 */
#define XF_DUMP_FLAG_HEX_ASCII_ESCAPE   (XF_DUMP_FLAG_HEX_ASCII | XF_DUMP_BIT(XF_DUMP_ESCAPE_BIT))

#endif /* XF_LOG_DUMP_IS_ENABLE */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

#if XF_LOG_DUMP_IS_ENABLE
/**
 * @brief 输出内存信息。
 *
 * @param addr 内存地址。
 * @param size 待输出的内存字节长度。
 * @param flags_mask 格式掩码，见 XF_DUMP_FLAG_*。
 * @return xf_err_t
 *      - XF_ERR_INVALID_ARG            参数错误
 *      - XF_OK                         成功
 */
xf_err_t xf_dump_mem(void *addr, size_t size, uint8_t flags_mask);
#endif

/* ==================== [Macros] ============================================ */

#if XF_LOG_LEVEL >= XF_LOG_USER
/**
 * @brief 用户等级日志。始终显示文件名、行号等信息。
 *
 * @param tag 日志标签。
 * @param format 日志格式化字符串。
 * @param ... 可变参数。
 * @return size_t 本次日志字节数。
 */
#   define XF_LOGU(tag, format, ...)  xf_log_level(XF_LOG_USER,     tag, format, ##__VA_ARGS__)
#else
#   define XF_LOGU(tag, format, ...)  (void)(tag)
#endif

#if XF_LOG_LEVEL >= XF_LOG_ERROR
/**
 * @brief 错误等级日志。始终显示文件名、行号等信息。
 *
 * @param tag 日志标签。
 * @param format 日志格式化字符串。
 * @param ... 可变参数。
 * @return size_t 本次日志字节数。
 */
#   define XF_LOGE(tag, format, ...)  xf_log_level(XF_LOG_ERROR,    tag, format, ##__VA_ARGS__)
#else
#   define XF_LOGE(tag, format, ...)  (void)(tag)
#endif

#if XF_LOG_LEVEL >= XF_LOG_WARN
/**
 * @brief 警告等级日志。
 *
 * @param tag 日志标签。
 * @param format 日志格式化字符串。
 * @param ... 可变参数。
 * @return size_t 本次日志字节数。
 */
#   define XF_LOGW(tag, format, ...)  xf_log_level(XF_LOG_WARN,     tag, format, ##__VA_ARGS__)
#else
#   define XF_LOGW(tag, format, ...)  (void)(tag)
#endif

#if XF_LOG_LEVEL >= XF_LOG_INFO
/**
 * @brief 信息等级日志。
 *
 * @param tag 日志标签。
 * @param format 日志格式化字符串。
 * @param ... 可变参数。
 * @return size_t 本次日志字节数。
 */
#   define XF_LOGI(tag, format, ...)  xf_log_level(XF_LOG_INFO,     tag, format, ##__VA_ARGS__)
#else
#   define XF_LOGI(tag, format, ...)  (void)(tag)
#endif

#if XF_LOG_LEVEL >= XF_LOG_DEBUG
/**
 * @brief 调试等级日志。
 *
 * @param tag 日志标签。
 * @param format 日志格式化字符串。
 * @param ... 可变参数。
 * @return size_t 本次日志字节数。
 */
#   define XF_LOGD(tag, format, ...)  xf_log_level(XF_LOG_DEBUG,    tag, format, ##__VA_ARGS__)
#else
#   define XF_LOGD(tag, format, ...)  (void)(tag)
#endif

#if XF_LOG_LEVEL >= XF_LOG_VERBOSE
/**
 * @brief 冗余等级日志。
 *
 * @param tag 日志标签。
 * @param format 日志格式化字符串。
 * @param ... 可变参数。
 * @return size_t 本次日志字节数。
 */
#   define XF_LOGV(tag, format, ...)  xf_log_level(XF_LOG_VERBOSE,  tag, format, ##__VA_ARGS__)
#else
#   define XF_LOGV(tag, format, ...)  (void)(tag)
#endif

#if XF_LOG_DUMP_IS_ENABLE
/**
 * @brief 以十六进制输出 buffer 的内容。
 *
 * @param buffer 待输出的 buffer。
 * @param buffer_len buffer 的长度。
 * @return xf_err_t 是否输出成功。
 */
#define XF_LOG_BUFFER_HEX(buffer, buffer_len) \
    xf_dump_mem(buffer, buffer_len, XF_DUMP_FLAG_HEX_ONLY)

/**
 * @brief 以十六进制输出 buffer 的内容，同时输出可见的 ascii 码。
 *
 * @param buffer 待输出的 buffer。
 * @param buffer_len buffer 的长度。
 * @return xf_err_t 是否输出成功。
 */
#define XF_LOG_BUFFER_HEXDUMP(buffer, buffer_len) \
    xf_dump_mem(buffer, buffer_len, XF_DUMP_FLAG_HEX_ASCII)

/**
 * @brief 以十六进制输出 buffer 的内容，同时输出可见的 ascii 码，以及转义字符。
 *
 * @param buffer 待输出的 buffer。
 * @param buffer_len buffer 的长度。
 * @return xf_err_t 是否输出成功。
 */
#define XF_LOG_BUFFER_HEXDUMP_ESCAPE(buffer, buffer_len) \
    xf_dump_mem(buffer, buffer_len, XF_DUMP_FLAG_HEX_ASCII_ESCAPE)

#else

#define XF_LOG_BUFFER_HEX(buffer, buffer_len)
#define XF_LOG_BUFFER_HEXDUMP(buffer, buffer_len)
#define XF_LOG_BUFFER_HEXDUMP_ESCAPE(buffer, buffer_len)

#endif // XF_LOG_DUMP_IS_ENABLE

#ifdef __cplusplus
} /* extern "C" */
#endif

/**
 * End of group_xf_utils_log
 * @}
 */

#endif // __XF_UTILS_LOG_H__
