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
#include <string.h>

/* MACROS */
#define DELIM "\n"
#define SIZE_BUF 1024

/* Principal functions */
void *line(char *);
int exe_file(char *, char **, char **);
int exe_command(char *, char **, char **);
void _env(char **);
int _cd(char **, char **, int);
int path(char *, char **, char **);

/* Other functions */
int pipes(char*, char**, int);
int ourcommands(char**, char**, int);
int _strlen(char *);
void print(char *);
void printerr(char *, int, char *, char *);
void *alloc_1(char *, char *);
char **alloc_2(char **, char *, char*);
void _free(char **);
char *_strcpy(char *, char *);
int _strcmp(char *, char *);
int _strncmp(char *, char *, int);
char *_strcat(char *, char *);
char *_get_cwd(void);
char *_get_home(char **);
char *_get_oldpwd(char **);
void _catch(int);
int ferr(char *);
char *_itoa(int, char *);
void *verify(char *);
int _atoi(int, char *);
int veri_buf(char *);
void _exit_arg(char *);
#endif
