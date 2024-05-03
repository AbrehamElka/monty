#include "monty.h"
stack_t *head = NULL;
/**
 * main - the main function of the system.
 * @argc: the number of arguments.
 * @argv: the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	excute(argv[1]);
	free_nodes();
	return (0);
}
