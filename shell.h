#ifndef _SHELL_
#define _SHELL_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
extern char **environ;
/**
 *struct argument_s - Doubly linked list for storing commands
 *@tipo: type of argument
 *@com: command from getline
 *@prev: pointer to the previous node
 *@next: pointer to the next node
 */
typedef struct argument_s
{
	int tipo;
	char *com;
	struct argument_s *next;
	struct argument_s *prev;
} argument_t;

void _strtok_execv(char *buffer, char *name, int num);
char *_path(char *str);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
int _strlen_recursion(char *s);
int _env(int cont);
char *_strtok(char *str, char *separator, int flag);
char *_convert_num(int k);
void _error(char *name, char *comand, int num);
void free_grid(char **grid, int height);
int checking_logop(char *buffer);
argument_t *add_command(argument_t **head, char *comando, int num);
argument_t *command_to_nodes(argument_t **head, char *buffer, int num);
void printing_commands(argument_t *head);
void multiple_processes(char *buffer, int num);
char *_strdup(char *str);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(char *str);
int arguments_count(argument_t *head);
char *_strncat(char *dest, char *src, int n);
char *_strndup(char *str, int cont);
int is_opera(char c);
void free_arguments(argument_t **head);

#endif
