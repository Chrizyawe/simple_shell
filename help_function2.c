#include "shell.h"

/**
 * display_help_for_alias - help builtin command alias
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void new_help_alias(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (reverse_string_compare(vars->array_tokens[1], "alias") == 0)
	{
		file = "/home/shell_test/shelltestenviroment/helpfiles/alias";
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
/**
 * display_help_for_other_commands -error message if not command found
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void display_help_for_other_commands(vars_t *vars)
{

	error_message(vars, ": no help topics match: `");
	put_error_message(vars->array_tokens[1]);

	put_error_message("'.  Try `help help' or `man -k ");
	put_error_message(vars->array_tokens[1]);
	put_error_message("' or `info ");
	put_error_message(vars->array_tokens[1]);
	put_error_message("'.");

	put_error_message("\n");
}
