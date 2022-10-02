#include "main.h"
/**
 * copy_from_envp - copies PATH from the envp varaible
 * and also pwd
 *
 * @copy_PATH: Destination char * to copy PATH into
 *
 * @copy_PWD: Destination char * to copy PWD into
 *
 * @envp: takes envp
 *
 * Return: void
 */
void copy_from_envp(char *copy_PATH, char *copy_PWD, char *envp[])
{
	int m, i = 0;

	for (; envp[i] != NULL; i++)
	{
		for (m = 0; envp[i][m] != '\0'; m++)
		{
			if (((envp[i][m] == 'P') && m == 0) &&
			(envp[i][m + 1] == 'A') &&
			(envp[i][m + 2] == 'T') &&
			(envp[i][m + 3] == 'H'))
			{
				_strncpy_fromn(copy_PATH, envp[i], 5);
				break;
			}
			if (((envp[i][m] == 'P') && m == 0) &&
			(envp[i][m + 1] == 'W') &&
			(envp[i][m + 2] == 'D'))
			{
				_strncpy_fromn(copy_PWD, envp[i], 4);
				break;
			}
		}
	}
}
/**
 * env - prints the envp elements
 *
 * @envp: Takes argument from
 * main function envp
 *
 * Return: void
 */
void env(char *envp[])
{
	int i = 0;

	for (; envp[i] != NULL; i++)
	{
		_write_to_STDOUT(envp[i]);
	}
}
/**
 * setenvironment - set env
 *
 * @argv: receive args
 *
 * Return: void
 */
void setenvironment(char *argv[])
{
	int result;

	result = setenv(argv[1], argv[2], 1);
	if (result == (-1) && isatty(0))
		perror("./shell");
}
/**
 * unsetenvironment - unsets environment
 *
 * @argv: gets input from user
 *
 * Result: void
 */
void unsetenvironment(char *argv[])
{
	int result;

	result = unsetenv(argv[1]);
	if (result == (-1) && isatty(0))
		perror("./shell");
}
