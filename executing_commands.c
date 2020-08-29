#include "shell.h"
/**
*executing_redirections_pipelines - Executes commands given the redirections,
*pipelines or
*other operators
*@head: Pointer to the first node
*@num: # of execution
*Return: 0 if processes were sucessful, otherwise > 0
*/
int executing_redirections_pipelines(argument_t *head, int num)
{
	struct stat st;
	char *aux = NULL, *fcom = NULL;
	int *ij;
	int op = 0, idx = 0;
	char *f = NULL;

	while (head != NULL)
	{
		if (idx == 0)
		{
			ij = first_argument(head->com);
			fcom = _strndup(head->com + ij[0], ij[1]);
			aux = head->com + ij[0];
		}
		if (idx == 1)
			op = head->tipo;
		if (idx == 2)
			f = head->com;
		idx++;
		head = head->next;
	}
	if (stat(fcom, &st) != 0)
	{
		_error(aux, fcom,num);
		free_arguments(&head);
		free(fcom);
		exit(EXIT_FAILURE);
	}
	if (op == 6 || op == 3)
		idx = to_file(fcom, aux, op, f, num);
	if (op == 5)
		idx = to_command(fcom, aux, op, f, num);
	free(fcom);
	return (idx);
}
