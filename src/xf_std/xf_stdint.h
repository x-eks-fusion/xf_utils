/**
 * @file xf_stdint.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-07-09
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_STDINT_H__
#define __XF_STDINT_H__

/* ==================== [Includes] ========================================== */

#include "xf_std_config.h"

#if XF_STDINT_IS_ENABLE
#   include <stdint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

#if (XF_STDINT_IS_ENABLE == 0)

typedef signed   char                   int8_t;         /*!<  8bit 整形 */
typedef signed   short                  int16_t;        /*!< 16bit 整形 */
typedef signed   int                    int32_t;        /*!< 32bit 整形 */
typedef unsigned char                   uint8_t;        /*!<  8bit 无符号整形 */
typedef unsigned short                  uint16_t;       /*!< 16bit 无符号整形 */
typedef unsigned int                    uint32_t;       /*!< 32bit 无符号整形 */
typedef long     int                    intptr_t;       /*!< 指针大小类型 */

#ifndef UINT8_MAX
#define UINT8_MAX                       (0xffU)         /*!<  uint8_t 的最大数字 */
#endif
#ifndef UINT16_MAX
#define UINT16_MAX                      (0xffffU)       /*!< uint16_t 的最大数字 */
#endif
#ifndef UINT32_MAX
#define UINT32_MAX                      (0xffffffffU)   /*!< uint32_t 的最大数字 */
#endif

#endif /* (XF_STDDEF_IS_ENABLE == 0) */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_STDINT_H__
