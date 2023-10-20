#include "main.h"


#define more_lines 1024

#define more_chars 1024

void handle_file_test(int prgm_cnt, char **prog)
{
    FILE *fd;
    char **lines, **line_tok;
    char ***line_3dtok;
    char *token;
    char *errmsg;
    size_t i, new_size, total_lines = 0, total_chars = 0, j;
    char c;

    errno = 0;
    if (prgm_cnt > 1)
    {
        fd = fopen(prog[1], "r");
        if (fd == NULL)
        {
            errmsg = "Can't open";
            error_msg(0, NULL, prog[0], errmsg, prog[1], 2);
            exit(127);
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
        line_tok = malloc(sizeof(char *) * (100));
        j = 0;
        for (i = 0; i < total_lines; i++)
        {
            token = strtok(lines[i], "\n");

            while (token != NULL)
            {

                line_tok[j++] = token;
                token = strtok(NULL, "\n");
            }
        }
        line_tok[j] = NULL;
        line_3dtok = get_filetok(line_tok);
        free(line_tok);
        free_array(lines, total_lines);
        exe_files(line_3dtok, prog);
        free_3darray(line_3dtok);
        exit(errno);
    }
}

    char ***get_filetok(char **line)
    {
        char ***args_3darray;
        int num_rows = 0, i, j, k, m, num_colm = 4;
        char *tok;

        NOTUSED(m);
        NOTUSED(j);
        while (line[num_rows] != NULL)
        {
            num_rows++;
        }
        args_3darray = malloc((num_rows + 1)  * sizeof(char **));
        for (i = 0; i < num_rows; i++)
        {
            args_3darray[i] = malloc(num_colm * sizeof(char *));
        }

        k = 0;
        for (i = 0; i < num_rows; i++)
        {
            tok = strtok(line[i], " ");
            k = 0;
            while (tok != NULL)
            {
                args_3darray[i][k] = malloc(strlen(tok) + 1);
                strcpy(args_3darray[i][k], tok);
                k++;

                tok = strtok(NULL, " ");
            }
            args_3darray[i][k] = NULL;
        }
        args_3darray[i] = NULL;

        return (args_3darray);
    }

    void exe_files(char ***arglist, char **argv)
    {
        int x, y;
        char *fullcmd, *errmsg;

        NOTUSED(y);
        for (x = 0; arglist[x] != NULL; x++)
        {
            if (is_valid_full_path(arglist[x]) == 1)
            {
                multi_exec_full_path(arglist[x], argv);
            }
            else
            {

                fullcmd = get_full_path(arglist[x][0]);
                if (fullcmd == NULL)
                {
                    errmsg = ": not found";
                    error_msg(0, arglist[x][0], argv[0], errmsg, arglist[x][0], 0);
                    free_3darray(arglist);
                    errno = 127;
                    exit(127);
                }
                multi_exec_fullcmd(arglist[x], argv, fullcmd);
            }
        }

    }