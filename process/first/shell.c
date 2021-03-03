#include "shell.h"

#define buffer_len 1024

void Shelll() {
  char line[buffer_len];          // to get command line
  char *argv[100];                // user command
  char *path = "/bin/";           // to set path at bin
  char progpath[20];              //for full file path
  int argc;                       //to get arg count

  while (1) {

    printf("My shell>> ");      //to print shell prompt

    if (!fgets(line, BUFFER_LEN, stdin))
      break;

    size_t length = strlen(line);

    if (line[length - 1] == '\n')
      line[length - 1] = '\0';

    if (strcmp(line, "exit") == 0) {      // check if the command is exiting
      break;
    }

    char *token;              // split the command into separate strings
    token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
      argv[i] = token;
      token = strtok(NULL, " ");
      i++;
    }
    argv[i] = NULL;             // set the last value to NULL for execvp

    argc = i; // get arg count
    for (i = 0; i < argc; i++) {
      printf("%s\n", argv[i]);            // print command/args
    }
    strcpy(progpath, path);              // copy /bin/ to file path
    strcat(progpath, argv[0]);             // add the program to path

    for (i = 0; i < strlen(progpath); i++) {    // delete newline
      if (progpath[i] == '\n') {
        progpath[i] = '\0';
      }
    }
    int pid = fork(); // fork child

    if (pid == 0) { // Child
      execvp(progpath, argv);
      fprintf(stderr, "Child process could not execvp\n");

    } else { // Parent
      wait(NULL);
      printf("Child got exited\n");
    }
  }
}
