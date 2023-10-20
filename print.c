#include "shell.h"

void cee_print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
