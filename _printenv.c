#include "main.h"
/**
 * _copy_varname - copies varname from envp
 *
 * @dest: to be copied to
 *
 * @src: whole of envvar with
 * value to be copied from
 *
 * Return: char pointer to dest
 */
char  *_copy_varname(char *dest, char *src)
{
	int m = 0;

	for (; src[m] != '='; m++)
	{
		dest[m] = src[m];
	}
	dest[m] = '\0';
	return (dest);
}
/**
 * copyfrom - locates char after =
 *
 * @str: environment variable with
 * value
 *
 * Return: index of char after =
 */
int copyfrom(char *str)
{
	int i = 0;

	while (str[i] != '=')
	{
		i++;
	}
	return (i + 1);
}
/**
 * addheadnotnull - Add new node when head is not null
 *
 * @head: head of linked list
 *
 * @environment: specific envp got from main function
 *
 * @temp: temp variable to point head to when inserting
 * new node
 *
 * Return: void
 */
void addheadnotnull(envir_t **head, char *environment, envir_t *temp)
{
	envir_t *new = malloc(sizeof(struct envir_s) * 400);

	(new->varname) = malloc(sizeof(char *) * 200);
	(new->value) = malloc(sizeof(char *) * 200);
	if ((new == NULL) || (temp == NULL))
	{
		free(new->varname);
		free(new->value);
		free(new);
		/*new = NULL;*/
		perror("Error");
		return;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	(new->next) = NULL;
	_copy_varname((new->varname), environment);
	if (_strcmp("LS_COLORS", (new->varname)) != 0)
		_strncpy_fromn((new->value), environment, copyfrom(environment));
	else
		_strncpy_fromn((new->value), environment, 10);

}
/**
 * addheadwhennull - Add new node to head when head is NULL
 *
 * @head: head of linked list
 *
 * @environment: specific environment variable
 *
 * Return: void
 */
void addheadwhennull(envir_t **head, char *environment)
{
	envir_t *new = malloc(sizeof(struct envir_s) * 400);

	(new->varname) = malloc(sizeof(char *) * 200);
	(new->value) = malloc(sizeof(char *) * 200);

	if (new == NULL)
	{
		free(new->varname);
		free(new->value);
		free(new);
		/*new = NULL;*/
		perror("Error");
		return;
	}
	*head = new;
	(new->next) = NULL;
	_copy_varname((new->varname), environment);
	_strncpy_fromn((new->value), environment, copyfrom(environment));
}
/**
 * get_environment - gets environment value based on environment name
 *
 * @head: head of linked list
 *
 * @varname: the varname entered by user
 *
 * @valueofvar: copy the value of head->value here
 *
 * @flag: if the environment varaible is found
 * change the flag to 1
 * flag = 0 if env is not found
 *
 * Return: flag
 */
int get_environment(envir_t *head, char *varname, char *valueofvar, int flag)
{
	while (head != NULL)
	{
		if ((_strcmp(((head)->varname), varname)) == 0)
		{
			_strcpy(valueofvar, ((head)->value));
			flag = 1;
			return (flag);
		}
		head = (head)->next;
	}
	return (flag);
}
