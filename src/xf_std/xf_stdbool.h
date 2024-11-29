/**
 * @file xf_stdbool.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-07-09
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_STDBOOL_H__
#define __XF_STDBOOL_H__

/* ==================== [Includes] ========================================== */

#include "xf_std_config.h"

#if XF_STDBOOL_IS_ENABLE
#include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

#if (XF_STDBOOL_IS_ENABLE == 0)

#ifndef bool
typedef uint8_t                         bool;           /*!< 布尔类型 */
#define true    1
#define false   0
#endif

#endif

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_STDBOOL_H__
