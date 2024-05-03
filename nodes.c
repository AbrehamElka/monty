#include "monty.h"
#include <string.h>
#include <ctype.h>
/**
 * is_digit - checks if a string is intiger.
 * @val: the string.
 *
 * Return: 1 on success.
 */
int is_digit(char *val)
{
	int i = 0;

	while (val[i] != '\0')
	{
		if (val[i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (isdigit(val[i]))
		{
			i++;
			continue;
		}
		else
			return (0);
	}
	return (1);
}
/**
 * creat_node - creates a new node.
 * @n: the value for the new node.
 *
 * Return: a pointer that is a new node.
 */
stack_t *creat_node(int n)
{
	stack_t *temp;

	temp = (stack_t *)malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_nodes();
		exit(EXIT_FAILURE);
	}
	temp->next = NULL;
	temp->prev = NULL;
	temp->n = n;

	return (temp);
}
/**
 * free_nodes - frees all the allocated memory.
 */
void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);

	}
}
