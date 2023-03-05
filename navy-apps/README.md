# Navy Application Framework

## 编译方法

在应用程序目录(如`tests/hello/`)下通过
```bash
make ISA=xxx
```
编译程序, 通过
```bash
make ISA=xxx install
```
编译程序并将程序安装到文件系统镜像`fsimg/bin/`目录下.

若要单独编译函数库(如`libs/libbmp`), 则需要运行
```bash
make ISA=xxx archive
```

通过
```bash
make clean
```
清除应用程序或函数库的编译结果, 也可在工程根目录下运行
```bash
make clean-all
```
清除所有应用程序和函数库的编译结果.

## 文件系统镜像

`fsimg/`目录包含文件系统镜像的内容:
```
bin/ -- 二进制文件(该目录默认未创建)
share/  -- 平台无关文件
  files/ -- 用于文件测试
  fonts/ -- 字体文件
  music/ -- 示例音乐
  pictures/ -- 示例图像
  games/ -- 游戏数据(该目录默认未创建)
    nes/ -- NES Roms
    pal/ -- 仙剑奇侠传相关数据文件
```

工程根目录下的`Makefile`中包含构建文件系统镜像的规则,
可以修改`APPS`和`TESTS`变量指定安装到文件系统镜像的应用程序,
然后通过
```bash
make ISA=xxx fsimg
```
来编译并安装指定的应用程序.

此外可以通过
```bash
make ISA=xxx ramdisk
```
来将`fsimg/`中的内容顺序打包成一个简单的镜像文件`build/ramdisk.img`,
并生成相应的文件信息`build/ramdisk.h`.
支持简单文件系统的操作系统(如Nanos-lite)可以使用这一镜像.

## 支持的ISA/操作系统

### native (编译到本地Linux执行)

编译在本地时不链接libc和libos，使用本地的glibc/glibstdc++ (用g++不带参数链接)。

使用`LD_PRELOAD`实现了本地模拟的`/dev/events`, `/dev/fb`和其他一些设备文件, 具体可参考`libs/libos/src/native.cpp`.
代码模拟了与Navy兼容的运行时环境, 使用以下命令运行native程序:
```bash
make ISA=native run mainargs="参数1 参数2 ..."
```

### x86, mips32, riscv32, am_native (Nanos, Nanos-lite)

