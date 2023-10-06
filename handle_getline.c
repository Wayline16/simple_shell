#include "main.h"

int alloc_line(char **pline, size_t *plsize, size_t newsize)
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
}
