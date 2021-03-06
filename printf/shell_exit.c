/*  
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

#define INPUT_LENGTH 1000
#define ARGUMENT_LENGTH 1001

int main () {
  int childPid;
  int status;
  int i, j, k;
  int errno;
  int argCounter;
  int pathCounter;
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
  //const char delim[2] = ":";
  const char token[5] = "exit";
  //char token2;

  
  while (1) {
    // Outputs '% ' to the shell program and resets variables from prev proccess
    fprintf(stdout, "%% ");
    memset(inputString, 0, sizeof(inputString));
    memset(argv, 0, sizeof(argv));
    memset(pathArgs, 0, sizeof(pathArgs));

    // Reads in user input; If EOF is reached, terminate program
    if (fgets(inputString, INPUT_LENGTH, stdin) == NULL) {
      return 0;
    }

    // token = strtok(0, " ");
    //token = inputString;
    //printf("entered token is :%s", token);

    //printf("token element:%c", token[1]);
    //printf("token element:%c", inputString[1]);

    if (inputString[1] == token[1] && inputString[2] == token[2] && inputString[3] == token[3] && inputString[0] == token[0]) 
      {
      printf("exit entered...exiting");
      exit(0);
      }
    
    // If input exeeds max, print error message and restart prompt
    if (strlen(inputString) > (INPUT_LENGTH - 2)) {
      printf("Cannot process more than 1000 characters of input; exiting...\n");
      //test exit(0)
      exit(0);

      // Manually flush buffer via getchar
      while (getchar() != '\n');
      continue;
    }

    // Fork a child process
    childPid = fork();

    // Child process executes following code
    if (childPid == 0) {
      // Resets counters from previous child process
      argCounter = 0;
      pathCounter = 0;

      // Parses the input string into arguments based on whitespace
      //testing input
      //testing //
      
      inputPieces = strtok(inputString, whitespace);
      argv[argCounter] = inputPieces;
      
      // Parses the remainder of the string based on whitespace
      while(inputPieces != NULL ) {
        argCounter++;
        inputPieces = strtok(NULL, whitespace);
        argv[argCounter] = inputPieces;
      }

      // Convert PATH variable to a string to be parsed
      char pathString[strlen(path)];
      for (i = 0; i < strlen(path); i++) {
        pathString[i] = path[i];
      }

      // Parses the PATH environment variable based on colons
      pathPieces = strtok(pathString, colon);


      
      pathArgs[pathCounter] = pathPieces;

      // Parses the remainder of the PATH environment variable based on colons
      while(pathPieces != NULL ) {
        pathCounter++;
        pathPieces = strtok(NULL, colon);
        pathArgs[pathCounter] = pathPieces;
      }

      // Appends file to end of each path and calls stat() to validate file
      for (i = 0; i < pathCounter; i++) {
        memset(tempPath, 0, sizeof(tempPath));
        strcpy (tempPath, pathArgs[i]);
        strcat (tempPath, "/");
        strcat (tempPath, argv[0]);
        finalPathArgs[i] = tempPath;
        sysCallReturn = stat(finalPathArgs[i], &sb);
        // If stat() call successful, execv() with proper path and break out
        if (sysCallReturn == 0) {
          sysCallReturn = execv(finalPathArgs[i], argv);
          break;
        }
      }

      // If last system call is unsuccessful, print out error message
      if (sysCallReturn == -1) {
        printf("%s\n", strerror(errno));
      }
      // Return from child process
      return 0;
    }
    // If fork() error occurs, print out appropriate message to alert user
    else if (childPid == -1) {
      printf("%s\n", strerror(errno));
      break;
    }
    // Parent process executes following code
    else {
      // Waits for child process to terminate before executing
      // If wait() error occurs, print out appropriate message to alert user
      if (wait(&status) == -1) {
        printf("%s\n", strerror(errno));
      }
    }
  }
}
