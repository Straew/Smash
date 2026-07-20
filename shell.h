#ifndef SHELL_H
#define SHELL_H

void shell_loop();
int execute_command(char *args[]);
int handle_cd(char *args[]);
int handle_pwd();
void handle_external_command(char *args[]);

#endif
