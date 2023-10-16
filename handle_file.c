#include "main.h"

int handle_file(char **args, char *buffer, char *prog)
{
    int fd;
    fd = open(args[1], O_RDONLY);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  // Read the contents of the file into a buffer.
  char buf[1024];
  int len = read(fd, buf, sizeof(buf));
  if (len < 0) {
    perror("read");
    return 1;
  }

  // Close the file.
  close(fd);

}
