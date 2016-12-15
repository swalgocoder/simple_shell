/*  
 *
 *  
 *  A linux command line interpreter
 *  
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include "holberton.h"

#define INPUT_LENGTH 1002
#define ARGUMENT_LENGTH 1001


int main () {
  int childPid;
  int status;
  unsigned int i;
  int errno;
  int arg_Counter;
  unsigned int path_Counter;
  int sysCallReturn;
  const char whitespace[8] = " \t\v\n\f\n\r";
  const char colon[2] = ":";
  const char* path = getenv("PATH");
  char inputString[INPUT_LENGTH];
  char tempPath[strlen(path)];
  char *argv[ARGUMENT_LENGTH];
  char *inputChar;
  char *pathChar;
  char *pathArgs[strlen(path)];
  char *final_PathArgs[strlen(path)];
  struct stat sb;
  const char *str = "#cisfun ";

  while (1) {

    write(1, str, strlen(str));
    memset(inputString, 0, sizeof(inputString));
    memset(argv, 0, sizeof(argv));
    memset(pathArgs, 0, sizeof(pathArgs));


    if (fgets(inputString, INPUT_LENGTH, stdin) == NULL) {
      return 0;
    }


    if (strlen(inputString) > (INPUT_LENGTH - 2)) {
      printf("Can't process more than 1000 characters\n");
      while (getchar() != '\n');
      continue;
    }


    childPid = fork();


    if (childPid == 0) {

      arg_Counter = 0;
      path_Counter = 0;


      inputChar = strtok(inputString, whitespace);
      argv[arg_Counter] = inputChar;


      while(inputChar != NULL ) {
        arg_Counter++;
        inputChar = strtok(NULL, whitespace);
        argv[arg_Counter] = inputChar;
      }


      char pathString[strlen(path)];
      for (i = 0; i < strlen(path); i++) {
        pathString[i] = path[i];
      }


      pathChar = strtok(pathString, colon);
      pathArgs[path_Counter] = pathChar;


      while(pathChar != NULL ) {
        path_Counter++;
        pathChar = strtok(NULL, colon);
        pathArgs[path_Counter] = pathChar;
      }


      for (i = 0; i < path_Counter; i++) {
        memset(tempPath, 0, sizeof(tempPath));
        strcpy (tempPath, pathArgs[i]);
        strcat (tempPath, "/");
        strcat (tempPath, argv[0]);
        final_PathArgs[i] = tempPath;
        sysCallReturn = stat(final_PathArgs[i], &sb);

        if (sysCallReturn == 0) {
          sysCallReturn = execv(final_PathArgs[i], argv);
          break;
        }
      }


      if (sysCallReturn == -1) {
        write(1, strerror(errno), strlen(strerror(errno)));
      }

      return 0;
    }

    else if (childPid == -1) {
      write(1, strerror(errno), strlen(strerror(errno)));
      break;
    }

    else {
      if (wait(&status) == -1) {
	write(1, strerror(errno), strlen(strerror(errno)));
      }
    }
  }
}
