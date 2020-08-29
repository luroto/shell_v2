#include "shell.h"
/**
 * multiple_processes - handles redirections and pipelines
 * @buffer: The entire line from getline
 * @program: Name of the executable
 * @num: number of times the process has been executed
 */
void multiple_processes(char *buffer, char *program, int num)
{
	argument_t *head = NULL;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		command_to_nodes(&head, buffer, num);
		executing_redirections_pipelines(head, program, num);
		free_arguments(&head);
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	if (pid > 0)
		wait(NULL);
	if (pid == -1)
	{
		perror("Error");
		exit(0);
	}
}
