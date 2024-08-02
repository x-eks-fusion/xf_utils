/**
 * @file xf_lock.c
 * @author catcatBlue (catcatblue@qq.com)
 * @brief
 * @version 1.0
 * @date 2024-06-25
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

/* ==================== [Includes] ========================================== */

#include "xf_lock.h"
#include "../xf_std/xf_stddef.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

static const xf_lock_ops_t *sp_ops = NULL;

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

xf_err_t xf_lock_register(const xf_lock_ops_t *const p_ops)
{
    if ((NULL == p_ops)
            || (NULL == p_ops->init)
            || (NULL == p_ops->trylock)
            || (NULL == p_ops->unlock)) {
        return XF_FAIL;
    }
    sp_ops = p_ops;
    return XF_OK;
}

/**
 * @attention 注意！此处不对 p_lock 内的值进行判断，
 * 因为 xf_lock_t lock 存的可能是索引.
 */

xf_err_t xf_lock_init(xf_lock_t *p_lock)
{
    if ((NULL == sp_ops) || (NULL == p_lock)) {
        return XF_FAIL;
    }
    return sp_ops->init(p_lock);
}

xf_err_t xf_lock_destroy(xf_lock_t lock)
{
    if ((NULL == sp_ops) || (NULL == sp_ops->destroy)) {
        return XF_FAIL;
    }
    return (sp_ops->destroy(lock));
}

int xf_lock_trylock(xf_lock_t lock)
{
    if ((NULL == sp_ops) || (NULL == sp_ops->trylock)) {
        return XF_LOCK_FAIL;
    }
    return sp_ops->trylock(lock);
}

int xf_lock_lock(xf_lock_t lock)
{
    if ((NULL == sp_ops) || (NULL == sp_ops->lock)) {
        return XF_LOCK_FAIL;
    }
    return sp_ops->lock(lock);
}

int xf_lock_timedlock(xf_lock_t lock, uint32_t timeout_ms)
{
    if ((NULL == sp_ops) || (NULL == sp_ops->timedlock)) {
        return XF_LOCK_FAIL;
    }
    return sp_ops->timedlock(lock, timeout_ms);
}

int xf_lock_unlock(xf_lock_t lock)
{
    if ((NULL == sp_ops) || (NULL == sp_ops->unlock)) {
        return XF_LOCK_FAIL;
    }
    return sp_ops->unlock(lock);
}

/* ==================== [Static Functions] ================================== */

