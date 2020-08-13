#include "shell.h"
/**
 * arguments_count - Count the size of the linked list
 * @head: Pointer to the first node
 * Return: Size of the linked list
 */
int arguments_count(argument_t *head)
{
	int size = 0;

	if (head == NULL)
		return (size);

	while (head != NULL)
	{
		size++;
		head = head->next;
	}
	return (size);
}
