#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *custom_strtok(char *str, const char *delimiters)
{
    static char *nextToken = NULL;
    char *tokenStart;

    if (str != NULL)
    {
        nextToken = str;
    }

    if (nextToken == NULL || *nextToken == '\0')
    {
        return NULL; 
    }

    
    while (*nextToken != '\0' && strchr(delimiters, *nextToken) != NULL)
    {
        nextToken++;
    }

    if (*nextToken == '\0')
    {
        return NULL; 
    }

    tokenStart = nextToken;
    while (*nextToken != '\0' && strchr(delimiters, *nextToken) == NULL)
    {
        nextToken++;
    }

    if (*nextToken != '\0')
    {
        *nextToken = '\0';
        nextToken++;
    }

    return tokenStart;
}
