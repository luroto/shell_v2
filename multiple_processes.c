#include "shell.h"
void multiple_processes(char *buffer, int oper, int num)
{
	argument_t *head = NULL;
	pid_t pid;
	int i;

	pid = fork();
	if (pid == 0)
	{
		command_to_nodes(&head, buffer, oper, num);
		//printing_commands(head);
		i = printing_commands(head);
		printf("This is the size: %d\n", i);
		free_arguments(&head);
		i = printing_commands(head);
		printf("\n\nVeamos si todo quedó en orden: This is the size: %d\n", i);
		free(buffer);
		exit (EXIT_SUCCESS);
	}
	if (pid > 0)
	if (pid == -1)
	{perror("Error");
		exit(0);}
}
