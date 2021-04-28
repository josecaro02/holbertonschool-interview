#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singli LL
 * @head: head of the linked list
 * @number: number to insert in the linked list
 * Return: Address of the new node, or NULL if it failed
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
	if (number <= current->n || current == NULL)
	{
		new->next = current;
		*head = new;
		return (new);
	}
	while (current->next != NULL && current->next->n < number)
		current = current->next;


	printf("Numero actuel %d\n", current->n);
	if (current == NULL)
	{
		new->next = NULL;
		return (new);
	}
	else
	{
		new->next = current->next;
		current->next = new;
		return (new);
	}
}
