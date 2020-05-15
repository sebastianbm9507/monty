#include "monty.h"

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
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	v = malloc(sizeof(var));
	if (v == NULL)
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
	v->fd = NULL;
	v->linestr = NULL;
	v->head = NULL;
	_open(argv[1]);
	free_nodes();
	free(v);
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
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_nodes();
		fclose(v->fd);
		free(v->linestr);
		free(v);
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

	if (v->head == NULL)
		return;

	while (v->head != NULL)
	{
		tmp = v->head;
		v->head = v->head->next;
		free(tmp);
	}
}
