/**
 * @file xf_err_to_name.c
 * @author catcatBlue (catcatblue@qq.com)
 * @brief 错误码转字符串.
 * @version 1.0
 * @date 2024-06-19
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_ERR_TO_NAME_H__
#define __XF_ERR_TO_NAME_H__

/* ==================== [Includes] ========================================== */

#include "xf_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/**
 * @brief Error Table Item.
 * 错误码和说明字符串。
 */
#define ERR_TBL_IT(err) {err, XSTR(err)}

/* ==================== [Typedefs] ========================================== */

/**
 * @brief 错误码和说明字符串结构体。
 */
typedef struct xf_err_msg_t {
    xf_err_code_t code;
    const char *msg;
} xf_err_msg_t;

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

#if XF_COMMON_ERR_TO_NAME_LOOKUP_IS_ENABLE
static const xf_err_msg_t xf_err_msg_table[] = {
    ERR_TBL_IT(XF_FAIL),
    ERR_TBL_IT(XF_OK),

    ERR_TBL_IT(XF_ERR_NO_MEM),
    ERR_TBL_IT(XF_ERR_INVALID_ARG),
    ERR_TBL_IT(XF_ERR_INVALID_STATE),
    ERR_TBL_IT(XF_ERR_INVALID_CHECK),
    ERR_TBL_IT(XF_ERR_INVALID_PORT),
    ERR_TBL_IT(XF_ERR_NOT_FOUND),
    ERR_TBL_IT(XF_ERR_NOT_SUPPORTED),
    ERR_TBL_IT(XF_ERR_BUSY),
    ERR_TBL_IT(XF_ERR_TIMEOUT),
    ERR_TBL_IT(XF_ERR_UNINIT),
    ERR_TBL_IT(XF_ERR_INITED),

    ERR_TBL_IT(XF_ERR_RESOURCE),
    ERR_TBL_IT(XF_ERR_ISR),

    ERR_TBL_IT(XF_ERR_MAX),
};
#endif /* XF_COMMON_ERR_TO_NAME_LOOKUP_IS_ENABLE */

static const char xf_unknown_msg[] = {
#if XF_COMMON_ERR_TO_NAME_LOOKUP_IS_ENABLE
    "ERROR",
#else
    "UNKNOWN ERROR",
#endif
};

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

const char *xf_err_to_name(xf_err_t code)
{
#if XF_COMMON_ERR_TO_NAME_LOOKUP_IS_ENABLE
    unsigned int i = 0;
    for (i = 0; i < (unsigned int)ARRAY_SIZE(xf_err_msg_table); ++i) {
        if (xf_err_msg_table[i].code == code) {
            return xf_err_msg_table[i].msg;
        }
    }
#endif /* XF_COMMON_ERR_TO_NAME_LOOKUP_IS_ENABLE */
    return xf_unknown_msg;
}

/* ==================== [Static Functions] ================================== */

#ifdef __cplusplus
}
#endif

#endif // __XF_ERR_TO_NAME_H__
