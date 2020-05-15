#include "monty.h"
/**
 * div_func - divs the top two elements of the stack.
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void div_func(stack_t **stack, unsigned int line)
{
	int result, n1, n2;
	(void)line;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line);
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line);
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}

	n1 = (*stack)->n;
	n2 = (*stack)->next->n;
	result = n2 / n1;
	(*stack) = (*stack)->next;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_func - mod the top two elements of the stack.
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void mod_func(stack_t **stack, unsigned int line)
{
	int result, n1, n2;
	(void)line;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line);
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line);
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
		exit(EXIT_FAILURE);
	}
	n1 = (*stack)->n;
	n2 = (*stack)->next->n;
	result = n2 % n1;
	(*stack) = (*stack)->next;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
