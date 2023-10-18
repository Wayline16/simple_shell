#ifndef __MAIN
#define __MAIN
#define NOTUSED(x) (void)(x)
/*include headers*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdbool.h>
/* Global environemnt */
extern char **environ;
/* Global program counter*/
int prog_count;

/**
 * struct alias - A new struct type defining a alias
 * @name:name of alias
 * @value: value of alias
 */
typedef struct alias {
  char *name;
  char *value;
} alias_t;

/*alias handlers*/
int handle_alias(char **args, char *buffer, char *prog);
void print_all_aliases();
alias_t *get_alias(char *name);
void print_aliases(char *names);
void define_alias(char *name, char *value);
void remove_alias(char *name);
char *get_command_by_name(char *name);
char *get_alias_name(char *str);
char *get_alias_value(char *str);
char **check_alias(char **args);
void free_aliases();
/*builtin command handlers*/
int handle_builtins(char **args, char *buffer, char *prog);
int handle_builtins2(char **args, char *buffer, char *prog);
int _cd(char **args);
int _cd_HOME(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void handle_echo_status(void);
void handle_echo_pid(void);
void handle_echo_args(char **args);
int exit_status(char *arg, char *prog);
int handle_file(char **args, char *prog);
int handle_file_test(char **args, char *prog);
/*command path handlers*/
char *extract_path(void);
int exec_full_path(char **args, char **argv);
char *get_full_path(char *cmd);
int exec_full_path_cmd(char **args, char **argv, char *fullcmd);
int is_valid_full_path(char **args);
/*string support handlers*/
void free_array(char **argv);
char *int_to_string(int num);
int is_digit_string(char *s);
int flag_arraydelim(char **str, char delim);
int flag_delim(char *str, char delim);
/*error msg handlers*/
void error_msg(int prog_cnt, char *cmd, char *prog, char *msg, char *arg, int mode);
/*input handlers*/
void handle_comments(char *buffer);
size_t custom_getline(char **lineptr, size_t *n, FILE *stream);
int _count_tokens(char *str, char *delim);
int _size_tokens(char *str, char *delim);
char **get_args(char *line);
char **handle_op(char **args);
char *custom_strtok(char *str, const char *delimiters);

#endif