#include "main.h"

/**
 *	_get_args - extracts the arguments.
 *	@line: string containing arguments.
 *	@delim: the delimeter.
 *
 *	Return: array of arguments.
 */
char **get_args(char *line) {
    const char *delim = " \n";
    char **args = NULL;
    int size_tokens = 0;
    int i = 0;
    
    char *token = custom_strtok(line, delim);
    
    while (token != NULL) {
        size_tokens++;
        token = custom_strtok(NULL, delim);
    }
    
    args = malloc(sizeof(char *) * (size_tokens + 1));
    if (args == NULL) {
        return NULL;
    }
    
    token = custom_strtok(line, delim);
    
    while (token != NULL) {
        
        args[i] = malloc(strlen(token) + 1);
        if (args[i] == NULL) {
            
            return NULL;
        }
       
        strcpy(args[i], token);
        
        i++;
        token = custom_strtok(NULL, delim);
    }
    
    args[i] = NULL;
    
    return args;
}


size_t strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}


char *strcpy(char *dest, const char *src) {
    char *dest_start = dest;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest_start;
}
