#include "monty.h"
/**
 * add_ - adds a node to the stack.
 * @newnode: the newnode.
 * @line_number: the line number.
 *
 * Return: Nothing.
 */
void add_(stack_t **newnode, __attribute__((unused))unsigned int line_number)
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
/**
 * print_ - prints the values of the stack.
 * @stack: the top of the stack.
 * @line_number: the line number.
 *
 * Return: Nothing.
 */
void print_(stack_t **stack, __attribute__((unused))unsigned int line_number)
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
void pint_(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
