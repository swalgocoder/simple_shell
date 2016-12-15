#ifndef MY_SHELL
#define MY_SHELL
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define INPUT_LENGTH 1002
#define ARGUMENT_LENGTH 1001

/* string functions */
int _putchar(char c);
int _printstring(char *string);
unsigned int _strlen(const char *s);
char * _strcpy(char *strDest, const char *strSrc);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, const char *s2);
/* memory functions */
char *_memset(void *s, int b, unsigned int n);
/* environment functions */
char *_getenv(const char *name);

#endif
