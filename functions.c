#include "shell.h"

/**
 * custom_string_compare - a function that compares two strings
 * @str1: First string
 * @str2: Second string
 * Return: 0 if strings match and 1 otherwise
 */
int custom_string_compare(char *str1, char *str2);
{
    int a;

    for (a = 0; str1[a] != '\0' && str2[a] != '\0'; a++)
    {
        if (str1[a] != str2[a])
        {
            return (str1[a] - str2[a]);
        }
    }
    if (str1[a] == '\0' && str2[a] == '\0')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
/**
 * handle_fatal_error - a function that handles fatal error
 * Return: void
 */

void handle_fatal_error(void);
{
	perror("Fatal Error");
	exit(100);
}
/**
 * print_error_message - a function that prints an error message if command not found
 * @argv: the name of the shell program
 * @command_count: An integer representing the number of commands running on the shell
 * @missing_command: A pointer to a string representing the command that was not found
 * Return: void
 */
void print_error_message(char *argv, int command_count, char *missing_command);
{
	print_str(argv, 1);
	print_str(": ", 1);
	print_number(command_count);
	print_str(": ", 1);
	print_str(missing_command, 1);
}
/**
 * handle_execution_error - a function that handles execution errors
 * @argv: the name of the shell program
 * @command_count: An integer representing the number of commands running on the shell
 * @failed_command: A pointer to a string representing the command that failed
 */
void handle_execution_error(char *argv, int command_count, char *failed_command);
{
	print_error(argv, command_count, failed_command);
	print_str(": ", 1);
	perror("");
	exit(1);
}
/**
 * print_custom_string - a function that prints a string character by character
 * @str: A pointer to a string to be printed
 * @newline:  An integer parameter; if it's equal to 0, a newline character is printed after the string
 * Return: void
 */
void print_custom_string(char *str, int newline);
{
	int a;

	if (str == NULL)
		str = "(null)";
	for (a = 0; str[a] != '\0'; a++)
	{
		write(STDOUT_FILENO, &str[a], 1);
	}
	if (newline == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
	}
}
