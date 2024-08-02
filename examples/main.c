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
#include <string.h>
#include <unistd.h>

#include "xf_utils.h"
#include "xf_utils_port.h" /*!< 通常不需要该头文件 */

#include "xf_utils_config.h"
#include "port_xf_lock.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

static void test_log_hello(void);
static void test_log_level(void);

static void test_xf_lock(void);

/* ==================== [Static Variables] ================================== */

static const char *TAG = "main";

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

int main(void)
{
    /* 初始化对接 */
    port_xf_lock();

    test_log_hello();
    test_log_level();
    test_xf_lock();
}

/* ==================== [Static Functions] ================================== */

static void test_log_hello(void)
{
    XF_LOGU(TAG, "hello: 测试格式化输出: int: %d, str: %s, float: %f", 123, "abc", -123.456f);
    XF_LOGE(TAG, "hello: 测试格式化输出: int: %d, str: %s, float: %f", 123, "abc", -123.456f);
    XF_LOGW(TAG, "hello: 测试格式化输出: int: %d, str: %s, float: %f", 123, "abc", -123.456f);
    XF_LOGI(TAG, "hello: 测试格式化输出: int: %d, str: %s, float: %f", 123, "abc", -123.456f);
    XF_LOGD(TAG, "hello: 测试格式化输出: int: %d, str: %s, float: %f", 123, "abc", -123.456f);
    XF_LOGV(TAG, "hello: 测试格式化输出: int: %d, str: %s, float: %f", 123, "abc", -123.456f);

    XF_LOG_BUFFER_HEXDUMP("hello world", 12);
}

static void test_log_level(void)
{
    XF_LOGU(TAG, "hello");
    XF_LOGE(TAG, "hello");
    XF_LOGW(TAG, "hello");
    XF_LOGI(TAG, "hello");
    XF_LOGD(TAG, "hello");
    XF_LOGV(TAG, "hello");
}

static void test_xf_lock(void)
{
    xf_lock_t log_lock      = NULL;
    xf_lock_t heap_lock     = NULL;
    xf_lock_t user_lock     = NULL;

    XF_ERROR_CHECK(xf_lock_init(&log_lock));
    XF_ERROR_CHECK(xf_lock_init(&heap_lock));
    XF_ERROR_CHECK(xf_lock_init(&user_lock));

    int ret = 0;

    XF_LOGI(TAG, "First attempt to lock using heap_lock.");
    ret = xf_lock_trylock(heap_lock);
    /* 第一次上锁应当成功 */
    if (0 == ret) {
        XF_LOGE(TAG, "xf_lock_trylock(heap_lock) FAIL");
    } else {
        XF_LOGI(TAG, "xf_lock_trylock(heap_lock) SUCC");
    }

    XF_LOGI(TAG, "Try heap_lock for a second time.");
    ret = xf_lock_trylock(heap_lock);
    /* 第二次上锁应当失败 */
    if (0 == ret) {
        XF_LOGI(TAG, "xf_lock_trylock(heap_lock) FAIL");
    } else {
        XF_LOGE(TAG, "xf_lock_trylock(heap_lock) SUCC");
    }

    XF_LOGI(TAG, "The first attempt to unlock the heap_lock.");
    ret = xf_lock_unlock(heap_lock);
    /* 在上锁的情况下，第一次解锁应当成功 */
    if (0 == ret) {
        XF_LOGE(TAG, "xf_lock_unlock(heap_lock) FAIL");
    } else {
        XF_LOGI(TAG, "xf_lock_unlock(heap_lock) SUCC");
    }

    /* 在没有上锁的情况下，不能重复解锁，该行为是未定义行为 */

    XF_ERROR_CHECK(xf_lock_destroy(log_lock));
    XF_ERROR_CHECK(xf_lock_destroy(heap_lock));
    XF_ERROR_CHECK(xf_lock_destroy(user_lock));
    log_lock = NULL;
    heap_lock = NULL;
    user_lock = NULL;
}
