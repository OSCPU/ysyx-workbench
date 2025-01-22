#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdint.h>  // 确保包含此头文件，定义了UINT32_MAX

#define MAX_DEPTH 10  // 设置最大递归深度
#define BUF_SIZE 1024 // 增加缓冲区大小

// 随机选择一个数字，生成32位无符号数
void gen_num(char *buf) {
    // 使用 rand() % UINT32_MAX 来生成 0 到 UINT32_MAX 的无符号整数
    sprintf(buf, "%u", rand() % UINT32_MAX);  // 生成0到UINT32_MAX的无符号整数
}

// 生成运算符
void gen_rand_op(char *op) {
    switch (rand() % 4) {  // 只生成 + - * /
        case 0: strcpy(op, "+"); break;
        case 1: strcpy(op, "-"); break;
        case 2: strcpy(op, "*"); break;
        case 3: strcpy(op, "/"); break;
    }
}

// 在数字和运算符之间插入随机空格
void add_random_spaces_between(char *buf) {
    int len = strlen(buf);
    for (int i = 0; i < len; i++) {
        if (i > 0 && ((buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/')
            || buf[i] == '(' || buf[i] == ')')) {
            // 1/3 的概率在运算符和数字或括号之间插入空格
            if (rand() % 3 == 0) {
                // 插入空格
                memmove(buf + i + 1, buf + i, len - i + 1);
                buf[i] = ' ';
                len++;
                i++;  // 跳过插入的空格
            }
        }
    }
}

// 生成随机表达式
void gen_rand_expr(char *buf, int depth) {
    if (depth > MAX_DEPTH) {
        gen_num(buf);  // 如果达到最大深度，生成数字
        return;
    }

    char temp_buf[BUF_SIZE];  // 使用临时缓冲区避免重叠

    switch (rand() % 5) {  // 增加更多的表达式生成方式
        case 0:
            gen_num(buf);  // 生成数字
            break;
        case 1:
            temp_buf[0] = '\0';
            strcat(temp_buf, "(");
            gen_rand_expr(temp_buf + strlen(temp_buf), depth + 1);  // 递归生成子表达式
            strcat(temp_buf, ")");
            strcpy(buf, temp_buf);  // 使用临时缓冲区来存储最终结果
            break;
        case 2:
            char left[BUF_SIZE], right[BUF_SIZE], op[10];
            left[0] = right[0] = op[0] = '\0';  // 初始化字符串
            gen_rand_expr(left, depth + 1);  // 生成左子表达式
            gen_rand_op(op);      // 生成操作符
            gen_rand_expr(right, depth + 1); // 生成右子表达式
            // 拼接最终的表达式到临时缓冲区
            sprintf(temp_buf, "%s %s %s", left, op, right);
            strcpy(buf, temp_buf);  // 使用临时缓冲区
            break;
        case 3:
            // 保证负号不会连续生成
            gen_rand_expr(temp_buf, depth + 1);
            sprintf(buf, "%s", temp_buf);  // 仅生成正数
            break;
        case 4:
            // 生成带更多括号的子表达式
            temp_buf[0] = '\0';
            strcat(temp_buf, "(");
            gen_rand_expr(temp_buf + strlen(temp_buf), depth + 1);
            strcat(temp_buf, ")");
            if (rand() % 2) {
                // 再次在括号外加一层
                char tmp_buf[BUF_SIZE];
                strcpy(tmp_buf, temp_buf);
                sprintf(buf, "(%s)", tmp_buf);
            } else {
                strcpy(buf, temp_buf);
            }
            break;
    }
    
    // 在生成的表达式中随机插入空格
    add_random_spaces_between(buf);
}



