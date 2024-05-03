#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <string.h>
#include <ctype.h>
void parse_line(char *line, unsigned int ln)
{
	char *opcode;
	char *val;
	char *dilm = " \n\t";

	opcode = strtok(line, dilm);
	val = strtok(NULL, dilm);
	if (val == NULL && strcmp(opcode, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	find_func(opcode, val, ln);
}
void find_func(char *op, char *val, unsigned int ln)
{
	int i;
	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{NULL, NULL}
	};

	for (i = 0; func_list[i].f != NULL; i++)
	{
		if (strcmp(op, func_list[i].opcode) == 0)
		{
			call_func(func_list[i].f, op, val, ln);
		}
	}
}
void call_func(op_f f, char *op, char *val, unsigned int ln)
{
	stack_t *node;

	if (strcmp(op, "push") == 0)
	{
		if (!(is_digit(val)))
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			free_nodes();
			exit(EXIT_FAILURE);
		}
		node = creat_node(atoi(val));

		f(&node, 0);
	}
	else
	{
		if (f != NULL)
			f(&head, 0);
	}
}
void excute(char *file)
{
	FILE *fh;
	char *line = NULL;
	size_t len = 0;
	unsigned int ln = 1;
	int i;
	int is_blank_line;

	fh = fopen(file, "r");

	while (getline(&line, &len, fh) != -1)
	{
		is_blank_line = 1;
		i = 0;
		for (; line[i] != '\0'; i++)
		{
			if (!isspace(line[i]))
			{
				is_blank_line = 0;
				break;
			}
		}
		if (!is_blank_line)
			parse_line(line, ln);
		ln++;
	}
	free(line);
	fclose(fh);
}

