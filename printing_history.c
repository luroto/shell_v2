#include "shell.h"
/**
 * printing_history - Count the size of the linked list
 * @head: Pointer to the first node
 * Return: Size of the linked list
 */
void printing_history(history_t *head)
{
	while (head != NULL)
    {
        printf(" %d %s", head->num, head->com);
        head = head->next;
    }
}
