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
"  printf(\"%%u\", result); "
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
    switch (choose(4)) {
        case 0: strcpy(op, "+"); break;
        case 1: strcpy(op, "-"); break;
        case 2: strcpy(op, "*"); break;
        case 3: strcpy(op, "/"); break;
    }
}

// 生成随机表达式
void gen_rand_expr(char *buf, int depth) {
    if (depth > MAX_DEPTH) {
        gen_num(buf);  // 如果达到最大深度，生成数字
        return;
    }

    switch (choose(3)) {
        case 0:
            gen_num(buf);  // 生成数字
            break;
        case 1:
            strcat(buf, "(");
            gen_rand_expr(buf, depth + 1);  // 递归生成子表达式
            strcat(buf, ")");
            break;
        case 2:
            char left[BUF_SIZE], right[BUF_SIZE], op[10];
            left[0] = right[0] = op[0] = '\0';  // 初始化字符串
            gen_rand_expr(left, depth + 1);  // 生成左子表达式
            gen_rand_op(op);      // 生成操作符
            gen_rand_expr(right, depth + 1); // 生成右子表达式
            // 拼接最终的表达式
            sprintf(buf, "%s %s %s", left, op, right);
            break;
    }
}

int main(int argc, char *argv[]) {
    int seed = time(0);
    srand(seed);
    int loop = 1;
    if (argc > 1) {
        sscanf(argv[1], "%d", &loop);
    }
    
    for (int i = 0; i < loop; i++) {
        char expr_buf[BUF_SIZE];
        gen_rand_expr(expr_buf, 0);  // 生成随机表达式

        sprintf(code_buf, code_format, expr_buf);

        // 写入临时 C 文件
        FILE *fp = fopen("/tmp/.code.c", "w");
        assert(fp != NULL);
        fputs(code_buf, fp);
        fclose(fp);

        // 编译并生成可执行文件
        int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
        if (ret != 0) continue;  // 编译失败，跳过

        // 执行并获取结果
        fp = popen("/tmp/.expr", "r");
        assert(fp != NULL);

        int result;
        ret = fscanf(fp, "%d", &result);
        pclose(fp);

        if (ret == 1) {
            printf("%u %s\n", result, expr_buf);
        } else {
            printf("Error executing expression: %s\n", expr_buf);
        }
    }
    return 0;
}
