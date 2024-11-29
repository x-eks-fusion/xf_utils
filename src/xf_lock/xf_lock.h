/**
 * @file xf_lock.h
 * @author catcatBlue (catcatblue@qq.com)
 * @brief 锁抽象层。
 * @note 通常对接互斥锁。
 * @version 1.0
 * @date 2024-06-25
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_LOCK_H__
#define __XF_LOCK_H__

/* ==================== [Includes] ========================================== */

#include "xf_lock_types.h"

/**
 * @ingroup group_xf_utils_user
 * @defgroup group_xf_utils_user_lock xf_lock
 * @brief 锁接口（通常对接互斥锁）。
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/**
 * @brief 初始化锁.
 *
 * @attention 禁止重复初始化有效的锁句柄, 以防内存泄漏.
 *
 * @param[out] p_lock 获取并初始化一个锁.
 * @return xf_err_t
 *      - XF_OK                 成功
 *      - XF_FAIL               失败
 */
xf_err_t xf_lock_init(xf_lock_t *p_lock);

/**
 * @brief 销毁锁.
 *
 * @attention 销毁后注意将锁句柄赋值为 NULL, 防止产生未定义行为.
 *
 * @param lock 需要销毁的锁句柄.
 * @return xf_err_t
 *      - XF_OK                 成功
 *      - XF_FAIL               失败
 */
xf_err_t xf_lock_destroy(xf_lock_t lock);

/**
 * @brief 尝试上锁.
 *
 * 如果在本次锁定操作前已经上锁, 则立刻返回 0.
 *
 * @param lock 需要锁定的锁句柄.
 * @return int
 *      - XF_LOCK_FAIL          上锁失败
 *      - XF_LOCK_SUCC          上锁成功
 *
 * @note 返回值等同 bool, 只有成功和失败两种可能性.
 */
int xf_lock_trylock(xf_lock_t lock);

/**
 * @brief 锁定直至成功.
 *
 * @attention 不推荐重复上锁, 可能导致死锁.
 * 推荐使用非阻塞版本 `xf_lock_trylock()`.
 *
 * @param lock 需要锁定的锁句柄.
 * @return int
 *      - XF_LOCK_FAIL          上锁失败
 *      - XF_LOCK_SUCC          上锁成功
 *
 * @note 返回值等同 bool, 只有成功和失败两种可能性.
 */
int xf_lock_lock(xf_lock_t lock);

/**
 * @brief 锁定直至成功或者超时.
 *
 * @param lock 需要锁定的锁句柄.
 * @param timeout_ms 超时时间, 单位 ms.
 *      如果填入 `(uint32_t)(~0)`, 行为应当等同于 `xf_lock_ops_lock_t`.
 * @return int
 *      - XF_LOCK_FAIL          上锁失败
 *      - XF_LOCK_SUCC          上锁成功
 *
 * @note 返回值等同 bool, 只有成功和失败两种可能性.
 */
int xf_lock_timedlock(xf_lock_t lock, uint32_t timeout_ms);

/**
 * @brief 解锁.
 *
 * @attention 禁止重复解锁, 重复解锁可能是未定义操作.
 *
 * @param lock 需要解锁的锁句柄.
 * @return int
 *      - XF_LOCK_FAIL          解锁失败
 *      - XF_LOCK_SUCC          解锁成功
 *
 * @note 返回值等同 bool, 只有成功和失败两种可能性.
 */
int xf_lock_unlock(xf_lock_t lock);

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

/**
 * End of group_xf_utils_user_lock
 * @}
 */

#endif /* __XF_LOCK_H__ */
