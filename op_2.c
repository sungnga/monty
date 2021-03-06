#include "monty.h"

/**
 * opcode_nop - does not perform the instruction
 * @stack: pointer to the address of node in stack_t list
 * @line_number: line number in the file
 * Return: nothing
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * opcode_add - adds top two elements of stack
 * @stack: pointer to address of stack
 * @line_number: line number
 * Return: void
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int result = 0;

	(void)line_number;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}

	result = current->n + current->next->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
	(*stack)->prev = NULL;
}

/**
 * opcode_sub - subtracts top two elements of stack
 * @stack: pointer to address of stack
 * @line_number: line number
 * Return: void
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int result = 0;

	(void)line_number;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}

	result = current->next->n - current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
	(*stack)->prev = NULL;
}

/**
 * opcode_mul - multiplies top two elements of stack
 * @stack: pointer to address of stack
 * @line_number: line number
 * Return: void
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int result = 0;

	(void)line_number;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}

	result = current->next->n * current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
	(*stack)->prev = NULL;
}
/**
 * opcode_div - divides top two elements of stack
 * @stack: pointer to address of stack
 * @line_number: line number
 * Return: void
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int result = 0;

	(void)line_number;
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}

	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", gl.ln);
		free_everything();
		exit(EXIT_FAILURE);
	}

	result = current->next->n / current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
	(*stack)->prev = NULL;
}
