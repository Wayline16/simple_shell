#ifndef __MAIN
#define __MAIN
#define NOTUSED(x) (void)(x)

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
extern char **environ;

int _count_tokens(char *str, char *delim);
int _size_tokens(char *str, char *delim);
char **get_args(char *line);
int handle_builtins(char **args, char *buffer);
void free_array(char **argv);
char *extract_path(void);
int is_valid_full_path(char **args);
int exec_full_path(char **args, char **argv);
void error_msg(char *prog);
char *get_full_path(char *cmd);
int exec_full_path_cmd(char **args, char **argv, char *fullcmd);
#endif