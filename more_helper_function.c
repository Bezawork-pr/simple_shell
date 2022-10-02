#include "main.h"
/**
 * _hash_checker - checks if first letter is hash
 *
 * @f_char : copies argv_here to check if the first letter is hash
 *
 * Return: 0 if Hash otherwise (-1)
 */
int _hash_checker(char *f_char)
{

	if (f_char[0] == 35)
	{
		return (0);
	}
	return (-1);
}
/**
 * _dollar_checker - checks if first letter is dollar sign
 *
 * @f_char: copies argv_here to check if first letter is dollar
 *
 * Return: 0 if it matches
 * Otherwise -1 if first letter  is not dollar sign
 */
int _dollar_checker(char *f_char)
{

	if (f_char[0] == 36)
	{
		return (0);
	}
	return (-1);
}
/**
 * _iota - changes int to char *
 *
 * @value: int value to be changed
 *
 * @numberArray: save int here after change
 *
 * Return: void
 */
void _iota(int value, char *numberArray)
{
	int n = value;
	int num = value;
	int count = 0;

	if (n == 0)
	{
		numberArray[0] = 0 + '0';
		numberArray[1] = '\0';
		return;
	}
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	numberArray[count] = '\0';
	while (n != 0)
	{
		numberArray[count] = (n % 10) + '0';
		n /= 10;
		count--;

	}
}
/**
 * _atoi - change string to int
 *
 * @string: string to be changed
 *
 * Return: int change of string
 */
int _atoi(char *string)
{
	int result = 0, sign = 1, i = 0;

	if (string[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; string[i] != '\0'; i++)
		result = result * 10 + string[i] - '0';
	return (sign * result);
}
/**
 * _is_digit - is the char digit
 *
 * @string: string to be checked
 *
 * Return: 0 if true or -1 if not
 */
int _is_digit(char *string)
{
	int i = 0;

	while (((string[i] >= '0') && (string[i] <= '9')) && (string[i] != '\0'))
		i++;
	if (i == lengthcounter(string))
		return (0);
	return (-1);
}
