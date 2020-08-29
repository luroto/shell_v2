#include "shell.h"
/**
 * directory_error - Printing errors in case of EISDIR
 * @program: Name of the executable
 * @file: file that is a directory
 * @num: # of execution
 * Return: It's a void function
 */ 
void directory_error(char *program, char *file, int num)
{
        fprintf(stderr,"%s: %d: cannot create %s: Is a directory\n", program, num, file);
}