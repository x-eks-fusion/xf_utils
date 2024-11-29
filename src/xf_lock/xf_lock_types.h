/**
 * @file xf_lock_types.h
 * @author catcatBlue (catcatblue@qq.com)
 * @brief 锁通用数据类型。
 * @version 1.0
 * @date 2024-06-25
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_LOCK_TYPES_H__
#define __XF_LOCK_TYPES_H__

/* ==================== [Includes] ========================================== */

#include "../xf_common/xf_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup group_xf_utils_user_lock
 * @{
 */

/* ==================== [Defines] =========================================== */

#define XF_LOCK_SUCC                    1  /*!< 上锁或者解锁成功 */
#define XF_LOCK_FAIL                    0  /*!< 上锁或者解锁失败 */

/* ==================== [Typedefs] ========================================== */

/**
 * @brief lock 句柄.
 */
typedef void *xf_lock_t;

/**
 * End of group_xf_utils_user_lock
 * @}
 */

/**
 * @ingroup group_xf_utils_port_lock
 * @{
 */

/**
 * @brief 初始化锁.
 *
 * @attention 禁止重复初始化有效的锁句柄, 以防内存泄漏.
 *
 * @param[out] p_lock 指向需要初始化的锁句柄的指针.
 * @return xf_err_t
 *      - XF_OK                 成功
 *      - XF_FAIL               失败
 */
typedef xf_err_t (*xf_lock_ops_init_t)(xf_lock_t *p_lock);

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
typedef xf_err_t (*xf_lock_ops_destroy_t)(xf_lock_t lock);

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
typedef int (*xf_lock_ops_trylock_t)(xf_lock_t lock);

/**
 * @brief 锁定直至成功.
 *
 * @attention 调用规范不推荐重复上锁,
 * 实现该函数时, 推荐在锁定前检测锁的持有者是否为同一个.
 *
 * @param lock 需要锁定的锁句柄.
 * @return int
 *      - XF_LOCK_FAIL          上锁失败
 *      - XF_LOCK_SUCC          上锁成功
 *
 * @note 返回值等同 bool, 只有成功和失败两种可能性.
 */
typedef int (*xf_lock_ops_lock_t)(xf_lock_t lock);

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
typedef int (*xf_lock_ops_timedlock_t)(xf_lock_t lock, uint32_t timeout_ms);

/**
 * @brief 解锁.
 *
 * @attention 推荐实现该函数时, 检测是否为重复解锁.
 *
 * @param lock 需要解锁的锁句柄.
 * @return int
 *      - XF_LOCK_FAIL          解锁失败
 *      - XF_LOCK_SUCC          解锁成功
 *
 * @note 返回值等同 bool, 只有成功和失败两种可能性.
 */
typedef int (*xf_lock_ops_unlock_t)(xf_lock_t lock);

/**
 * @brief 锁操作结构体.
 *
 * @attention 通常要求所有操作全部实现, 特殊情况下至少实现:
 * 1. `init`;
 * 2. `trylock`;
 * 3. `unlock`.
 * @attention 如未完全实现, 请用 `#pragma message("...")` 等方式明显地通知用户.
 */
typedef struct xf_lock_ops_s {
    xf_lock_ops_init_t      init;
    xf_lock_ops_destroy_t   destroy;
    xf_lock_ops_trylock_t   trylock;
    xf_lock_ops_lock_t      lock;
    xf_lock_ops_timedlock_t timedlock;
    xf_lock_ops_unlock_t    unlock;
} xf_lock_ops_t;

/**
 * End of group_xf_utils_port_lock
 * @}
 */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
}
#endif

#endif /* __XF_LOCK_TYPES_H__ */
