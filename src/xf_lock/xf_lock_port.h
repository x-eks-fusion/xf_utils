/**
 * @file xf_lock_port.h
 * @author catcatBlue (catcatblue@qq.com)
 * @brief 锁对接。
 * @version 1.0
 * @date 2024-06-25
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_LOCK_PORT_H__
#define __XF_LOCK_PORT_H__

/* ==================== [Includes] ========================================== */

#include "xf_lock_types.h"

/**
 * @cond XFAPI_PORT
 * @ingroup group_xf_utils_port
 * @defgroup group_xf_utils_port_lock xf_lock
 * @brief 对接 xf_lock 操作集。
 * @endcond
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/**
 * @brief 注册锁操作.
 *
 * @param p_ops 指向静态锁操作集的指针, 操作集必须在整个程序生命周期中可用.
 * @return xf_err_t
 *      - XF_OK                 成功
 *      - XF_FAIL               失败
 */
xf_err_t xf_lock_register(const xf_lock_ops_t *const p_ops);

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

/**
 * End of group_xf_utils_port_lock
 * @}
 */

#endif /* __XF_LOCK_PORT_H__ */
