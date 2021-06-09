#include "lists.h"

/**
 *check_cycle - checks if a linked list has a cycle
 *@list: pointer to heaf of list
 *
 *Return: 1 if has a cycle, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	slow = malloc(sizeof(listint_t));
	fast = malloc(sizeof(listint_t));

	slow = fast = list;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
