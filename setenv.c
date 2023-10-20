#include "shell.h"

/**
 * add_new_variable - a function that creates a new environment variable
 * @vars: pointer to a struct of variables
 * Return: void
 */
void add_new_variable(vars_t *vars)
{
	unsigned int a;
	char **newenv;

	for (a = 0; vars->env[a] != NULL; a++)
		;
	newenv = malloc(sizeof(char *) * (a + 2));
	if (newenv == NULL)
	{
		error_message(vars, NULL);
		vars->status = 127;
		exit_shell(vars);
	}
	for (a = 0; vars->env[a] != NULL; a++)
		newenv[a] = vars->env[a];
	newenv[a] = add_value_to_key(vars->array_tokens[1], vars->array_tokens[2]);
	if (newenv[a] == NULL)
	{
		error_message(vars, NULL);
		free(vars->buffer);
		free(vars->commands);
		free(vars->array_tokens);
		free_env(vars->env);
		free(newenv);
		exit(127);
	}
	newenv[a + 1] = NULL;
	free(vars->env);
	vars->env = newenv;
}
/**
 * find_env_key - a function that finds an environmental variable
 * @env: array of environmental variables
 * @key: the variable to find
 * Return: a pointer to the address of the environmental variable
 */

char **find_env_key(char **env, char *key)
{
	unsigned int a, b, len;

	len = calculate_string_length(key);
	for (a = 0; env[a] != NULL; a++)
	{
		for (b = 0; b < len; b++)
		{
			if (key[b] != env[a][b])
			{
				break;
			}
		}
		if (b == len && env[a][b] == '=')
			return (&env[a]);
	}
	return (NULL);
}
/**
 * add_value_to_key - a function that creates a new environment
 * variable string
 * @key: the variable name to create
 * @value: the variable value
 * Return: a pointer to the new string
 */
char *add_value_to_key(char *key, char *value)
{
	unsigned int len1, len2, a, b;
	char *new;

	len1 = calculate_string_length(key);
	len2 = calculate_string_length(value);
	new = malloc(sizeof(char) * (len1 + len2 + 2));
	if (new == NULL)
		return (NULL);
	for (a = 0; key[a] != '\0'; a++)
		new[a] = key[a];
	new[a] = '=';
	for (b = 0; value[b] != '\0'; b++)
		new[a + 1 + b] = value[b];
	new[a + 1 + b] = '\0';
	return (new);
}
/**
 * resize_and_allocate - a function that reallocates
 * a pointer to double the space
 * @ptr: pointer to the old array
 * @size: pointer to the number of elements in the old array
 * Return: pointer to the new array
 */
char **resize_and_allocate(char **ptr, size_t *size)
{
	char **new;
	size_t a;

	new = malloc(sizeof(char *) * ((*size) + 10));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (a = 0; a < (*size); a++)
	{
		new[a] = ptr[a];
	}
	*size += 10;
	free(ptr);
	return (new);
}
