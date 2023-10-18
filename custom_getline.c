#include "main.h"

/**
 * custom_getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 * Return: The number of bytes read.
 */
size_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
        static char *buffer;
        static size_t bufsize, pos;
        static ssize_t z, nread;

        if (buffer == NULL)
        {
                bufsize = 1024;
                buffer = malloc(bufsize * sizeof(char));
        }
        while ((nread = read(fileno(stream), buffer + pos, bufsize - pos)) > 0)
        {
                for (z = 0; z < nread; z++)
                {
                        if (buffer[pos + z] == '\n')
                        {
                                buffer[pos + z] = '\0';
                                *lineptr = buffer;
                                *n = pos + z + 1;
                                return (pos + z + 1);
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
        return (-1);
}
if (nread < 0)
{
        return (-1);
}
buffer[pos] = '\0';
*lineptr = buffer;
*n = pos + 1;
return (pos + 1);
}