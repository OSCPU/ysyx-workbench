# MicroBench

CPU正确性和性能测试用基准程序。对AbstractMachine的要求：

1. 需要实现TRM和IOE的API。
2. 在IOE的全部实现均留空的情况下仍可运行。如果有正确实现的`AM_TIMER_UPTIME`，可以输出正确的统计时间。若这个功能没有实现(返回`0`)，仍可进行正确性测试。
3. 使用`putch(ch)`输出。
4. 堆区`heap`必须初始化(堆区可为空)。如果`heap.start == heap.end`，即分配了空的堆区，只能运行不使用堆区的测试程序。每个基准程序会预先指定堆区的大小，堆区不足的基准程序将被忽略。

## 使用方法

同一组程序分成四组：test，train，ref和huge。

| 名称  | 动态指令数  | 计时 | 计分 | 建议使用场景  |
| ----- | ----------- | ---- | ---- | ----- |
| test  | 约300K      |  X   |  X   | 正确性测试  |
| train | 约60M       |  O   |  X   | 在RTL仿真环境中研究微结构行为 |
| ref   | 约2B        |  O   |  O   | 在模拟器或FPGA环境中评估处理器性能 |
| huge  | 约50B       |  O   |  O   | 衡量高性能处理器(如真机)的性能 |

默认运行ref数据规模，可通过`mainargs`选择其它的数据规模, 如:
```bash
make ARCH=native run mainargs=huge
```

## 评分根据

每个benchmark都记录以`REF_CPU`为基础测得的运行时间微秒数。每个benchmark的评分是相对于`REF_CPU`的运行速度，与基准处理器一样快的得分为`REF_SCORE=100000`。

所有benchmark的平均得分是整体得分。

## 已有的基准程序

| 名称    | 描述                                | ref堆区使用  | huge堆区使用 |
| ----- | -------------------------------------------- | ----- |  ----- |
| qsort | 快速排序随机整数数组                         | 640KB | 16MB  |
| queen | 位运算实现的n皇后问题                        | 0     | 0     |
| bf    | Brainf**k解释器，快速排序输入的字符串        | 32KB  | 32KB  |
| fib   | Fibonacci数列f(n)=f(n-1)+…+f(n-m)的矩阵求解  | 256KB | 2MB   |
| sieve | Eratosthenes筛法求素数                       | 2MB   | 10MB  |
| 15pz  | A*算法求解4x4数码问题                        | 2MB   | 64MB  |
| dinic | Dinic算法求解二分图最大流                    | 680KB | 2MB   |
| lzip  | Lzip数据压缩                                 | 4MB   | 64MB  |
| ssort | Skew算法后缀排序                             | 4MB   | 64MB  |
| md5   | 计算长随机字符串的MD5校验和                  | 10MB  | 64MB  |

## 增加一个基准程序`foo`

在`src/`目录下建立名为`foo`的目录，将源代码文件放入。

每个基准程序需要实现三个函数：

* `void bench_foo_prepare();`：进行准备工作，如初始化随机数种子、为数组分配内存等。运行时环境不保证全局变量和堆区的初始值，因此基准程序使用的全局数据必须全部初始化。
* `void bench_foo_run();`：实际运行基准程序。只有这个函数会被计时。
* `int bench_foo_validate();`：验证基准程序运行结果。正确返回1，错误返回0。

在`benchmark.h`的`BENCHMARK_LIST`中增加相应的`def`项，格式参考已有的benchmark。

## 基准程序可以使用的库函数

虽然klib中提供了一些函数，但不同的klib实现会导致性能测试结果有差异。
因此MicroBench中内置一些简单的库函数:

* `bench_memcpy(void *dst, const void *src, size_t n)`: 内存复制。
* `bench_srand(uint seed)`：用seed初始化随机数种子。
* `bench_rand()`：返回一个0..32767之间的随机数。
* `bench_alloc`/`bench_free`：内存分配/回收。目前回收是空操作。

