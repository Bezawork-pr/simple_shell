#include "main.h"
/**
 * main - Entry point
 *
 * @argc: not going to use it
 *
 * @argv: not going to use it
 *
 * @envp: takes environment variables
 *
 * Return: type int : 0 on SUCCESS
 * and exit with FAILURE
 */
int main(
		int argc __attribute__((unused)),
		char *argv[] __attribute__((unused)),
		char *envp[]

		)
{
	char *copy_PATH, *copy_PWD, *get_stdin, *tempforfindfile;
	int i, m;
	envir_t *head = NULL;
	envir_t *temp;

	copy_PATH = malloc(sizeof(char *) * 50);
	copy_PWD = malloc(sizeof(char *) * 50);
	get_stdin = malloc(sizeof(char *) * 50);
	temp = malloc(sizeof(envir_t) * 100);
	tempforfindfile = malloc(sizeof(char *) * 100);
	if ((copy_PATH == NULL) || (copy_PWD == NULL) ||
			(get_stdin == NULL) || (temp == NULL) ||
			(tempforfindfile == NULL))
	{
		free(copy_PATH);
		free(copy_PWD);
		free(get_stdin);
		free(temp);
		free(tempforfindfile);
		perror("IT IS I");
		exit(1);
	}
	for (m = 0; envp[m] != NULL; m++)
	{
		if (head == NULL)
			addheadwhennull(&head, envp[m]);
		else
			addheadnotnull(&head, envp[m], temp);
	}
	copy_from_envp(copy_PATH, copy_PWD, envp);
	i = loop(envp, copy_PATH, copy_PWD, get_stdin, head, tempforfindfile);
	free(copy_PATH);
	free(copy_PWD);
	free(get_stdin);
	free(temp);
	free(tempforfindfile);
	free_list(head);
	exit(i);
	return (0);
}
