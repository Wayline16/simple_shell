#include "main.h"


#define more_lines 1024

#define more_chars 1024

int handle_file_test(char **args, char *prog)
{
    FILE *fd;
    char **lines;
    char *token;
    size_t i, new_size, total_lines = 0, total_chars = 0;
    char c;
    int exe = 0;

    NOTUSED(prog);

    if (strcmp(args[0], "shell") == 0)
    {
        fd = fopen(args[1], "r");
        if (fd == NULL)
        {
            perror("failed open");
            return -1;
        }

        lines = malloc(sizeof(char *) * more_lines);
        do
        {
            c = fgetc(fd);
            if (ferror(fd))
            {
                printf("error reading\n");
            }

            if (feof(fd))
            {
                if (total_chars != 0)
                {
                    lines[total_lines] = realloc(lines[total_lines], total_chars + 1);
                    lines[total_lines][total_chars] = '\0';

                    total_lines++;
                }
                break;
            }

            if (total_chars == 0)
            {
                lines[total_lines] = malloc(more_chars);
            }
            lines[total_lines][total_chars] = c;
            total_chars++;
            if (c == '\n')
            {
                lines[total_lines] = realloc(lines[total_lines], total_chars + 1);
                lines[total_lines][total_chars] = '\0';

                total_lines++;
                total_chars = 0;

                if (total_lines % more_lines == 0)
                {
                    new_size = total_lines + more_lines;
                    lines = realloc(lines, sizeof(char *) * new_size);
                }
            }
            else if (total_chars % more_chars == 0)
            {
                new_size = total_chars + more_chars;
                lines[total_lines] = realloc(lines[total_lines], new_size);
            }

        } while (1);

        lines = realloc(lines, sizeof(char *) * total_lines);

        fclose(fd);

        for (i = 0; i < total_lines; i++)
        {
            token = strtok(lines[i], "\n");

            while (token != NULL)
            {

                printf("%s\n", token);
                token = strtok(NULL, "\n");
            }
        }

        for (i = 0; i < total_lines; i++)
        {
            free(lines[i]);
        }

      exe = 1;
    }
    return (exe);
}