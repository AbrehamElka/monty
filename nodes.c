#include "monty.h"

stack_t *creat_node(int n)
{
	stack_t *temp;

	temp = (stack_t *)malloc(sizeof(stack_t));
	if (temp == NULL)
		exit(1);
	temp->next = NULL;
	temp->prev = NULL;
	temp->n = n;

	return (temp);
}

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
