#include "shell.h"

/**
 * change_directory - a function that changes the current working directory
 * @vars: the input parameter from the user
 * Return: void
 */
void change_directory(vars_t *vars)
{
	int index;

	if (vars->array_tokens[1] == NULL)
	{
		index = find_env_index(*vars, "HOME");
		chdir((vars->env[index]) + 5);
	}
	else if (reverse_string_compare(vars->array_tokens[1], "-") == 0)
		print_custom_string(vars->array_tokens[1], 0);
	else
		chdir(vars->array_tokens[1]);
}
/**
 * print_cd - function that handles prints error when cd argument is invalid
 * @vars: the parameter
 * Return: void
 */
void print_cd(vars_t *vars)
{
	print_custom_string("-bash: cd: ", 1);
	print_custom_string(vars->array_tokens[1], 1);
	print_custom_string(": invalid option", 0);
	print_custom_string("cd: usage: cd [-] [--]", 0);
}
/**
 * print_cd_2 - a function that prints error message
 * if cd argument doesnt exist
 * @vars: the variable parameter
 * Return: void
 */
void print_cd_2(vars_t *vars)
{
	print_custom_string("-bash: cd: ", 1);
	print_custom_string(vars->array_tokens[1], 1);
	print_custom_string(": Not a directory", 0);
}
