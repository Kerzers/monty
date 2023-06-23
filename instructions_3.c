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

/**
 * pchar - prints character equvalent of n
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */

void pchar(stack_t **stack, unsigned int line_number)
{

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)(*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */

void pstr(stack_t **stack, unsigned int line_number)
{

	stack_t *temp;

	(void)line_number;
	temp = *stack;

	if (!temp)
	{
		printf("\n");
		return;
	}

	while (temp && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", (char)temp->n);
		temp = temp->next;
	}
	printf("\n");
}
/**
 * rotl - rotates the stack to the top.
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *top, *second;
	size_t len;

	if (stack)
	{
		len = stack_len(*stack);
		if (len == 2)
			swap(stack, line_number);
		if (len > 2)
		{
			last = *stack;
			while (last->next)
				last = last->next;
			top = *stack;
			second = top->next;
			second->prev = NULL;
			*stack = second;

			top->next = NULL;
			top->prev = last;

			last->next = top;
		}
	}
}

/**
 * rotr - rotates the stack to the top.
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *top;
	size_t len;

	if (stack)
	{
		len = stack_len(*stack);
		if (len == 2)
			swap(stack, line_number);
		if (len > 2)
		{
			top = *stack;
			last = *stack;
			while (last->next)
				last = last->next;

			top->prev = last;
			(last->prev)->next = NULL;
			last->prev = NULL;
			last->next = top;
			*stack = last;

		}
	}
}
