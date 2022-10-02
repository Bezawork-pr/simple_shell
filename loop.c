#include "main.h"
/**
 * exittypes - user input exit type
 *
 * @argv: the commands
 *
 * @status: status from process
 *
 * @j: place of exit if exit is found
 *
 * Return: void but exits
 */

int exittypes(char *argv[], int status, int j)
{
	if ((j == 0) && (argv[j + 1] == NULL))
		return (0);
	if ((j == 0) && ((argv[1] != NULL) && (_is_digit(argv[1]) == 0)))
		return (_atoi(argv[j + 1]));
	if (_is_digit(argv[1]) == -1)
		return (2);
	if (_strcmp("exit", argv[0]) != 0)
		return (status);
	return (0);
}
/**
 * checkifexit - check if exit
 *
 * @argv: list of command
 *
 * Return: int
 */
int checkifexit(char *argv[])
{
	int i = 0;

	while (argv[i] != NULL)
	{
		if (_strcmp(argv[i], "exit") == 0)
			return (i);
		i++;
	}
	return (-1);
}
/**
 * checkifechocommand - check if the command
 * is a command like echo $$ or echo $?
 * or echo $environment
 *
 * @argv_here: takes commands and checks
 * if the command is echo + $$ or echo $?
 * or $environment
 *
 * Return: 0 if the comparisim matches
 * or 1 if it doesnot match
 */
int checkifechocommand(char *argv_here[])
{
	if ((_strcmp(argv_here[0], "echo") == 0) &&
			(_dollar_checker(argv_here[1]) == 0))
		return (0);
	return (1);
}
/**
 * environmentsetunset - set and unset environment
 *
 * @argv_here: takes arguments
 * and check using _strcmp if it is equivalent
 * to setenv or unset env
 * in which case it call the function setenv
 * or unsetenv and sets or unsets env
 *
 * Return: 0 if argv_here[0]is either setenv or unsetenv
 * otherwise (-1) if argv_here[0] is something else
 */
int environmentsetunset(char *argv_here[])
{
	if (_strcmp(argv_here[0], "setenv") == 0)
	{
		setenvironment(argv_here);
		return (0);

	}
	else if (_strcmp(argv_here[0], "unsetenv") == 0)
	{
		unsetenvironment(argv_here);
		return (0);
	}
	return (-1);
}
/**
 * loop - functions get called based on argument
 * get_stdin saves stdin from getline function
 *  if env typed by the user
 * env is printed
 * if pwd then copy_PWD is printed to STDOUT
 * if other  command is typed
 * and fork and exceve implement cmd
 * by iterating through paths provided by the PATH
 * envp element
 *
 * @envp: envp elements from main function argument
 * is passed here
 *
 * @copy_PATH : PATH copied from envp is saved in
 * this char * and passed here
 *
 * @copy_PWD: PWD copied from envp is saved in this char *
 * and passed here
 *
 * @get_stdin: stores from getline function
 *
 * @head: head of linked list containing env
 *
 * @tempforfindfile: temp var to store
 *
 * Return: void
 */
int loop(char *envp[], char *copy_PATH, char *copy_PWD,
		char *get_stdin, envir_t *head, char *tempforfindfile)
{
	char *buffercopy, *argv_here[100];
	int i, status = 0, m = 0;

	buffercopy = malloc(sizeof(char *) * 100);
	while (1)
	{
		for (i = 0; i < 100; i++)
			argv_here[i] = NULL;
		if (isatty(0))
			prompt_icon();
		get_stdin = _getline(buffercopy);
		if (lengthcounter(get_stdin) > 1)
		{
			if (_strcmp(get_stdin, "env") == 0)
				env(envp);
			else if (_strcmp(get_stdin, "pwd") == 0)
				_write_to_STDOUT(copy_PWD);
			else
			{
				separator_getline(argv_here, get_stdin);
				if (environmentsetunset(argv_here) == (0))
					continue;
				else if (_strcmp(argv_here[0], "cd") == 0)
					change_directory(argv_here, copy_PWD);
				else if (checkifechocommand(argv_here) == 0)
					echo_commands(head, argv_here, status);
				else if ((checkifexit(argv_here)) > (-1))
				{
					m = exittypes(argv_here, status, checkifexit(argv_here));
					free(buffercopy);
					return (m);
				}
				else
				{
					does_file_exist(copy_PATH, argv_here, tempforfindfile);
					status = _process(argv_here, copy_PATH, tempforfindfile);
				}
			}
		}
	}
}
