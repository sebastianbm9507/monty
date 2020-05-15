#include "monty.h"
/**
 * mul_fun - divs the top two elements of the stack.
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void div_fun(stack_t **stack, unsigned int line)
{
	int result;
	(void)line;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line);
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_fun - divs the top two elements of the stack.
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void mod_fun(stack_t **stack, unsigned int line)
{
	int result;
	(void)line;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line);
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
