#include "monty.h"
void add_to_stack(stack_t **newnode, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (newnode == NULL || *newnode == NULL)
		exit(1);
	if (head == NULL)
	{
		head = *newnode;
		return;
	}
	temp = head;
	head = *newnode;
	head->next = temp;
	temp->prev = head;
}

void print_stack(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;
	if (*stack == NULL)
		return;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
