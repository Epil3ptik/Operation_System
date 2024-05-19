#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "factorial.h"

#define BUF_SIZE 1024
const int OUT = 1;

int num = 11;

int main() {
    char buf[BUF_SIZE];
    int fd[2];
    pipe(fd);
    ssize_t pid = fork();
    if (pid == 0) { // дочерний процесс
        long long int fact = factorial(num);
        ssize_t len = snprintf(buf, sizeof(buf), "Factorial of %d is %lld\n", num, fact);
        close(fd[0]);
        write(fd[1], buf, len);
        close(fd[1]);
        _exit(0);
    } 
    else if (pid > 0) { // родительский процесс
        int status;
        close(fd[1]);
        wait(&status);
        ssize_t len = read(fd[0], buf, BUF_SIZE);
        write(OUT, buf, len);
        close(fd[0]);
    } 
    else { // ошибка
        printf("Error creating a child process!\n");
    }
    return 0;
}
