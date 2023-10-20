#include "shell.h"
/**
 * new_help - help builtin command
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */

void display_custom_help(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (vars->array_tokens[1] == NULL)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/help";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			put_error_message("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			display_custom_message("\n");
			if (r == -1)
			{
				put_error_message("Fatal Error");
				return;
			}
		}
		free(s);
		fd = close(fd);
		return;
	}
	else
		display_help_for_help(vars);
}

/**
 * display_help_for_help - help builtin command help
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void display_help_for_help(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (reverse_string_compare(vars->array_tokens[1], "help") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/help_help";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			put_error_message("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			display_custom_message("\n");
			if (r == -1)
			{
				put_error_message("Fatal Error");
				return;
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		display_help_for_exit(vars);
}

/**
 * display_help_for_exit - it help builtin command exit
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void display_help_for_exit(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (reverse_string_compare(vars->array_tokens[1], "exit") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/exit";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			put_error_message("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			display_custom_message("\n");
			if (r == -1)
			{
				put_error_message("Fatal Error");
				return;
			}
		}
		free(s);
		fd = close(fd);
	}

	else
		display_help_for_change_directory(vars);
}
/**
 * display_help_for_change_directory - help builtin command
 * change directory
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void display_help_for_change_directory(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (reverse_string_compare(vars->array_tokens[1], "cd") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/cd";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			put_error_message("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			display_custom_message("\n");
			if (r == -1)
			{
				put_error_message("Fatal Error");
				return;
			}
		}
		free(s);
		fd = close(fd);
	}

	else
		display_help_for_env(vars);
}
/**
 * display_help_for_env - help builtin command env
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void display_help_for_env(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (reverse_string_compare(vars->array_tokens[1], "env") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/env";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			put_error_message("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			display_custom_message("\n");
			if (r == -1)
			{
				put_error_message("Fatal Error");
				return;
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		display_help_for_history(vars);
}
