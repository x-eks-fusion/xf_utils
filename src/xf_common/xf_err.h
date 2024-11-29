/**
 * @file xf_err.h
 * @author catcatBlue (catcatblue@qq.com)
 * @brief 错误码及错误类型定义.
 * @version 1.0
 * @date 2024-06-19
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_ERR_H__
#define __XF_ERR_H__

/* ==================== [Includes] ========================================== */

#include "xf_common_config.h"
#include "../xf_std/xf_stdint.h"

/**
 * @ingroup group_xf_utils_user_common
 * @defgroup group_xf_utils_user_common_err xf_err
 * @brief 错误码及错误类型定义.
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/**
 * @brief 错误类型定义。
 *
 * @note  1. 非 0 值都为错误。
 *        2. 建议使用 xf_err_t 作为错误类型，xf_err_code_t 内的值仅用于对比。
 */
typedef enum {
    XF_FAIL = -1,                   /*!< 通用错误（执行失败） */
    XF_OK = 0,                      /*!< 通用成功（执行成功） */

    XF_ERR_NO_MEM = 0x100,          /*!< 内存不足 */
    XF_ERR_INVALID_ARG,             /*!< 无效参数 */
    XF_ERR_INVALID_STATE,           /*!< 无效状态 */
    XF_ERR_INVALID_CHECK,           /*!< 无效校验（校验发生错误） */
    XF_ERR_INVALID_PORT,            /*!< 对接的方法无效 */
    XF_ERR_NOT_FOUND,               /*!< 未找到 */
    XF_ERR_NOT_SUPPORTED,           /*!< 不支持 */
    XF_ERR_BUSY,                    /*!< 正忙 */
    XF_ERR_TIMEOUT,                 /*!< 超时 */
    XF_ERR_UNINIT,                  /*!< 未初始化 */
    XF_ERR_INITED,                  /*!< 已初始化 */

    XF_ERR_RESOURCE,                /*!< 资源不可用 */
    XF_ERR_ISR,                     /*!< 中断调用错误 */

    XF_ERR_MAX,                     /*!< 错误类型最大值 */
} xf_err_code_t;

/* ==================== [Typedefs] ========================================== */

/**
 * @brief 整形错误类型。
 * 错误码具体值见 @ref xf_err_code_t.
 */
typedef int32_t xf_err_t;

/* ==================== [Global Prototypes] ================================= */

/**
 * @brief 返回 xf_err_code_t 错误代码对应的错误信息字符串。
 *
 * @param code xf_err_code_t 错误代码。
 * @return const char * 错误信息字符串。
 */
const char *xf_err_to_name(xf_err_t code);

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /*extern "C"*/
#endif

/**
 * End of group_xf_utils_user_common_err
 * @}
 */

#endif /* __XF_ERR_H__ */
