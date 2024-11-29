/**
 * @file xf_stdbool.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief xf_utils 对标准库 stdbool.h 的封装。
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
#   include <stdbool.h>
#endif

/**
 * @cond XFAPI_USER
 * @ingroup group_xf_utils_std
 * @defgroup group_xf_utils_std_stdbool xf_stdbool
 * @brief 对标准库 stdbool.h 的封装。
 * @endcond
 * @{
 */

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

#endif /* (XF_STDBOOL_IS_ENABLE == 0) */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

/**
 * End of group_xf_utils_std_stdbool
 * @}
 */

#endif // __XF_STDBOOL_H__
