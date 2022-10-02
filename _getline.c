#include "main.h"
/**
 * mygetline_fn - replica of getline function
 *
 * @buffer : store results in
 *
 * Return: The line it got from the stdin
 */
void mygetline_fn(char *buffer)
{
	int rd;

	rd = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
	buffer[rd - 1] = '\0';
	if (rd == (-1))
	{
		if (isatty(0))
			perror("./shell");
		exit(1);
	}
}
/**
 * _getline - uses getline() function to get
 * user input
 * it changes nextline character received
 * from the getline functionto string null
 * terminator from getline() function
 *
 * @buffercopy: its where getline saves to
 *
 * Return: void
 */
char *_getline(char *buffercopy)
{
	char *buffer = NULL;
	size_t buff_size;
	int characters;
	int i = 0;

	characters = getline(&buffer, &buff_size, stdin);
	if (characters == (-1))
	{
		if (isatty(0))
		{
			perror("./shell");
			free(buffer);
			exit(1);
		}
		free(buffer);
		exit(0);
	}
	for (; buffer[i] != '\n'; i++)
	{
		buffercopy[i] = buffer[i];
	}
	buffercopy[i] = '\0';
	fflush(stdin);
	free(buffer);
	if (characters == 1)
		buffercopy = "";
	return (buffercopy);
}
