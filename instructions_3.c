#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */

void mod(stack_t **stack, unsigned int line_number)
{
	size_t len = 0;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	((*stack)->next)->n %= (*stack)->n;
	pop(&(*stack), line_number);
}