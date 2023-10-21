#include "shell.h"
/**
 * count_tokens - a function used for counting token
 * @str: the string
 * @delim: the delimiter
 * Return: number of tokens
 */
int count_tokens(char *str, const char *delim)
{
	char *string, *token;
	int a;

	string = duplicate_string(str);
	if (string == NULL)
		return (-1);
	token = custom_strtok(string, delim);
	for (a = 0; token != NULL; a++)
		token = custom_strtok(NULL, delim);
	free(string);
	return (a);
}
/**
 * tokenize_string - a function that tokenizes
 * a buffer with a delimiter
 * @buf: the buffer to tokenize
 * @delim: the delimiter to use to tokenize
 * Return: a pointer to an array of pointers to the tokens
 */
char **tokenize_string(char *buf, char *delim)
{
	char **tokens = NULL;
	size_t a = 0, count = 10;

	if (buf == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * count);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[a] = custom_strtok(buf, delim)) != NULL)
	{
		a++;
		if (a == count)
		{
			tokens = resize_and_allocate(tokens, &count);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buf = NULL;
	}
	return (tokens);
}
/**
 * tokenize_child_string - tokenizes a buffer to use just for the child process
 * @buf: buffer to tokenize
 * @delim: the delimiter
 * @num_token: number of token
 * Return: a point to an array of pointers to the tokens
 */
char **tokenize_child_string(int num_token, char *buf, const char *delim)
{
	int a;
	char **buffer;
	char *token, *line_cp;

	line_cp = duplicate_string(buf);
	buffer = malloc(sizeof(char *) * (num_token + 1));
	if (buffer == NULL)
		return (NULL);
	token = custom_strtok(line_cp, delim);
	for (a = 0; token != NULL; a++)
	{
		buffer[a] = duplicate_string(token);
		token = custom_strtok(NULL, delim);
	}
	buffer[a] = NULL;
	free(line_cp);
	return (buffer);
}
/**
 * token_interface - token interface
 * @buf: the buffer to be tokenized
 * @delim: the delimiter
 * @num_token: the number of tokens
 * Return: tokens
 */
char **token_interface(char *buf, const char *delim, int num_token)
{
	vars_t vars;

	num_token = count_tokens(buf, delim);
	if (num_token == -1)
	{
		free(buf);
		return (NULL);
	}
	vars.array_tokens = tokenize_child_string(num_token, buf, delim);
	if (vars.array_tokens == NULL)
	{
		free(buf);
		return (NULL);
	}

	return (vars.array_tokens);
}