其中`am_native`是指在[AM项目](https://github.com/NJU-ProjectN/abstract-machine)的`native`上运行操作系统.

## 运行时环境

### 系统调用

Navy的运行时环境会提供一部分POSIX系统调用, 具体见`libs/libos/src/syscall.c`, 可以往其中添加更多的系统调用.
实现的系统调用越多, 可以运行的程序就越多.
若调用了未实现的系统调用, 则会触发assertion fail;
若一个未实现的系统调用不便触发assertion fail, 则会调用`exit()`结束运行.

### 特殊文件

Navy假设操作系统提供以下设备文件的支持:

1. 设备文件
 * `/dev/events`: 只读的设备, 应用程序能从中读出按键事件(事件之间以`'\n'`分隔), 按键名称全部大写, 名字同SDL扫描码名(参考nwm/native中的实现). 如`kd RETURN`表示按下回车键, `ku A`表示松开`A`键.
 * `/dev/fb`: 只写的设备, 看起来是一个W * H * 4字节的数组, 按行优先存储所有像素的颜色值(32位). 每个像素是`00rrggbb`的形式, 8位颜色. 该设备支持lseek. 屏幕大小从`/proc/dispinfo`文件中获得.
 * `/dev/sbclt`(可选): 可读可写的设备.
   * 写入时, 应用程序需要一次写入3个`int`整数共12字节, 3个整数会被依次解释成`freq`, `channels`, `samples`, 来对系统的声卡设备进行初始化.
   * 读出时, 应用程序可读出一个`int`整数, 表示当前声卡设备流缓冲区的空闲字节数.
 * `/dev/sb`(可选): 只写设备, 应用程序可以直接写入解码后的声音数据, 注意该设备不支持lseek, 此外写操作在声音数据完全写入到流缓冲区之后才会返回.
 * `/dev/null`, `/dev/zero`(可选): 永远返回空, 和永远返回0的虚拟设备.
 * `/dev/tty`(可选): 调试用的控制台.

2. procfs文件系统: 所有的文件都是key-value pair, 格式为` [key] : [value]`, 冒号左右可以有任意多(0个或多个)的空白字符(whitespace).
 * `/proc/dispinfo`: 屏幕信息, 包含的keys: `WIDTH`表示宽度, `HEIGHT`表示高度.
 * `/proc/cpuinfo`(可选): CPU信息.
 * `/proc/meminfo`(可选): 内存信息.

例如一个合法的 `/proc/dispinfo`文件例子如下:
```
WIDTH : 640
HEIGHT:480
```

### 运行库

* `libc`: C运行库, 移植自newlib 3.3.0, 同时包含最小的手写C++运行库(但不支持libstdc++)
* `libos`: 系统调用接口
* `compiler-rt`: 移植自llvm, 主要用于在32位ISA上提供64位除法的支持
* `libfixedptc`: 提供定点数计算的支持, 包含`sin`, `pow`, `log`等初等函数功能, 可以替代范围不大的浮点数
* `libndl`: NDL(NJU DirectMedia Layer), 提供时钟, 按键, 绘图, 声音的底层抽象
* `libbmp`: 支持32位BMP格式文件的读取
* `libbdf`: 支持BDF字体格式的读取
* `libminiSDL`: 基于NDL的多媒体库, 提供部分兼容SDL库的API
* `libvorbis`: OGG音频解码器, 仅支持解码成`s16le`格式的PCM编码, 移植自[stb项目][stb]
* `libam`: 通过Navy的运行时环境实现的AM API, 可以运行AM程序, 目前仅支持TRM和IOE
* `libSDL_ttf`: 基于libminiSDL和[stb项目][stb]中的truetype字体解析器, 支持truetype字体的光栅化
* `libSDL_image`: 基于libminiSDL和[stb项目][stb]中的图像解码器, 支持JPG, PNG, BMP, GIF的解码
* `libSDL_mixer`: 基于libminiSDL和libvorbis, 支持多通道混声, 目前仅支持OGG格式

[stb]: https://github.com/nothings/stb

## 应用程序列表

Navy目前收录的应用程序位于`apps/`目录下, 包括
* `nslider`: NJU幻灯片播放器, 可以播放4:3的幻灯片
* `menu`: 启动菜单, 可以选择需要运行的应用程序
* `nterm`: NJU终端, 包含一个简易內建Shell, 也支持外部Shell
* `bird`: flappy bird, 移植自sdlbird
* `pal`: 仙剑奇侠传, 支持音效, 移植自SDLPAL
* `am-kernels`: 可在libam的支持下运行部分AM应用, 目前支持coremark, dhrystone和打字小游戏
* `fceux`: 可在libam的支持下运行的红白机模拟器
* `oslab0`: 学生编写的游戏集合, 可在libam的支持下运行
* `nplayer`: NJU音频播放器, 支持音量调节和可视化效果, 目前仅支持OGG格式
* `lua`: LUA脚本解释器
* `busybox`: BusyBox套件(版本1.32.0), 系统调用较少时只能运行少量工具
* `onscripter`: NScripter脚本解释器, 在Navy环境中可支持Planetarian, Clannad等游戏的运行
* `nwm`: NJU窗口管理器(需要mmap, newlib中不支持, 故目前只能运行在native)

## 应用程序编写指南

### ANSI C应用程序

原则上, ANSI C程序可以直接编译运行. `stdin`可以读取输入, `stdout`, `stderr`能接受输出.

#### NTerm终端应用程序

向`stdout`, `stderr`输出字符序列显示在终端上，接受ANSI escape sequences (`#`表示数字):
* `\033[s`: 保存光标状态
* `\033[u`: 恢复上次保存的光标状态
* `\033[J`/`\033[2J`: 清除屏幕
* `\033[K`: 清除光标后到行末的字符（含光标处的字符）
* `\033[#;#H`/`\033[#;#f]`: 移动光标到数字所在行/列（行/列从1开始编号）
* `\033[H`/`\033[f`: 将移动光标到左上角
* `\033[#A`: 光标向上移动数字行
* `\033[#B`: 光标向下移动数字行
* `\033[#C`: 光标向右移动数字列
* `\033[#D`: 光标向左移动数字列
* `\033[#;#;...;#m`: 设置显示模式, 只提供部分ANSI escape sequence的支持

NTerm-specific:

* `\033[1t`: cookmode
* `\033[2t`: rawmode

具体可参考`apps/nterm/src/term.cpp`.

#### NWM图形程序

通过NWM创建的应用程序可以通过以下文件描述符与NWM通信:
* `3`号文件是事件管道, 应用程序读取该文件会得到与`/dev/events`格式一致的事件(即发送给这个进程的按键事件)
* `4`号文件是图形控制管道, 应用程序在绘图前向该文件写入两个整数, 表示应用程序期望创建的窗口宽度和高度, 整数之间由空格分隔, 写入后, 需要轮询`3`号文件, 等待NWM的应答. NWM收到上述两个整数后, 创建相应大小的窗口和画布canvas, 创建成功后往`3`号文件写入`mmap ok`(暂定), 通知应用程序窗口创建成功.
* `5`号文件是画布共享内存, 在应用程序收到窗口创建成功的消息后可以访问, 其大小与窗口大小一致. NWM可以从中直接读出应用程序绘制的内容.
