#include "shell.h"
/**
 * 
 * 
 * 
 */
extern char **environ;
int to_file(char *com, char *comp, int op, char *f, int num)
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
        opf = open(f, O_CREAT| O_TRUNC| O_RDWR, 0664);
    else 
        opf = open(f, O_CREAT| O_APPEND| O_RDWR, 0664);
    dup2(opf, 1);
    opera = execve(path, arr, environ);
    close(opf);
    fflush(stdout);
    dup2(ost, 1);
    close(ost);
    if (opera == 1)
    {
        _error(com, path, num);
        free(path);
        free_grid(arr, i);
        return (-1);
    }
    free(path);
    free_grid(arr, i);
    return (0);
}