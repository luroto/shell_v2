#include "shell.h"
/**
 *logical_operators - handles &&, || and ;
1;5202;0c *@head: Arguments list
 *@num: # of execution
 *Return - 0 if sucessful
 */
int logical_operators(argument_t *head, int num)
{
	char *fcom = NULL;
	int *ij, status = 0, value = 0;
	pid_t pid;

	while (head != NULL)
	{
		if (head->tipo == 0)
		{
			ij = first_argument(head->com);
			fcom = _strndup(head->com + ij[0], ij[1]);
			_strtok_execv(head->com, fcom, num);
			pid = waitpid(-1, &status, 0);
			printf("This is the value of waitpid : %d ", pid);
			if (WIFEXITED(status))
			{
				value = WEXITSTATUS(status);
				printf("This is the value %d ", value);
				if (head->next!= NULL)
				{
					if (head->next->tipo == 2 &&
					    value > 0)
						return (-1);
				}
				else
					if (head->prev->tipo == 2 &&
					    value > 0)
						return (-1);
			}
			free(fcom);
		}
		head = head->next;
	}
	return (0);
}
