#ifndef MONTY_FILE
#define MONTY_FILE
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern stack_t *head;
typedef void (*op_f)(stack_t **stack, unsigned int line_number);

void parse_line(char *line, unsigned int ln);
void excute(char *file);
void find_func(char *op, char *val, unsigned int ln);
void call_func(void (*f)(stack_t **stack, unsigned int line_number), char *op, char *val, unsigned int ln);

stack_t *creat_node(int n);
void free_nodes(void);
void add_(stack_t **stack, unsigned int line_number);
void print_(stack_t **stack, unsigned int line_number);
void pint_(stack_t **head, unsigned int line_number);
void pop_(stack_t **stack, unsigned int ln);
void swap_(stack_t **stack, unsigned int ln);
void add_s(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int ln);
int is_digit(char *val);
#endif
