#include "main.h"

/**
 * handle_comments - Checks if the string is a comment
 * @buffer: The string to check and fix a null byte at point of #
 * Return: Void
 */

void handle_comments(char *buffer)
{
	char *p = buffer;

	while (*p)
	{
		if (p > buffer && *p == '#' && *(p - 1) != ' ')
		{
			break;
		}
		if (*p == '#')
		{
			*p = '\0';
			break;
		}
		p++;
	}
}
