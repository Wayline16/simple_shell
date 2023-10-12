#include "main.h"


size_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char *buffer;
	static size_t bufsize = 1024;
	static size_t pos;
	ssize_t nread, i;

	if (buffer == NULL)
		buffer = malloc(bufsize * sizeof(char));
	while ((nread = read(fileno(stream), buffer + pos, bufsize - pos)) > 0)
	{
		for (i = 0; i < nread; i++)
		{
			if (buffer[pos + i] == '\n')
			{
				buffer[pos + i] = '\0';
				*lineptr = buffer;
				*n = pos + i + 1;
				return (pos + i + 1);
			}
		}
		pos += nread;
		if (pos == bufsize)
		{
			bufsize *= 2;
			buffer = realloc(buffer, bufsize * sizeof(char));
		}
	}
	if (nread == 0)
	{
		errno = EINVAL;
		return (-1);
	}
	if (nread < 0)
	{
		errno = EINVAL;
		return (-1);
	}
	buffer[pos] = '\0';
	*lineptr = buffer;
	*n = pos + 1;
	return (pos + 1);
}