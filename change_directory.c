#include "main.h"
/**
 * change_directory -- implementation cd command in c
 *
 * @argv: array of char pointers
 * commands and arguments saved in
 * an array of pointers
 *
 * @copy_PWD: saved from environment
 * variable passed here
 *
 * Return: void
 */

void change_directory(char *argv[], char *copy_PWD)
{
	char *buffer;

	buffer = malloc(sizeof(char *) * 100);
	if (getcwd(buffer, 1024) == NULL)
		perror("Error");
	if (chdir(argv[1]) == (-1))
		perror("Error");
	if (getcwd(buffer, 1024) == NULL)
		perror("Error");
	_strcpy(copy_PWD, buffer);
	_write_to_STDOUT(buffer);
	free(buffer);
}

