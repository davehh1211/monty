#ifndef MONTY_
#define MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct free_s - free the var noted
 * @file: file opened
 * @buffer: buffer of getline
 *
 * Description: file and buffer
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct free_s
{
	FILE *file;
	char *buffer;
} free_t;

extern free_t var_global;

void *_calloc(unsigned int nmemb, unsigned int size);
void optacodevalid(char *opcode, unsigned int line_number,
stack_t **stack);
void o_push(stack_t **stack, unsigned int line_number);
void o_pall(stack_t **stack, unsigned int line_number);
void o_pop(stack_t **stack, unsigned int line_number);
void free_dlistint(stack_t *head);
void fileread(char *argv, stack_t **stack);
int numberchecker(char *str);
void o_nop(stack_t **stack, unsigned int line_number);


#endif
