#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

/* Libraries */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

/* MACROS */
#define DELIM "|\n"
#define SIZE_BUF 1024

/* Principal functions */
void *line(char *);
void _env(char **);
void _cd(char **arg, char **env);
void path(char *, char **, char **);

/* Other functions */
void pipes(char*, char**);
void ourcommands(char**, char**);
int _strlen(char *);
void print(char *);
void *alloc_1(char *, char *);
char **alloc_2(char **, char *, char*, char *);
void _free(char **);
char *_strcpy(char *, char *);
#endif
