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
#include <ctype.h>
extern char **environ;
int prog_count;

int _count_tokens(char *str, char *delim);
int _size_tokens(char *str, char *delim);
char **get_args(char *line);
int handle_builtins(char **args, char *buffer, char *prog);
int handle_builtins2(char **args, char *buffer, char *prog);
void free_array(char **argv);
char *extract_path(void);
int is_valid_full_path(char **args);
int exec_full_path(char **args, char **argv);
void error_msg(int prog_cnt, char *cmd, char *prog, char *msg, char *arg, int mode);
char *get_full_path(char *cmd);
int exec_full_path_cmd(char **args, char **argv, char *fullcmd);
void handle_comments(char *buffer);
int alloc_line(char **pline, size_t *plsize, size_t newsize);
ssize_t _getline(char **pline, size_t *plsize, FILE *fp);
int exit_status(char *arg, char *prog);
char *int_to_string(char *str, int num);
int is_digit_string(char *s);
int _cd(char **args);
int _cd_HOME(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int flag_delim(char **str, char delim);
char **handle_op(char **args);
char **create_array(char **args, char *delim);
char *custom_strtok(char *str, const char *delimiters);
#endif