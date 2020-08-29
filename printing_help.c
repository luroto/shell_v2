#include "shell.h"

void printing_help(char *buffer)
{
        if (_strcmp(buffer, "help cd\n") == 0)
        {
                printf("cd allows you to change directory\n");
        }
        else if (_strcmp(buffer, "help history\n") == 0)
        {
                printf("history prints all the commands you have entered so far\n");
        }
        else if (_strcmp(buffer, "help exit\n") == 0)
        {
                printf("exit allows you to close this shellcito. You can give a value to it\n");
        }
}