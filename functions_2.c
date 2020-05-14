#include "monty.h"
/**
 * add_func - adds the top two elements of the stack.
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void add_func(stack_t **stack, unsigned int line)
{
	int result;
	(void) stack;
	(void) line;


	if (head == NULL || head->next == NULL)
		printf("error");

	if (head->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	head = head->next;
	result = head->n + head->prev->n;
	head->n = result;
	free(head->prev);
	head->prev = NULL;
}
/**
 * nop_func - Do nothing
 * @stack: Head of the list
 * @line_number: line of file
 * Return: Nothing
 */
void nop_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub_func - adds the top two elements of the stack.
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void sub_func(stack_t **stack, unsigned int line)
{
	int result;
	(void) stack;
	(void) line;


	if (head == NULL || head->next == NULL)
		printf("error");

	if (head->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	head = head->next;
	result = head->n - head->prev->n;
	head->n = result;
	free(head->prev);
	head->prev = NULL;
}