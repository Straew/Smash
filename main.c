#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

int main() {
    char line[1024];
    
    while (1) {
        printf("👊 ");
        if (!fgets(line, sizeof(line), stdin)) break;
        line[strcspn(line, "\n")] = 0;

        char *args[64];
        int i = 0;
        args[i] = strtok(line, " ");
        while (args[i]) args[++i] = strtok(NULL, " ");

        if (args[0] == NULL) continue;
        if (strcmp(args[0], "exit") == 0) break;

        execute_command(args);
    }
    return 0;
}
