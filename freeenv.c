#include "main.h"
/**
 * free_list - Free a list
 *
 * @head: list to free
 *
 * Return: void
 */
void free_list(envir_t *head)
{
	envir_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head->varname);
		free(head->value);
		free(head);
		head = temp;
	}
	free(head);
	head = NULL;
}
/**
 * freevar- frees var
 *
 * @dest: to be freed
 *
 * @copypid: to be freed
 *
 * @copystatus: to be freed
 *
 * @valueofvar: to be freed
 *
 * Return: void
 */
void freevar(char *dest, char *copypid, char *copystatus, char *valueofvar)
{
	free(dest);
	free(copypid);
	free(copystatus);
	free(valueofvar);
}
