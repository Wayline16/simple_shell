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
#include <fcntl.h>

extern char **environ;
int prog_count;

typedef struct alias {
  char *name;
  char *value;
} alias_t;


void print_all_aliases();
alias_t *get_alias(char *name);
void print_aliases(char *names);
void define_alias(char *name, char *value);
void remove_alias(char *name);
char *get_command_by_name(char *name);
void free_aliases();

int _count_tokens(char *str, char *delim);
int _size_tokens(char *str, char *delim);
char **get_args(char *line);
int handle_builtins(char **args, char *buffer, char *prog);
int handle_builtins2(char **args, char *buffer, char *prog);
int handle_alias(char **args, char *buffer, char *prog);
void free_array(char **argv);
char *extract_path(void);
int is_valid_full_path(char **args);
int exec_full_path(char **args, char **argv);
void error_msg(int prog_cnt, char *cmd, char *prog, char *msg, char *arg, int mode);
char *get_full_path(char *cmd);
int exec_full_path_cmd(char **args, char **argv, char *fullcmd);
void handle_comments(char *buffer);
char **check_alias(char **args);

/*ssize_t _getline(char **pline, size_t *plsize, FILE *fp);*/
size_t custom_getline(char **lineptr, size_t *n, FILE *stream);

int exit_status(char *arg, char *prog);
char *int_to_string(int num);
int is_digit_string(char *s);
int _cd(char **args);
int _cd_HOME(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int flag_arraydelim(char **str, char delim);
int flag_delim(char *str, char delim);
char **handle_op(char **args);
char ***create_cmd_array(char **args, char *delim);
char *custom_strtok(char *str, const char *delimiters);
void handle_echo_status(void);
void handle_echo_pid(void);
void handle_echo_args(char **args);
char *get_alias_name(char *str);
char *get_alias_value(char *str);

#endif