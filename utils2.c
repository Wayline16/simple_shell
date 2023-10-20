#include "main.h"

/**
 * flag_arraydelim - check in an array if delimiter found
 * @str: array to check
 * @delim: delimiter to search
 *
 * Return: 1 if found,2 if invalid delim ,0 otherwise
 */
int flag_arraydelim(char **str, char delim)
{
    int flag = 0, j = 0, k = 0;

    for (; str[j] != NULL; j++)
    {
        k = 0;
        while (str[j][k] != '\0')
        {
            if (str[j][k] == delim)
            {
                if (str[j][k + 1] == delim)
                {
                    flag = 2;
                    break;
                }
                else
                    flag = 1;
            }
            k++;
        }
    }
    return (flag);
}

/**
 * flag_delim - check in a string if delimiter found
 * @str: string to check
 * @delim: delimiter to search
 *
 * Return: 1 if found,2 if invalid delim ,0 otherwise
 */
int flag_delim(char *str, char delim)
{
    int flag = 0, j = 0;

    while (str[j] != '\0')
    {
        if (str[j] == delim)
        {
            if (str[j + 1] == delim)
            {
                flag = 2;
                break;
            }
            else
                flag = 1;
        }
        j++;
    }

    return (flag);
}

int _count_2dtokens(char **str, char *delim)
{
    int len = 0, count = 0, str_cnt = 0, i;
    char *token = NULL;
    char **token_cnt_cpy = NULL;

    if (str == NULL)
        return (count);
    while (str != NULL)
    {
        str_cnt++;
    }
    token_cnt_cpy = strdup2d(str);
    for (i = 0; i < str_cnt; i++)
    {
        token = strtok(token_cnt_cpy[i], delim);
        while (token)
    {
        count++;
        len += strlen(token);
        token = strtok(NULL, delim);
    }
    len++;
    }
    free(token_cnt_cpy);
    return (count + len);
}



char **strdup2d(char **str)
{
  int i, j;
  int num_strings = 0;
  char **new_str;

  while (str[num_strings] != NULL) {
    num_strings++;
  }

  new_str = malloc(sizeof(char *) * (num_strings + 1));
  if (new_str == NULL) {
    return NULL;
  }


  for (i = 0; i < num_strings; i++) {
    new_str[i] = strdup(str[i]);
    if (new_str[i] == NULL) {
      for (j = 0; j < i; j++) {
        free(new_str[j]);
      }
      free(new_str);
      return NULL;
    }
  }

  new_str[num_strings] = NULL;

  return new_str;
}

void free_3darray(char ***argslist)
{
    int i, j;
    for (i = 0; argslist[i] != NULL; i++)
    {
        for (j = 0; argslist[i][j] != NULL; j++)
        {
            free(argslist[i][j]);
        }
        free(argslist[i]);
    }
    free(argslist);
}