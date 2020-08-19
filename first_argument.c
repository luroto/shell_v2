#include "shell.h"

int *first_argument(char *buffer)
{
    int i, j, k, total, flag = 0;
    static int result[2];
    
    total = _strlen_recursion(buffer);
    for (i = 0, j = 0; i < total; i++)
    {
        if (buffer[i] != ' ' && flag == 0)
        {
            j = i;
            flag = 1;
        }
        if (buffer[i] == ' ' && flag != 0)
            break;
    }
    k = i - j; 
    result[0] = j;
    result[1] = k;
    return (result);
}