#include "main.h"
/**
 * thefreer - frees malloc
 *
 * @copy_path_for_checkfile : to be freed
 *
 * @copycmd_typedbyuser: to be freed
 *
 * Return: void
 */
void thefreer(char *copy_path_for_checkfile, char *copycmd_typedbyuser)
{
	free(copy_path_for_checkfile);
	free(copycmd_typedbyuser);
}
/**
 * does_file_exist - check if file exist
 * it appends the cmd to different paths provided
 * by path which is copied from the environment
 * variable PATH and uses access function to find
 * if the file exist
 * or not
 *
 * @path: copy of path from the envp main function
 * argument
 *
 * @cmd: Gets the command picked by getline
 * and each command saved in array of pointers
 * by removing space using stktok function
 *
 * @tempforfindfile: temporary variable to store
 *
 * function updates right path for excve
 * Return: void
 */
void does_file_exist(char *path, char *cmd[], char *tempforfindfile)
{
	char *copy_path_for_checkfile, *list[100] = {NULL}, *append[100] = {NULL};
	char *slash = "/", **temp2 = cmd, *copycmd_typedbyuser;
	int m, i;

	copycmd_typedbyuser = malloc(sizeof(char *) * 100);
	copy_path_for_checkfile = malloc(sizeof(char *) * 100);
	_strcpy(copy_path_for_checkfile, path);
	_strcpy(copycmd_typedbyuser, cmd[0]);
	separator_PATH(list, copy_path_for_checkfile);
	if (_strcmp(copycmd_typedbyuser, "ls") == 0)
	{
		for (m = 0; list[m] != NULL; m++)
		{
			_strcpy(tempforfindfile, "");
			_strcpy(tempforfindfile, list[m]);
			_strcat(tempforfindfile, slash);
			_strcat(tempforfindfile, cmd[0]);
			append[m] = tempforfindfile;
		}
	}
	else if (_strcmp(copycmd_typedbyuser, "/bin/ls") == 0)
	{
		for (m = 0; list[m] != NULL; m++)
		{
			append[m] = cmd[0];

		}
	}
	for (i = 0; append[i] != NULL; i++)
	{
		if (access(append[i], F_OK) == 0)
		{
			thefreer(copy_path_for_checkfile, copycmd_typedbyuser);
			*temp2 = append[i];
			return;
		}
	}
	perror("Error");
	thefreer(copy_path_for_checkfile, copycmd_typedbyuser);
}

