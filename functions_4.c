#include "monty.h"
/**
 * rotl_func - top element of the stack becomes the last one,
 *  and the second top element of the stack becomes the first one
 * @stack: Head of the list
 * @line: line of file
 * Return: Nothing
 */
void rotl_func(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	/* go to last node 🔁 */
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
