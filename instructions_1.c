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
	int data;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!atoi(instruct[1]) && strcmp(instruct[1], "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	data = atoi(instruct[1]);
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

	(void)line_number;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the stack
 * @stack: ...
 * @line_number: ...
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes element from a stack
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = current->next;
		(current->next)->prev = NULL;
		free(current);
	}
}

/**
 * swap - waps the top two elements of the stack.
 * @stack: the stack
 * @line_number: the line number we read from in the file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	size_t len = 0;
	stack_t *top = *stack, *second = NULL, *third = NULL;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{	second = top->next;
		if (len > 2)
		{
			third = second->next;
			third->prev = top;
		}
		second->next = top;
		second->prev = NULL;
		*stack = second;

		top->prev = second;
		top->next = NULL;
	}
}

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
