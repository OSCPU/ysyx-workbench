#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main(int argc, char *argv[])
{
    FILE* fp;
    char* filename = argv[1];
    char* operate = argv[2];
    fp = fopen(filename, operate);
    int pid = fork();

    int i = 0, j = 1;
    int turn = 0;

    if(pid < 0){
        printf("Fork failed\n");
    }else if(pid == 0){
        while(turn != i);
        // fprintf(fp, "315PROC1      MYFILE1\n");
        fwrite("315PROC1 MYFILE1\n", sizeof(char), strlen("315PROC1 MYFILE1\n"), fp);
        turn  = j;
    }else{
        while(turn != j);
        // fprintf(fp, "315PROC2      MYFILE2\n");
        fwrite("315PROC1 MYFILE2\n", sizeof(char), strlen("315PROC1 MYFILE1\n"), fp);
    }
    fclose(fp);
    return 0;
}

