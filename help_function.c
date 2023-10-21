#include "shell.h"
/**
 * display_help_for_history - help builtin command history
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void display_help_for_history(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (reverse_string_compare(vars->array_tokens[1], "history") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/history";
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
		display_help_for_unalias(vars);
}
/**
 * display_help_for_unalias - help builtin command unalias
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void display_help_for_unalias(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (reverse_string_compare(vars->array_tokens[1], "unalias") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unalias";
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
		display_help_for_unset(vars);
}
/**
 * display_help_for_unset - help builtin command unset
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void display_help_for_unset(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (reverse_string_compare(vars->array_tokens[1], "unset") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unset";
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
		display_help_for_unset_env(vars);
}
/**
 * display_help_for_unset_env - help builtin command unsetenv
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void display_help_for_unset_env(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (reverse_string_compare(vars->array_tokens[1], "unsetenv") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/unsetenv";
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
		display_help_for_set_env(vars);
}
/**
 * display_help_for_set_env - help builtin command setenv
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void display_help_for_set_env(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (reverse_string_compare(vars->array_tokens[1], "setenv") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/setenv";
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
		new_help_alias(vars);
}
