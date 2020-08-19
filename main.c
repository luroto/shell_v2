#include "shell.h"
/**
 *ctrlhandler - receive the comand Crt + C
 *
 *@numa: integer which receives the signal handler before return
 */
void ctrlhandler(__attribute__((unused))int numa)
{
	signal(SIGINT, ctrlhandler);
	write(1, "\n", 1);
}
/**
 *main - receive the info, verific Crt+C Crt+D and exit and exec other fu\
nc.
 *@argc: number of arguments
 *@argv: argments
 *
 *Return: ) if sucessful
 */
int main(int argc, char **argv)
{
	char *buffer = NULL, *aux = "exit\n";
	size_t bufsize = 1;
	ssize_t checkget = 0;
	history_t *hh = NULL;
	int num = 0;

	(void)argc;
	signal(SIGINT, ctrlhandler);
	while (checkget != -1)
	{
		num++;
		printf("$ ");
		checkget = getline(&buffer, &bufsize, stdin);
		if (checkget == -1)
			break;
		add_history(&hh, buffer, num);
		if (_strcmp(buffer, aux) == 0)
		{
			free(buffer);
			free_history(&hh);
			exit(0);
		}
		if (checking_logop(buffer) == 0)
			_strtok_execv(buffer, argv[0], num);
		else
			multiple_processes(buffer, num);
	}
	free(buffer);
	free_history(&hh);
	return (0);
}
