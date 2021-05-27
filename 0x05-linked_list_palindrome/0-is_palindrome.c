#include "lists.h"

/**
 * is_palindrome - function to check if a ll is palindrome
 *@head: head of the linked list
 *
 *Return: 1 if palindrome 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	listint_t *tail, *current;
	int n_nodes, i, j;

	n_nodes = 1;
	tail = current = *head;
	if (current == NULL)
		return (0);
	if (current->next == NULL)
		return  (1);
	while (tail->next != NULL)
	{
		n_nodes++;
		tail = tail->next;
	}

	tail = *head;
	for (i = 0; i < n_nodes / 2; i++)
	{
		for (j = 0; j < n_nodes - i - 1; j++)
			tail = tail->next;
		if (current->n != tail->n)
			return (0);
		current = current->next;
		tail = *head;
	}

	return (1);
}

