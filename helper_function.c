#include "main.h"
/**
 * lengthcounter - counts the length
 *
 * @str: literal string
 *
 * Return: Length of string
 * without NULL terminator
 */
int lengthcounter(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strcmp - string compare function
 *
 * @f_string: First string
 *
 * @s_string: second string
 *
 * Return: -1 if they are not smilar
 * 0 if they are simlar
 */
int _strcmp(char *f_string, char *s_string)
{
	int i = 0;
	int f_length = lengthcounter(f_string);
	int s_length = lengthcounter(s_string);

	if (f_length != s_length)
	{
		return (-1);
	}
	while ((f_string[i] == s_string[i]) && (f_string[i] != '\0'))
	{
		i++;
	}
	if ((f_string[i] == '\0') && (s_string[i] == '\0'))
	{
		return (0);
	}
	return (-1);
}
/**
 * _strncpy_fromn - copies a string
 *
 * @dest: takes string
 *
 * @src: takes string
 *
 * @n: n states which index to start
 * copying from
 *
 * Return: pointer to dest char *
 */
char  *_strncpy_fromn(char *dest, char *src, int n)
{
	int i = n;
	int m = 0;

	for (; src[i] != '\0'; i++)
	{
		dest[m] = src[i];
		m++;
	}
	dest[m] = '\0';
	return (dest);
}
/**
 * _strcpy - copies the string pointed to by src
 *
 * @dest: to be copied to
 *
 * @src: To be copied from
 *
 * Return: copied is returned
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
		dest[i + 1] = '\0';
	}
	return (dest);
}
/**
 * _strcat- concats two string
 *
 * @list: char * to append to
 *
 * @executable: cmd to be appended to path
 * to find if the executable exist
 *
 * Return: void
 */
void _strcat(char *list, char *executable)
{
	int z, length;

	length = lengthcounter(list);
	for (z = 0; executable[z] != '\0'; z++)
	{
		list[z + length] = executable[z];
		list[z + length + 1] = '\0';
	}
}
