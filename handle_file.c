#include "main.h"

int handle_file(char **args, char *prog)
{
    int fd, exe = 0, i, status;
    char *buf = NULL;
    char *commands = NULL;
    int num_commands = 0;
    char **arg = NULL;
    int num_args = 0;
    char *ptr = NULL;
    int buffer_size, len;

struct stat st;
    NOTUSED(prog);
    if (strcmp(args[0], "shell") == 0)
    {
        fd = open(args[1], O_RDONLY);
        if (fd < 0)
        {
            perror("open");
            return 1;
        }



        if (fstat(fd, &st) < 0)
        {
            perror("fstat");
            return 1;
        }
        buffer_size = st.st_size;


        buf = malloc(buffer_size);
        if (buf == NULL)
        {
            perror("malloc");
            return 1;
        }


        len = read(fd, buf, buffer_size);
        if (len < 0)
        {
            perror("read");
            return 1;
        }


        if (len != buffer_size)
        {

            buffer_size = len;
            buf = realloc(buf, buffer_size);
            if (buf == NULL)
            {
                perror("realloc");
                return 1;
            }

            len += read(fd, buf + len, buffer_size - len);
            if (len < 0)
            {
                perror("read");
                return 1;
            }
        }


        close(fd);
        commands = malloc(1024);
        ptr = strtok(buf, "\n");
        while (ptr != NULL)
        {
            strcpy(commands + num_commands * 1024, ptr);
            num_commands++;
            ptr = strtok(NULL, "\n");
        }

        /*Execute each command.*/
        for (i = 0; i < num_commands; i++)
        {
            /*Create a child process.*/
            pid_t pid = fork();
            if (pid < 0)
            {
                perror("fork");
                return 1;
            }

            /*Child process.*/
            if (pid == 0)
            {
                /*Parse the command into arguments.*/
arg = malloc(1024 * sizeof(char *));
      if (arg == NULL) {
        perror("malloc");
        return 1;
      }
                ptr = strtok(commands + i * 1024, " ");
                while (ptr != NULL)
                {
                    arg[num_args++] = ptr;
                    ptr = strtok(NULL, " ");
                }

                /*Execute the command.*/
                execve(arg[0], arg, NULL);
                perror("execve");
                exit(1);
            }

            /*Parent process.*/
            else
            {
                /*Wait for the child process to finish.*/

                waitpid(pid, &status, 0);

                /*If the child process exited with a non-zero status, print an error message.*/
                if (status != 0)
                {
                    printf("Command `%s` failed.\n", commands + i * 1024);
                }
            }
        }
        exe = 1;
    }

    return (exe);
}
