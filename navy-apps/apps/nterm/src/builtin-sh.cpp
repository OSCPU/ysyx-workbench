#include <nterm.h>
#include <stdarg.h>
#include <unistd.h>
#include <SDL.h>

char handle_key(SDL_Event *ev);

static void sh_printf(const char *format, ...) {
  static char buf[256] = {};
  va_list ap;
  va_start(ap, format);
  int len = vsnprintf(buf, 256, format, ap);
  va_end(ap);
  term->write(buf, len);
}

static void sh_banner() {
  sh_printf("Built-in Shell in NTerm (NJU Terminal)\n\n");
}

static void sh_prompt() {
  sh_printf("sh> ");
}

static void sh_handle_cmd(const char *cmd) {
  // 从 cmd 中获取命令名称
  char* c_name = strtok((char*)cmd, " \n"); // 改为用“ ”分割可以把后面的作为一个字符串，为了可拓展性，改为了全部分割到遇到\n
printf("%s\n",c_name);
  if (c_name == NULL) {
    // 如果没有命令名称，直接返回
    return;
  } 
  else if (strcmp(c_name, "echo") == 0) {
    // 处理 echo 命令
    char* str = strtok(NULL, "\n"); // 获取“echo”的后面的指针 
    sh_printf("%s\n", str);
  }
  else if((strcmp(c_name, "exit") == 0)){
    exit(0);
  }
  else if((strcmp(c_name, "run") == 0)){
    char* str = strtok(NULL, "\n");
    execve((const char *)str, (char**)NULL, (char**)NULL);
  }
}

void builtin_sh_run() {
  sh_banner();
  sh_prompt();

  while (1) {
    SDL_Event ev;
    if (SDL_PollEvent(&ev)) {
      if (ev.type == SDL_KEYUP || ev.type == SDL_KEYDOWN) {
        const char *res = term->keypress(handle_key(&ev));
        if (res) {
          sh_handle_cmd(res);
          sh_prompt();
        }
      }
    }
    refresh_terminal();
  }
}
