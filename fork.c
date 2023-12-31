#include "shell.h"

/**
 * execute_child_process - a function that creates a child in order to
 * execute another program
 * @vars: an array of pointers and a string
 * Return: void
 */
void execute_child_process(vars_t vars)
{
	pid_t id;
	int check, status;
	struct stat buf;
	char *temp_command, *command;

	id = fork();
	if (id != 0)
		wait(&status);
	else
	{
		temp_command = vars.array_tokens[0];
		command = find_executable_path(vars, vars.array_tokens[0]);
		if (command == NULL)
		{
			check = stat(temp_command, &buf);
			if (check == -1)
			{
				print_error_message(vars.argv[0], vars.counter, temp_command);
				print_custom_string(": not found", 0);

				exit(100);
			}
			command = temp_command;
		}
		vars.array_tokens[0] = command;
		if (vars.array_tokens[0] != NULL)
		{
			if (execve(vars.array_tokens[0], vars.array_tokens, vars.env) == -1)
				handle_execution_error(vars.argv[0], vars.counter, temp_command);
		}
	}
}
/**
 * find_executable_path - a function that acts as an interface for
 * functions that will be able to
 * find the full path of a program
 * @command: A common command such as ls, echo, pwd, etc..
 * @vars: structure with variables
 * Return: On success a string with the full path of the program
 */
char *find_executable_path(vars_t vars, char *command)
{
	char *str = "PATH";
	char *constructed;
	char **path_tokens;
	int index, a;
	char *dir;

	index = find_env_index(vars, str);
	path_tokens = tokenize_path_directories(vars, index, str);
	if (path_tokens == NULL)
		return (NULL);

	dir = search_directories(path_tokens, command);
	if (dir == NULL)
	{
		for (a = 0; path_tokens[a] != NULL; a++)
			free(path_tokens[a]);
		free(path_tokens);
		return (NULL);
	}
	constructed = generate_path(dir, command);
	if (constructed == NULL)
	{
		for (a = 0; path_tokens[a] != NULL; a++)
			free(path_tokens[a]);
		free(path_tokens);
		return (NULL);
	}
	for (a = 0; path_tokens[a] != NULL; a++)
		free(path_tokens[a]);
	free(path_tokens);
	return (constructed);
}
/**
 * tokenize_path_directories - a function that separates a string
 * of strings containing the path directories
 * @vars: a structure with variables
 * @idx: index of the path in the environment variables
 * @str: strings to separate and tokenize
 * Return: Null terminated array of strings
 */
char **tokenize_path_directories(vars_t vars, int idx, char *str)
{
	char *env_var;
	int token_count = 0, len;
	char **path_tokens;
	const char *delim = ":\n";

	len = calculate_string_length(str);

	env_var = vars.env[idx] + (len + 1);
	path_tokens = token_interface(env_var, delim, token_count);
	if (path_tokens == NULL)
		return (NULL);

	return (path_tokens);
}
/**
 * search_directories - for searching through directories specified in the PATH
 * environment variable to locate specified files
 * @path_tokens: a pointer to array of strings contained
 * in the PATH environment variable
 * @command: Represents a command
 * Return: a strings with the directory containing the command file
 */

char *search_directories(char **path_tokens, char *command)
{
	int a, b;
	char *cmd, *buf;
	size_t size;
	struct stat stat_buf;

	buf = NULL;
	size = 0;
	cmd = getcwd(buf, size);
	if (cmd == NULL)
		return (NULL);
	if (command[0] == '/')
		command = command + 1;
	for (a = 0; path_tokens[a] != NULL; a++)
	{
		b = chdir(path_tokens[a]);
		if (b == -1)
		{
			perror("ERROR!");
			return (NULL);
		}
		b = stat(command, &stat_buf);
		if (b == 0)
		{
			chdir(cmd);
			free(cmd);
			return (path_tokens[a]);
		}
	}
	chdir(cmd);
	free(cmd);
	return (NULL);
}
