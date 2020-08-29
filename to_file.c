#include "shell.h"
/**
 *to_file - handles redirection to files
 *@com: First command
 *@comp: Full first command
 *@op: Operator for this command
 *@f: File for output redirection
 *@program: Name of the executable
 *@num: # of process
 *Return: 0 if all OK, otherwise -1
 */
int to_file(char *com, char *comp, int op, char *f, char *program, int num)
{
	char *path = NULL, *arr[2];
	int i = 0, opf = 0, opera = 0, ost = 0;

	path = _path(com);
	arr[i] = _strtok(comp, " \t\n", 0);
	while (arr[i] != NULL)
	{
		i++;
		arr[i] = _strtok(comp, " \t\n", 1);
	}
	dup2(1, ost);
	if (op == 3)
		opf = open(f, O_CREAT | O_TRUNC | O_RDWR, 0664);
	else
		opf = open(f, O_CREAT | O_APPEND | O_RDWR, 0664);
	if (opf == -1)
	{
		_error(program, com, num);
		free(path);
		free_grid(arr, i);
		return (-1);
	}
	dup2(opf, 1);
	opera = execve(path, arr, environ);
	close(opf);
	fflush(stdout);
	dup2(ost, 1);
	close(ost);
	if (opera == 1)
	{
		_error(program, com, num);
		free(path);
		free_grid(arr, i);
		return (-1);
	}
	free(path);
	free_grid(arr, i);
	return (0);
}
