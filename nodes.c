#include "monty.h"
#include <string.h>
#include <ctype.h>
int is_digit(char *val)
{
	int i = 0;

	while (val[i] != '\0')
	{
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
