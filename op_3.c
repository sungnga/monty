#include "monty.h"

/**
 * opcode_mod - computes the rest of the division of top two elements of stack
 * @stack: pointer to address of stack
 * @line_number: line number
 * Return: void
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int result = 0;

	(void)line_number;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}

	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}

	result = current->next->n % current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
	(*stack)->prev = NULL;
}

/**
 * opcode_pchar - prints the char at the top of the stack
 * @stack: pointer to address of stack
 * @line_number: line number
 * Return: void
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	 stack_t *current;

	(void)line_number;
	current = *stack;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}
	else if (current->n < 0 || current->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", current->n);
}

/**
 * opcode_pstr - prints string starting with top of stack until stack is empty
 * @stack: pointer to address of stack
 * @line_number: line number
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;
	if (current == NULL)
	{
		printf("\n");
		return;
	}
	while (current && current->n != 0 && current->n > 0 && current->n < 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * opcode_rotl - rotates stack to the top
 * @stack: pointer to address of stack
 * @line_number: line number
 */
void opcode_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;

		while (temp->next)
			temp = temp->next;

		temp->next = (*stack)->prev;
		(*stack)->prev->next = NULL;
		(*stack)->prev->prev = temp;
		(*stack)->prev = NULL;
	}
}

/**
 * opcode_rotr - rotates stack to bottom
 * @stack: pointer to address to stack
 * @line_number: line number
 */
void opcode_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		temp = *stack;

		while (temp->next->next)
			temp = temp->next;

		temp->next->next = *stack;
		(*stack)->prev = temp->next;
		*stack = temp->next;
		(*stack)->prev = NULL;
		temp->next = NULL;
	}
}
