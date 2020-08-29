#include "shell.h"
/**
 * access_error - Printing errors in case of EACCES
 * @program: Name of the executable
 * @file: file that doesn't have permissions
 * @num: # of execution
 * Return: It's a void function
 */ 
void access_error(char *program, char *file, int num)
{
        fprintf(stderr,"%s: %d: cannot open %s: Permission denied\n", program, num, file);
}