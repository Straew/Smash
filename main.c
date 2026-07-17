#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
int main () {
    char line[1024]; // char limit
    // loop
    while (1) {
        printf("👊 ");
        if (!fgets(line, sizeof (line), stdin)) break; // gets the input
        line [strcspn (line, "\n")] = 0;  // finds where the Enter/newline is and chops it off

        char *args[64];
        int i =0;
        args[i]= strtok(line, " ");
        while (args[i]) args[++i] = strtok(NULL, " "); // splits command

        if (args[0] == NULL) continue; // no command? move on
        if (strcmp(args[0], "exit") == 0) break; // command==exit?terminate the program
        
        if (strcmp(args[0], "cd") == 0){ // 0 args holds cd cmd and 1 holds the dir
            if (args[1] == NULL){
                fprintf (stderr, "cd: expected an argument \n");
            }
            else {
                if (chdir(args[1]) != 0){ // dir doesnt exist 
                            perror("cd failed");
                        }
            }
            continue;
        }

        pid_t pid = fork(); // program cloner
        if (pid == 0){ // cloned program
            execvp(args[0], args); // become the og instead of a clone
            perror ("exec failed"); // error msg
            return 1;
        } 
        else {
            wait (NULL); // waits
        }
    }
    return 0;
}
