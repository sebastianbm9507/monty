#include "monty.h"
/**
 * _open - Function to open the file and check file is accesible
 * @file: file to be open
 * Return: Nothing
 */
void _open(char *file)
{
	FILE *fd;

	if (access(file, R_OK) != 0)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	else
	{
		fd = fopen(file, "r");
		if (fd == NULL)
		{
			printf("Error: Can't open file %s\n", file);
			exit(EXIT_FAILURE);
		}
	/** Go to read the file 📄*/
	_readfile(fd);
	/* Close the file ❌*/
	fclose(fd);
	}
}
/**
 * _readfile - function to read the lines of the opened file
 * @fd: File descriptor of the file
 * Return: Nothing
 */
void _readfile(FILE *fd)
{
  /** read all the file */
	int line;
	char *linestr = NULL;
	size_t n;
	/* Go trough each line ⤵️ */
	for (line = 1; getline(&linestr, &n, fd) != EOF; line++)
		_read_lines(linestr, line);
	/** Free the line */
	free(linestr);
}
/**
 * _read_lines - Function to separate the line into tokens
 * @linesrt: Line of the file
 * @line: number of the line to read
 * Return: Nothing
 */
void _read_lines(char *linesrt, int line)
{
	char *opcode = NULL;
	char *value = NULL;

	opcode = strtok(linesrt, "\n ");
	if (opcode == NULL)
		return;
	value = strtok(NULL, "\n ");
	find_fn(opcode, value, line);
}
/**
 * find_fn - Function to choose the right function
 * depends of the opcode
 * @opcode: Opcode extracted from file
 * @val: value to insert
 * @line: number of the line to read
 * Return: Nothing
 */
void find_fn(char *opcode, char *val, int line)
{
	stack_t *node; /** variable to store the node ⏺ */
	int i, j; /** counter variables 🔀 */
	instruction_t list[] = {
	{"pop", pop_func}, {"push", push_func},	{"pall", pall_func}, {"pint",
	pint_func}, {"swap", swap_func}, {"add", add_func}, {"nop", nop_func}};
	/** go through the list to find the function 🔁*/
	for (i = 0; list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, list[i].opcode) == 0) /* Check if the opcode exist ✅ */
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (val == NULL)
				{
					printf("L%d: usage: push integer", line);
					exit(EXIT_FAILURE);
				}
				for (j = 0; val[j] != '\0'; j++)
				{
					if (isdigit(val[j]) == 0)
					{
						printf("L%d: usage: push integer\n", line);
						exit(EXIT_FAILURE);
					}
				}
				node = create_node(atoi(val)); /* Create node */
				node = node;
				list[i].f(&node, line);
				break;
			}
			else
			{
					list[i].f(&head, line);
					break;
			}
		}
	}
		if (list[i].opcode == NULL)
			printf("L%d: unknown instruction %s\n", line, opcode);
}
