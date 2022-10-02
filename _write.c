#include "main.h"
/**
 * prompt_icon - Writes using the system call writes
 *
 * Return: void
 */
void prompt_icon(void)
{
	char *prompt = "( ˘︹˘ ) ";
	int prompt_length = lengthcounter(prompt);
	int _write_return;

	_write_return = write(STDOUT_FILENO, prompt, prompt_length);
	if (_write_return == (-1))
	{
		perror("Error: ");
			exit(1);
	}
}
/**
 * _write_to_STDOUT - write to Stdout
 *
 * @_input: takes input to print
 *
 * Return: void
 */
void _write_to_STDOUT(char *_input)
{
	int _check_write_return;
	int std_length = lengthcounter(_input);
	int newlinelength = lengthcounter("\n");

	_check_write_return = write(STDOUT_FILENO, _input, std_length);
	if (_check_write_return == (-1))
	{
		perror("Error: ");
		exit(1);
	}
	write(STDOUT_FILENO, "\n", newlinelength);
}
