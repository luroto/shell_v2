#include "shell.h"
/**
*executing_redirections_pipelines - Executes commands given the redirections,
*pipelines or
*other operators
*@head: Pointer to the first node
*@program: Name of the executable
*@num: # of execution
*Return: 0 if processes were sucessful, otherwise > 0
*/
int executing_redirections_pipelines(argument_t *head, char *program, int num)
{
	char *aux = NULL, *fcom = NULL, *fpath = NULL, *err = "1";
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
	fpath = _path(fcom);
	if (fpath[0] != err[0])
	{
		if (op == 6 || op == 3)
			idx = to_file(fcom, aux, op, f, program, num);
		if (op == 5)
			idx = to_command(fcom, aux, op, f, program, num);
		free(fcom);
		return (idx);
	}
	_error(program, fcom, num);
	free_arguments(&head);
	free(fcom);
	exit(EXIT_FAILURE);
}
