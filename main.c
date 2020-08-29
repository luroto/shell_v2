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
 *main- receive he info, verific Crt+C Crt+D and exit and exec other fu\
nc.
 *@argc: number of arguments
 *@argv: argments
 *
 *Return: ) if sucessful
 */
int main(int argc, char **argv)
{
	char *buffer = NULL;
	size_t bufsize = 1;
	ssize_t checkget = 0;
	history_t *hh = NULL;
	int num = 0, term = 0;

	(void)argc;
	signal(SIGINT, ctrlhandler);
	term = isatty(STDIN_FILENO);
	while (checkget != -1)
	{
		num++;
		if (term == 1)
			printf("$ ");
		checkget = getline(&buffer, &bufsize, stdin);
		if (checkget == -1)
			break;
		add_history(&hh, buffer, num);
		if (checking_logop(buffer) == 0 &&
			checking_builtins(buffer, &hh) == 0)
		_strtok_execv(buffer, argv[0], num);
		else
			multiple_processes(buffer, argv[0], num);
		if (term != 1 && checkget == -1)
			break;
	}
	free(buffer);
	free_history(&hh);
	return (0);
}
