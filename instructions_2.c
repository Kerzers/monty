#include "monty.h"

/**
 * add - add the top two elements
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */

void add(stack_t **stack, unsigned int line_number)
{

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't add, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	((*stack)->next)->n += (*stack)->n;
	pop(&(*stack), line_number);
}

/**
 * nop - doesn’t do anything
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
