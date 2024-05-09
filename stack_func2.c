#include "monty.h"
/**
 * swap_ - swaps the top two stacks.
 * @stack: the top of the stack.
 * @ln: the line number.
 *
 * Return: Nothing.
 */
void swap_(stack_t **stack, unsigned int ln)
{
	int x;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		free_nodes();
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = x;
}
/**
 * add_s - adds the top of the two stacks.
 * @stack: top of the stack.
 * @ln: the line number.
 *
 * Return: Nothing.
 */
void add_s(stack_t **stack, unsigned int ln)
{
	int sum = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		free_nodes();
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = sum;
}
/**
 * nop - does nothing.
 * @s: top of the stack.
 * @l: the line number.
 *
 * Return: Nothing.
 */
void nop(stack_t **s, unsigned int l)
{
	(void)s;
	(void)l;
}
