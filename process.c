#include "main.h"
/**
 * wait_fun - wait for process to end
 *
 * @pid: pid of the process we are waiting for
 *
 * @child_count: number of children to wait
 *
 * @returnStatus: This is the return status of the
 * process
 *
 * @copyforhash: copy for checking with strcmp
 *
 * Return: return status
 */
int wait_fun(pid_t pid, int child_count, int returnStatus, char *copyforhash)
{
	free(copyforhash);
	if (child_count)
	{
		child_count--;
		waitpid(pid, &returnStatus, 0);
	}
	return (returnStatus);
}
/**
 * _process - comand implementation area
 * takes single commands
 * multiple commands
 * ignores comments
 * and return exit status of process
 *
 * @envp: environment
 *
 * @argv: command with arguments
 * are passed to the _process function
 *
 * @path: PATH
 *
 * @tempforfindfile: temp variable
 *
 * Return: return Status of most
 * recent process
 *
 */
int _process(char *argv[], char *path, char *tempforfindfile)
{
	int returnStatus = 0, hash_flag = 0, first_element = 0;
	int comment = 0, i = 0, child_count = 0, result = 0, flag = 0;
	pid_t pid;
	char *copyforhash;

	copyforhash = malloc(sizeof(char *) * 104);
	for (i = 0; argv[i] != NULL; i++)
	{
		_strcpy(copyforhash, argv[i]);
		if (_hash_checker(copyforhash) == 0)
			comment = 1;
		if ((_strcmp(";", argv[i]) == 0) || (argv[i + 1] == NULL) ||  (comment == 1))
		{
			(_strcmp(";", argv[i]) == 0) ? argv[i] = NULL : argv[i];
			if (comment == 1)
			{
				hash_flag = 1;
				if (argv[i - 1] == NULL)
					break;
				argv[i] = NULL;
			}
			if (flag == 1)
				does_file_exist(path, &argv[first_element], tempforfindfile);
			pid = fork();
			(pid > 0) ? child_count++ : child_count;
			if (pid < 0)
				break;
			else if (pid == 0)
			{
				result = execve(argv[first_element], argv + first_element, NULL);
				if (result < 0)
					break;
			}
			flag = 1;
			first_element = i + 1;
			if (hash_flag == 1)
				break;
		}
	}
	return (wait_fun(pid, child_count, returnStatus, copyforhash));
}
