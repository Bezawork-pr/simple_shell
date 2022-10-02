#include "main.h"
/**
 * separator_getline - separates string
 *
 * @argv: Takes commands with argument
 *
 * @string: string from the get function
 *
 * Return: void
 */
void separator_getline(char *argv[], char *string)
{
	char **temp = argv;
	char *piece = strtok(string, " ");

	while (piece != NULL)
	{
		*temp++ = piece;
		piece = strtok(NULL, " ");
	}
}
/**
 * separator_PATH - separates path provided
 * by the PATH envp variable
 *
 * @list: save different directory paths
 * separately
 *
 * @path: this is direct copy from PATH
 * envp varaible before separation of different
 * paths
 *
 * Return: void
 */
void separator_PATH(char *list[], char *path)
{
	char **temp = list;
	char *piece = strtok(path, ":");

	while (piece != NULL)
	{
		*temp++ = piece;
		piece = strtok(NULL, ":");
	}
}
