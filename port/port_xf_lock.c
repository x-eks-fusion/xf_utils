/**
 * @file main.c
 * @author catcatBlue (catcatblue@qq.com)
 * @brief
 * @version 1.0
 * @date 2024-06-20
 *
 * Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

/* ==================== [Includes] ========================================== */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "xf_utils_port.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

static xf_err_t _lock_init(xf_lock_t *p_lock);
static xf_err_t _lock_destroy(xf_lock_t lock);
static int _lock_trylock(xf_lock_t lock);
static int _lock_lock(xf_lock_t lock);
static int _lock_timedlock(xf_lock_t lock, uint32_t timeout_ms);
static int _lock_unlock(xf_lock_t lock);

/* ==================== [Static Variables] ================================== */

static const xf_lock_ops_t lock_ops = {
    .init       = _lock_init,
    .destroy    = _lock_destroy,
    .trylock    = _lock_trylock,
    .lock       = _lock_lock,
    .timedlock  = _lock_timedlock,
    .unlock     = _lock_unlock,
};

/* ==================== [Macros] ============================================ */

#define _LOGE(fmt, ...) printf("[ERR](%s:%d): " fmt "\n", __FILE__,__LINE__, ##__VA_ARGS__)

#define _CHECK(e, ret) \
    do { \
        int __ret = (e); \
        if (__ret) { \
            _LOGE(XSTR(e)); \
            return ret;\
        } \
    } while (0)

/* ==================== [Global Functions] ================================== */

void port_xf_lock(void)
{
    xf_lock_register(&lock_ops);
}

/* ==================== [Static Functions] ================================== */

static xf_err_t _lock_init(xf_lock_t *p_lock)
{
    int ret = 0;

    /* 也可以改成静态的方式保存 pthread_mutex_t 数组 */
    pthread_mutex_t *p_pthread_mutex =
        (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    _CHECK(NULL == p_pthread_mutex, XF_FAIL);

    ret = pthread_mutex_init(p_pthread_mutex, NULL);
    _CHECK(0 != ret, XF_FAIL);

    /**
     * @brief 此处直接强转保存指针，而不是保存指向 p_pthread_mutex 的指针，
     * 静态方式时可以保存二级指针或数组索引。
     */
    *p_lock = (void *)p_pthread_mutex;

    return XF_OK;
}

static xf_err_t _lock_destroy(xf_lock_t lock)
{
    int ret = 0;
    pthread_mutex_t *p_pthread_mutex = (pthread_mutex_t *)lock;

    ret = pthread_mutex_destroy(p_pthread_mutex);
    _CHECK(0 != ret, XF_FAIL);

    free(p_pthread_mutex);

    /* 清除 *(uintptr_t)p_lock 不是这里的责任 */

    return XF_OK;
}

static int _lock_trylock(xf_lock_t lock)
{
    int ret = 0;
    pthread_mutex_t *p_pthread_mutex = (pthread_mutex_t *)lock;
    ret = pthread_mutex_trylock(p_pthread_mutex);
    if (0 != ret) {
        return XF_LOCK_FAIL;
    }
    return XF_LOCK_SUCC;
}

static int _lock_lock(xf_lock_t lock)
{
    int ret = 0;
    pthread_mutex_t *p_pthread_mutex = (pthread_mutex_t *)lock;
    ret = pthread_mutex_lock(p_pthread_mutex);
    if (0 != ret) {
        return XF_LOCK_FAIL;
    }
    return XF_LOCK_SUCC;
}

static int _lock_timedlock(xf_lock_t lock, uint32_t timeout_ms)
{
    int ret = 0;
    pthread_mutex_t *p_pthread_mutex = (pthread_mutex_t *)lock;

    struct timespec ts = {0};
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += timeout_ms / 1000;
    ts.tv_nsec += (timeout_ms % 1000) * 1000000;

    ret = pthread_mutex_timedlock(p_pthread_mutex, &ts);
    if (0 != ret) {
        return XF_LOCK_FAIL;
    }
    return XF_LOCK_SUCC;
}

static int _lock_unlock(xf_lock_t lock)
{
    int ret = 0;
    pthread_mutex_t *p_pthread_mutex = (pthread_mutex_t *)lock;
    ret = pthread_mutex_unlock(p_pthread_mutex);
    if (0 != ret) {
        return XF_LOCK_FAIL;
    }
    return XF_LOCK_SUCC;
}

