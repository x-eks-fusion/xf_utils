/**
 * @file xf_utils_config.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_UTILS_CONFIG_H__
#define __XF_UTILS_CONFIG_H__

/* ==================== [Includes] ========================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

#define XF_STDDEF_ENABLE                    (1)
#define XF_STDDEF_ENABLE                    (1)
#define XF_STDINT_ENABLE                    (1)
#define XF_STDBOOL_ENABLE                   (1)
#define XF_STDLIB_ENABLE                    (1)
#define XF_STRING_ENABLE                    (1)

#define XF_CHECK_ENABLE                     (1)
#define XF_ASSERT_IS_ENABLE                 (1)
#define XF_ERROR_CHECK_IS_ENABLE            (1)

/**
 * @brief 是否使能错误码值到字符串的查找表(`XF_OK`->"XF_OK").
 */
#define XF_COMMON_ERR_TO_NAME_LOOKUP_DISABLE    (1)


#define XF_ATTRIBUTE_ENABLE                     (1)

#define XF_LOG_LEVEL                            XF_LOG_VERBOSE

#define XF_LOG_DUMP_ENABLE                      (1)

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_UTILS_CONFIG_H__
