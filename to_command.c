#include "shell.h"
/**
 * to_command - Handles redirection from file to command
 * @com: First command
 * @comp: Full first command
 * @op: The operator
 * @f: filename to be used as input
 * @program: Name of the executable
 * @num: # of executions
 * Return: 0 if successful, otherwise -1
 */
int to_command(char *com, char *comp, int op, char *f, char *program, int num)
{
	char *path = NULL, *arr[2];
	int i = 0, opf = 0, opera = 0, osi = 0;

	path = _path(com);
	arr[i] = _strtok(comp, " \t\n", 0);
	while (arr[i] != NULL)
	{
		i++;
		arr[i] = _strtok(comp, " \t\n", 1);
	}
	dup2(0, osi);
	if (op == 5)
		opf = open(f, O_RDONLY);
	else
		opf = open(f, O_CREAT | O_APPEND | O_RDWR, 0664);
	if (opf == -1)
	{
		_error(program, com, num);
		free(path);
		free_grid(arr, i);
		return (-1);
	}
	dup2(opf, 0);
	opera = execve(path, arr, environ);
	close(opf);
	dup2(osi, 0);
	close(osi);
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
