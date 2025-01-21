#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

static char code_buf[65536 + 128] = {}; // a little larger than buf
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u %s\\n\", result, \"%s\"); "
"  return 0; "
"}";

#define MAX_DEPTH 10  // 设置最大递归深度
#define BUF_SIZE 1024 // 增加缓冲区大小

// 随机选择一个数字
int choose(int n) {
    return rand() % n;
}

// 生成随机数字
void gen_num(char *buf) {
    sprintf(buf, "%u", rand());
}

// 生成运算符
void gen_rand_op(char *op) {
    switch (choose(8)) {  // 增加更多的操作符
        case 0: strcpy(op, "+"); break;
        case 1: strcpy(op, "-"); break;
        case 2: strcpy(op, "*"); break;
        case 3: strcpy(op, "/"); break;
        case 4: strcpy(op, "&&"); break;
        case 5: strcpy(op, "||"); break;
        case 6: strcpy(op, "!="); break;
        case 7: strcpy(op, "=="); break;
    }
}

// 生成随机表达式
void gen_rand_expr(char *buf, int depth) {
    if (depth > MAX_DEPTH) {
        gen_num(buf);  // 如果达到最大深度，生成数字
        return;
    }

    char temp_buf[BUF_SIZE];  // 使用临时缓冲区避免重叠

    switch (choose(8)) {  // 增加更多的表达式生成方式
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
            // 生成一个负数表达式或取反表达式
            gen_rand_expr(temp_buf, depth + 1);
            sprintf(buf, "-%s", temp_buf);  // 生成负数表达式
            break;
        case 4:
            // 生成带更多括号的子表达式
            temp_buf[0] = '\0';
            strcat(temp_buf, "(");
            gen_rand_expr(temp_buf + strlen(temp_buf), depth + 1);
            strcat(temp_buf, ")");
            if (choose(2)) {
                // 再次在括号外加一层
                char tmp_buf[BUF_SIZE];
                strcpy(tmp_buf, temp_buf);
                sprintf(buf, "(%s)", tmp_buf);
            } else {
                strcpy(buf, temp_buf);
            }
            break;
        case 5:
            // 生成逻辑表达式 (&& 或 ||)
            char left_logic[BUF_SIZE], right_logic[BUF_SIZE], op_logic[10];
            left_logic[0] = right_logic[0] = op_logic[0] = '\0';  // 初始化
            gen_rand_expr(left_logic, depth + 1);  // 生成左子表达式
            gen_rand_op(op_logic);      // 生成逻辑操作符
            gen_rand_expr(right_logic, depth + 1); // 生成右子表达式
            // 拼接最终的逻辑表达式
            sprintf(temp_buf, "%s %s %s", left_logic, op_logic, right_logic);
            strcpy(buf, temp_buf);
            break;
        case 6:
            // 生成不等式表达式
            gen_rand_expr(temp_buf, depth + 1);
            sprintf(buf, "%s != 0", temp_buf);  // 生成不等式
            break;
        case 7:
            // 生成等式表达式
            gen_rand_expr(temp_buf, depth + 1);
            sprintf(buf, "%s == 0", temp_buf);  // 生成等式
            break;
    }
}

int main(int argc, char *argv[]) {
    int seed = time(0);
    srand(seed);

    FILE *fp = fopen("input", "w");  // 打开文件用于写入
    assert(fp != NULL);  // 确保文件成功打开

    for (int i = 0; i < 100; i++) {  // 生成100条表达式
        char expr_buf[BUF_SIZE];
        gen_rand_expr(expr_buf, 0);  // 生成随机表达式
      //  char result_buf[BUF_SIZE];
        sprintf(code_buf, code_format, expr_buf, expr_buf);

        // 写入临时 C 文件
        FILE *temp_fp = fopen("/tmp/.code.c", "w");
        assert(temp_fp != NULL);
        fputs(code_buf, temp_fp);
        fclose(temp_fp);

        // 编译并生成可执行文件
        int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
        if (ret != 0) continue;  // 编译失败，跳过

        // 执行并获取结果
        temp_fp = popen("/tmp/.expr", "r");
        assert(temp_fp != NULL);

        int result;
        ret = fscanf(temp_fp, "%d", &result);
        pclose(temp_fp);

        if (ret == 1) {
            fprintf(fp, "%u %s\n", result, expr_buf);  // 将结果和表达式写入文件
        } else {
            fprintf(fp, "Error executing expression: %s\n", expr_buf);
        }
    }

    fclose(fp);  // 关闭文件

    return 0;
}

