#include "monty.h"
/**
 * pop_func - Removes the top node
 * @stack: Head of the list
 * @line: number of the line
 * Return: Nothing
 */
void pop_func(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;
	(void) line;
	/** Check for more than 1 node ✅*/
	if (temp->next != NULL)
	{
		head = head->next;
		head->prev = NULL;
	}
	else
		head = NULL;
	free(temp);
}
/**
 * push_func - Appends a node on top of list
 * @node: Node to be added
 * @line: number of the line
 * Return: Nothing
 */
void push_func(stack_t **node, unsigned int line)
{
	stack_t *temp;

	(void)line;
	if (node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	temp = head;
	head = *node;
	head->next = temp;
	temp->prev = head;
}
/**
 * pall_func - Print the list
 * @stack: Head of list
 * @line: number of the line
 * Return: Nothing
 */
void pall_func(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;
	(void)line;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint_func - Print the top element of list
 * @stack: Head of list
 * @line: number of the line
 * Return: Nothing
 */
void pint_func(stack_t **stack, unsigned int line)
{

	(void)line;
	if (!*stack)
	{
		printf("L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
/**
 * swap_func - swaps the top two elements of the stack.
 * @stack: Head of list
 * @line: number of the line
 * Return: Nothing
 */
void swap_func(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;
	(void)line;
	if (temp->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (temp->next->next == NULL)
	{
		head = temp->next;
		head->next = temp;
		head->prev = NULL;
		temp->next = NULL;
		temp->prev = head;
	}
	else
	{
		head = temp->next;
		temp->next = head->next;
		head->next->prev = temp;
		head->prev = NULL;
		head->next = temp;
		temp->prev = head;
	}
}


