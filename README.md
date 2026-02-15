*This activity has been created as part of the 42 curriculum by Doha Baniyaseen*

# Get Next Line

## Description
"get_next_line" is a C function that reads and returns aline from a file descriptor each time it is called. The function keeps reading from the file until it encounters a newline ('\n') or reaches the end of the file.

This project helps understanding of :

- Static variables
- Memory management
- File descriptor
- Efficient reading from files

 ---

## Instructions
To compile this code, you have to install these three file get_next_line.c, get_next_line.h, get_next_line_utils.c and main.cyou can test this main

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
  int fd;
  char *line;

  fd = open("test.txt", O_RDONLY);
  while ((line = get_next_line(fd)))
  {
    printf("%s", line);
    free(line);
  }
  close(fd);
}
You will compile your code as follows (a buffer size of 42 is used as an example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

## Resources
https://medium.com/@lannur-s/42-get-next-line-guide-string-approach-chapter-3-understanding-the-subject-5101454806ce
https://medium.com/@lannur-s/gnl-c3cff1ee552b
https://dev.to/aerrfig/get-next-line-a-42-project-to-learn-how-to-deal-with-file-descriptors-and-io-of-system-3652
https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line
https://www.youtube.com/watch?v=-Mt2FdJjVno
