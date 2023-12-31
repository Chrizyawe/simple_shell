#include "shell.h"

/**
 * duplicate_string - a function that duplicates a string
 * @str: the string to duplicate
 * Return: a pointer to the new string
 */
char *duplicate_string(char *str)
{
	char *dup;

	int a, len;

	if (str == 0)
	{
		return (0);
	}
	for (len = 0; str[len]; len++)
		;
	dup = malloc(sizeof(char) * (len + 1));

	for (a = 0; a <= len; a++)
	{
		dup[a] = str[a];
	}
	return (dup);
}
/**
 * reverse_string_compare - function that compares two strings
 * @str1: first string
 * @str2: second string
 * Return: Success (0)
 */
int reverse_string_compare(char *str1, char *str2)
{
	int a = 0;

	while (str1[a] == str2[a])
	{
		if (str1[a] == '\0')
			return (0);
		a++;
	}
	return (str1[a] - str2[a]);
}
/**
 * concatenate_strings - function that concatenates two strings
 * @str1: the first string
 * @str2: the second string
 * Return: the concatenated string
 */
char *concatenate_strings(char *str1, char *str2)
{
	char *newstr;
	unsigned int len2, len1, newlen, a, b = 0;

	if (str1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; str1[len1]; len1++)
			;
	}
	if (str2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; str2[len2]; len2++)
			;
	}
	newlen = len1 + len2 + 1;
	newstr = malloc(sizeof(char) * newlen);
	if (newstr == NULL)
		return (NULL);
	for (a = 0; a < len1; a++)
		newstr[a] = str1[a];
	for (b = 0; b < len2; b++)
		newstr[a + b] = str2[b];
	newstr[len1 + len2] = '\0';
	return (newstr);
}
/**
 * print_string - a function that prints a string
 * to the standard output
 * @str: the string
 * Return: the number of characters written or -1 if failed
 */
ssize_t print_string(char *str)
{
	ssize_t a, len;

	for (a = 0; str[a]; a++)
		;
	len = write(1, str, a);
	if (len != a)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}
/**
 * calculate_string_length - a function that returns the lenght of a string
 * @str: the string
 * Return: the lenght of the string
 */
int calculate_string_length(char *str)
{
	int a;

	if (str == NULL)
		return (0);
	for (a = 0; str[a] != '\0'; a++)
		;
	return (a);
}
