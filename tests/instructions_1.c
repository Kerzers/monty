#include "monty.h"

/**
 * push - insert the element into the stack
 * @stack: reference to the header of a double linked list (stack)
 * @line_number: line number of the instruction
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->prev = NULL;
	if (!*stack)
	{
		*stack = new;
		new->next = NULL;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

/**
 * pal - prints all the values on the stack, starting from the top of the stack
 * @stack: reference to the header of a double linked list (stack)
 * @line_number: line number of the instruction
 * Return: nothing
 */
void pal(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 *
 *
 *
 */
void pint(stack_t **stack, unsigned int line_number);
{
	if (!*stack)
	{
		dprintf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
