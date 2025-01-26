#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUF_SIZE 8192

void gen_rand_expr(char *buf, int depth);

void generate_and_run_program(const char *expr) {
    // 1. 创建一个临时 C 文件
    FILE *fp = fopen("temp.c", "w");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    // 写入 C 程序代码
    fprintf(fp, "#include <stdio.h>\n");
    fprintf(fp, "int main() {\n");
    fprintf(fp, "  unsigned result = %s;\n", expr);
    fprintf(fp, "  printf(\"%%u\", result);\n");
    fprintf(fp, "  return 0;\n");
    fprintf(fp, "}\n");

    fclose(fp);

      // 2. 编译生成的 C 文件
    int compile_result = system("gcc temp.c -o temp.out");
    if (compile_result != 0) {
        fprintf(stderr, "Compilation failed!\n");
        exit(1);
    }

    // 3. 运行生成的程序并获取结果
    FILE *pipe = popen("./temp.out", "r");
    if (!pipe) {
        perror("popen");
        exit(1);
    }

    char result_buf[BUF_SIZE] = {0};
    if (!fgets(result_buf, BUF_SIZE, pipe)) {
        perror("fgets");
        pclose(pipe);
        exit(1);
    }
    pclose(pipe);

    // 输出表达式和结果
   
    printf("%s %s\n",result_buf, expr);


    // 4. 清理临时文件
    int remove_result = system("rm -f temp.c temp.out");
    if (remove_result != 0) {
        fprintf(stderr, "Failed to remove temporary files!\n");
        exit(1);
    }
}

int main() {
    srand(time(0));

    for (int i = 0; i < 100; i++) {  // 生成 100 条测试用例
        char expr_buf[BUF_SIZE] = {0};
        gen_rand_expr(expr_buf, 0);

        generate_and_run_program(expr_buf);
    }

    return 0;
}

