#include <string.h>
#include "shell.h"

int execute_command(char *args[]) {
    if (strcmp(args[0], "cd") == 0) {
        return handle_cd(args);
    }
    
    if (strcmp(args[0], "pwd") == 0) {
        return handle_pwd();
    }
    
    handle_external_command(args);
    return 0;
}
