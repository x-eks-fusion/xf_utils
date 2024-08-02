# xf_utils

本仓库主要是为了统一一些基础常用功能的调用。以便移植到各个平台上

- xf_common: 错误码, 位操作, 链表等常用宏和数据类型定义.
  - xf_attr：定义了一些常用属性的宏。例如：__weak等功能
  - xf_bit_def：定义了一些位操作
  - xf_err：定义了错误枚举，以及错误枚举转换函数
  - xf_list: 双向链表库
  - xf_predef: 定义了一些常用宏，包括 ARRAY_SIZE、xf_container_of等
  - xf_version：定义了当前版本，获取版本的函数
- xf_log: 日志库。提供了日志的分等级打印，以及数组的打印等功能
- xf_check: 错误检查与断言。提供了基于错误库的断言检查。
- xf_lock: 常用作互斥锁, 取决于具体实现。保证多线程下，代码不出现竞争的锁
- xf_std: 对常用的标准库函数进行封装。以便于方便对单片机的移植

# 快速入门

1. 安装 xmake.

   [安装 - xmake](https://xmake.io/#/zh-cn/guide/installation)

2. 运行示例.

   ```bash
   # cd xf_utils 根目录
   clear; xmake clean ; xmake build ; xmake run 
   ```

# 快速移植指南

1. 复制`src`到你的工程
2. 将`src/xf_common/xf_err_to_name.c` `src/xf_lock/xf_lock.c` `src/xf_utils_log/xf_utils_log_dump.c` 加入编译。将`src`加入`include path`
3. 添加一个`xf_utils_config.h`配置文件（具体配置在`src`下面每个文件夹的`*_config.h`文件中）。
4. `lock`如果不使用则没必要管。如果使用，则可以通过 `#include "xf_utils_port.h"` 调用`xf_lock_register()`函数，完成对接方可使用。可以参考 `port/port_xf_lock.c` 。
