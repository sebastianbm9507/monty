#include "monty.h"

/* global variable */
stack_t *head = NULL;
/**
 * main - Main function
 * @argc: int variable to handle number or arguments
 * @argv: Array of arguments
 * Return: Always 0
 */
int main(int argc, char **argv)
{
  /* checking argc has a valid number */
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_open(argv[1]);
	free_nodes();
	return (0);
}
/**
 * create_node - Creates a node.
 * @n: Value to the node
 * Return: On sucess -> pointer to the node. On failure  NULL.
 */
stack_t *create_node(int n)
{
	stack_t *new_node;


	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Node can't be created");
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;

	return (new_node);
}
/**
 * free_nodes - Function to free the list
 * Return: Nothing
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
