#include "main.h"
/**
 * echo_commands - three types of
 * echo commands are dealt here
 * echo $$
 * echo $?
 * echo $ plus enviornment variables
 *
 * @head: head of linkedlist where environment
 * varibales are stored
 *
 * @argv: commands with argument
 * listed separatedly as a char of pointers
 *
 * @status: get return status from
 * the process file
 *
 * Return: void
 */
void echo_commands(envir_t *head, char *argv[], int status)
{
	char *dest;
	pid_t pid = getpid();
	char *copystatus, *copypid, *valueofvar;
	int newlinelength = lengthcounter("\n");
	int length = 200, flag, i;

	flag = 0;
	valueofvar = malloc(sizeof(char *) * length);
	dest = malloc(sizeof(char *) * length);
	copystatus = malloc(sizeof(char *) * length);
	copypid = malloc(sizeof(char *) * length);

	for (i = 0; i < length; i++)
	{
		valueofvar[i] = '\0';
		dest[i] = '\0';
		copypid[i] = '\0';
		copystatus[i] = '\0';
	}

	_iota(status, copystatus);
	_iota((int)pid, copypid);
	_strncpy_fromn(dest, argv[1],  1);
	if  (_strcmp("$", dest) == 0)

	{
		write(STDOUT_FILENO, copypid, sizeof(copypid));
		write(STDOUT_FILENO, "\n", newlinelength);
	}
	else if (_strcmp("?", dest) == 0)
	{
		write(STDOUT_FILENO, copystatus, sizeof(copystatus));
		write(STDOUT_FILENO, "\n", newlinelength);
	}
	else if (get_environment(head, dest, valueofvar, flag) == 1)
		_write_to_STDOUT(valueofvar);
	free(dest);
	free(copypid);
	free(copystatus);
	free(valueofvar);
}
