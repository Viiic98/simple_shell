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
void ls(char*, char*, char**);
void pwd(char*, char*, char**);
void echo(char*, char*, char**);
void cp(char*, char*, char**);
void _env(char**);
void _cd(char **arg, char **env);


/* Other functions */
void pipes(char*, char**);
void ourcommands(char**, char**);

#endif
