#include "main.h"

int _setenv(const char *name, const char *value, int overwrite)
{
    char *es;
    int i;

    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL ||
        value == NULL)
    {
        errno = EINVAL;
        return -1;
    }
    es = getenv(name);
    for (i = 0; environ[i] != NULL; i++)
    {
        if (environ[i] == es)
        {
            break;
        }
    }
    if (overwrite || es == NULL)
    {
        es = malloc(strlen(name) + strlen(value) + 2);
        if (es == NULL)
        {
            errno = ENOMEM;
            return -1;
        }

        strcpy(es, name);
        strcat(es, "=");
        strcat(es, value);

        environ[i] = es;
        environ[i + 1] = NULL;
    }
    return 0;
}