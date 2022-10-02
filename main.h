#ifndef MAIN_FUNCTION_SIMPLE_SHELL_H
#define MAIN_FUNCTION_SIMPLE_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <limits.h>
/**
 * struct envir_s - single linked list
 *
 * @varname: varname of environment
 *
 * @value: value of the var stored separately
 *
 * @next: address of next node
 *
 * Description: single linked list
 */
typedef struct envir_s
{
	char *varname;
	char *value;
	struct envir_s *next;
} envir_t;
void addheadnotnull(envir_t **head, char *environment, envir_t *temp);
void addheadwhennull(envir_t **head, char *environment);
int get_environment(envir_t *head, char *varname, char *valueofvar, int flag);
void free_list(envir_t *head);
int loop(char *envp[], char *copy_PATH, char *copy_PWD,
		char *get_stdin, envir_t *head, char *tempforfindfile);
void env(char *envp[]);
void setenvironment(char *argv[]);
void unsetenvironment(char *argv[]);
char *_getline(char *buffercopy);
void mygetline_fn(char *buffer);
int lengthcounter(char *str);
void prompt_icon(void);
void _write_to_STDOUT(char *_input);
int _strcmp(char *f_string, char *s_string);
char *_changegetlength(char *src);
int _process(char *envp[], char *argv[], char *path, char *tempforfindfile);
void separator_getline(char *argv[], char *string);
char *_strncpy_fromn(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
void does_file_exist(char *path, char *cmd[], char *tempforfindfile);
void _strcat(char *list, char *executable);
void separator_PATH(char *list[], char *path);
void copy_from_envp(char *copy_PATH, char *copy_PWD, char *envp[]);
int _hash_checker(char *f_char);
void change_directory(char *argv[], char *copy_PWD);
void echo_commands(envir_t *head, char *argv[], int status);
int _dollar_checker(char *f_char);
void _iota(int value, char *numberArray);
int _atoi(char *string);
int _is_digit(char *string);
void freevar(char *dest, char *copypid, char *copystatus, char *valueofvar);
#endif /* MAIN_FUNCTION_SIMPLE_SHELL_H */
