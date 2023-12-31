#include "shell.h"

/**
 * sig_handler - handles the control c signal interupt
 * @unused: unused variable (required for signal function prototype
 * Return: void
 */
static void sig_handler(int unused)
{
	(void)unused;
	if (signal_flag == 0)
		print_string("\n$ ");
	else
		print_string("\n");
}
/**
 * main - main function used to run the shell
 * @argc: the number of arguments passed
 * @argv: array of arguments passed to main
 * @environment:array of environment variables
 * Return: 0 for success
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t len_buffer = 0;
	unsigned int a;
	unsigned int is_pipe = 0;

	vars_t vars = {NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL};

	vars.argv = argv;
	vars.env = create_new_environment(environment);

	signal(SIGINT, sig_handler);

	if (!isatty(STDIN_FILENO))
		is_pipe = 1;
	if (is_pipe == 0)
		print_string("$ ");
	signal_flag = 0;

	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		vars.counter++;
		vars.commands = tokenize_string(vars.buffer, ";");
		for (a = 0; vars.commands && vars.commands[a] != NULL; a++)
		{
			vars.array_tokens = tokenize_string(vars.commands[a], " \t\r\n\a");
			if (vars.array_tokens && vars.array_tokens[0])
				if (check_builtin(&vars) == NULL)
				{
					execute_child_process(vars);
				}
			free(vars.array_tokens);
		}
		free(vars.buffer);
		free(vars.commands);
		if (is_pipe == 0)
			print_string("$ ");
		vars.buffer = NULL;
	}
	free_env(vars.env);
	free(vars.buffer);
	exit(vars.status);
}
/**
 * check_for_match - a function that checks if a character matches any in str
 * @c: character to check
 * @str: string to check for the character
 * Return: 1 if match and 0 if not match
 */
unsigned int check_for_match(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}
/**
 * custom_strtok - custom strtok function
 * @str: string to tokenize
 * @delim: delimter to tokenize with
 * Return: a pointer to the next token
 */
char *custom_strtok(char *str, const char *delim)
{
	static char *token_start;
	static char *next_token;
	unsigned int i;

	if (str != NULL)
		next_token = str;
	token_start = next_token;
	if (token_start == NULL)
		return (NULL);
	for (i = 0; next_token[i] != '\0'; i++)
	{
		if (check_for_match(next_token[i], delim) == 0)
			break;
	}
	if (next_token[i] == '\0' || next_token[i] == '#')
	{
		next_token = NULL;
		return (NULL);
	}
	token_start = next_token + i;
	next_token = token_start;
	for (i = 0; next_token[i] != '\0'; i++)
	{
		if (check_for_match(next_token[i], delim) == 1)
			break;
	}
	if (next_token[i] == '\0')
		next_token = NULL;
	else
	{
		next_token[i] = '\0';
		next_token = next_token + i + 1;
		if (*next_token == '\0')
			next_token = NULL;
	}
	return (token_start);
}
