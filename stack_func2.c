#include "monty.h"

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
void nop_(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	
}
