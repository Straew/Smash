#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

int handle_cd(char *args[]) {
    char *target = args[1];
    
    if (target == NULL || strcmp(target, "~") == 0) {
        target = getenv("HOME");
        if (target == NULL) {
            fprintf(stderr, "cd: HOME not set\n");
            return 1;
        }
    }
    
    if (chdir(target) != 0) {
        perror("cd failed");
        return 1;
    }
    return 0;
}

int handle_pwd() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
        return 0;
    } else {
        perror("pwd failed");
        return 1;
    }
}

void handle_external_command(char *args[]) {
    pid_t pid = fork();
    
    if (pid == 0) {
        execvp(args[0], args);
        perror("exec failed");
        exit(1);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("fork failed");
    }
}
