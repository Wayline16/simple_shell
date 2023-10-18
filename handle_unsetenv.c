#include "main.h"

/**
 * _unsetenv - unsets enviroment
 * @name: enviroment name to unset
 *
 * Return: execution status
 */
int _unsetenv(const char *name)
{
    size_t len;
    char **ep, **sp;
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
    {
        errno = EINVAL;
        return -1;
    }
    len = strlen(name);
    for (ep = environ; *ep != NULL;)
        if (strncmp(*ep, name, len) == 0 && (*ep)[len] == '=')
        {

            /* Remove found entry by shifting all successive entries
               back one element */

            for (sp = ep; *sp != NULL; sp++)
                *sp = *(sp + 1);

            /* Continue around the loop to further instances of 'name' */
        }
        else
            ep++;
    return 0;
}