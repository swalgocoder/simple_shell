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

#define INPUT_LENGTH 1002
#define ARGUMENT_LENGTH 1001

int main () {
  int childPid;
  int status;
  //  unsigned int i, j, k; //
  unsigned int i;
  int errno;
  int argCounter;
  unsigned int pathCounter;
  int sysCallReturn;
  const char whitespace[8] = " \t\v\n\f\n\r";
  const char colon[2] = ":";
  const char* path = getenv("PATH");
  char inputString[INPUT_LENGTH];
  char tempPath[strlen(path)];
  char *argv[ARGUMENT_LENGTH];
  char *inputPieces;
  char *pathPieces;
  char *pathArgs[strlen(path)];
  char *finalPathArgs[strlen(path)];
  struct stat sb;
  char *prompt = "#cisfun$";

  while (1) {

    fprintf(stdout, "%s", prompt);
    memset(inputString, 0, sizeof(inputString));
    memset(argv, 0, sizeof(argv));
    memset(pathArgs, 0, sizeof(pathArgs));


    if (fgets(inputString, INPUT_LENGTH, stdin) == NULL) {
      return 0;
    }


    if (strlen(inputString) > (INPUT_LENGTH - 2)) {
      printf("Cannot process more than 1000 characters of input\n");
      while (getchar() != '\n');
      continue;
    }


    childPid = fork();


    if (childPid == 0) {

      argCounter = 0;
      pathCounter = 0;


      inputPieces = strtok(inputString, whitespace);
      argv[argCounter] = inputPieces;


      while(inputPieces != NULL ) {
        argCounter++;
        inputPieces = strtok(NULL, whitespace);
        argv[argCounter] = inputPieces;
      }


      char pathString[strlen(path)];
      for (i = 0; i < strlen(path); i++) {
        pathString[i] = path[i];
      }


      pathPieces = strtok(pathString, colon);
      pathArgs[pathCounter] = pathPieces;


      while(pathPieces != NULL ) {
        pathCounter++;
        pathPieces = strtok(NULL, colon);
        pathArgs[pathCounter] = pathPieces;
      }


      for (i = 0; i < pathCounter; i++) {
        memset(tempPath, 0, sizeof(tempPath));
        strcpy (tempPath, pathArgs[i]);
        strcat (tempPath, "/");
        strcat (tempPath, argv[0]);
        finalPathArgs[i] = tempPath;
        sysCallReturn = stat(finalPathArgs[i], &sb);

        if (sysCallReturn == 0) {
          sysCallReturn = execv(finalPathArgs[i], argv);
          break;
        }
      }


      if (sysCallReturn == -1) {
        printf("%s\n", strerror(errno));
      }

      return 0;
    }

    else if (childPid == -1) {
      printf("%s\n", strerror(errno));
      break;
    }

    else {
      if (wait(&status) == -1) {
        printf("%s\n", strerror(errno));
      }
    }
  }
}
