#include "lists.h"
#include <stdlib.h>
/**
 *insert_node - Insert a node in the head of the linked list
 *@head: pointer to pointer of first node of listint_t list
 *@number: integer to be included in new node
 *
 *Return: addresss of the new head of the linked list of NULl if fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		if (current->n > number)
		{
			new->next = current;
			*head = new;
			return (*head);
		}
		while (current->next != NULL)
		{
			if(current->n == number){
				new->next = current->next;
				current->next = new;
				return (*head);
			}
			if (current->n < number)
			{
				if (current->next->n > number)
				{
					new->next = current->next;
					current->next = new;
					return (*head);
				}
			}
			current = current->next;
		}
		current->next = new;
		new->next = NULL;

	}

	return (*head);
}
