#include "monty.h"

/**
 * add - add the top two elements
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */

void add(stack_t **stack, unsigned int line_number)
{
	size_t l = stack_len(*stack);

	if (l < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	((*stack)->next)->n += (*stack)->n;
	pop(&(*stack), line_number);
}

/**
 * sub - add the top two elements
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	size_t l = stack_len(*stack);

	if (l < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	((*stack)->next)->n -= (*stack)->n;
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
