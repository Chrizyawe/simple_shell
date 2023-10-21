#include "shell.h"

/**
 * cee_print - to write in stdout
 * @string: The string to write
 */
void cee_print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
