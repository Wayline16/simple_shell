#include "main.h"

/*int alloc_line(char **pline, size_t *plsize, size_t newsize)
{
    void *n = realloc(*pline, newsize);
    if (n == NULL)
        return -1;
    *pline = n;
    *plsize = newsize;
    return 0;
}

ssize_t _getline(char **pline, size_t *plsize, FILE *fp)
{

    char *cur;
    char *ret;
    char *eod;
    size_t cursize;

    if (*plsize < 2)
        if (alloc_line(pline, plsize, 2))
            return -1;
    if (*pline == NULL)
        return -1;
    if (feof(fp))
        return -1;
    cur = *pline;
    cursize = *plsize;
    for (;;)
    {
        ret = fgets(cur, cursize, fp);
        if (ret == NULL && !feof(fp))
            return -1;
        if (ret == NULL && cur == *pline)
            return -1;
        eod = memchr(cur, '\0', cursize);
        if (feof(fp) || eod[-1] == '\n')
            return eod - *pline;

        cursize = *plsize + 1;
        if (alloc_line(pline, plsize, *plsize * 2))
            return -1;
        cur = *pline + *plsize - cursize;
    }
}*/
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