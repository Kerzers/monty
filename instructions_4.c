#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: the stack
 * @line_number: the line number we read from in the file
 *
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */
void queue(stack_t **stack, unsigned int line_number)
{
	rotl(stack, line_number);
}
