#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <string.h>
#include <ctype.h>
/**
 * parse_line - parse a line.
 * @line: the line to parse.
 * @ln: the line number.
 *
 * Return: Nothing.
 */
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
/**
 * find_func - finds the instruction from the list.
 * @op: the function to search.
 * @val: the value given after the opcode.
 * @ln: the line number.
 *
 * Return: Nothing.
 */
void find_func(char *op, char *val, unsigned int ln)
{
	int i;
	int flag = 1;
	instruction_t func_list[] = {
		{"push", add_},
		{"pall", print_},
		{"pint", pint_},
		{"pop", pop_},
		{"swap", swap_},
		{"add", add_s},
		{"nop", nop_},
		{NULL, NULL}
	};

	for (i = 0; func_list[i].f != NULL; i++)
	{
		if (strcmp(op, func_list[i].opcode) == 0)
		{
			flag = 0;
			call_func(func_list[i].f, op, val, ln);
		}
	}
	if (flag)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, op);
		free_nodes();
		exit(EXIT_FAILURE);
	}
}
/**
 * call_func - calls the instruction.
 * @f: the function to be called.
 * @op: the instruction.
 * @val: the value after the instruction.
 * @ln: the line number.
 *
 * Return: Nothing.
 */
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

		f(&node, ln);
	}
	else
	{
		if (f != NULL)
			f(&head, ln);
	}
}
/**
 * excute - excutes the instructions in a file.
 * @file: the file to be processed.
 *
 * Return: Nothing.
 */
void excute(char *file)
{
	FILE *fh;
	char *line = NULL;
	size_t len = 0;
	unsigned int ln = 1;
	int i;
	int is_blank_line;

	fh = fopen(file, "r");
	if (fh == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

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

