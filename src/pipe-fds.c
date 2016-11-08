#include <stdio.h>
#include <stdint.h>

#define MAX_BUF 4096

int
pipe_fds (int fd_in,
          int fd_out)
{
    uint8_t buffer [MAX_BUF] = { 0, };
    ssize_t count            = 0;

    count = read (fd_in, buffer, MAX_BUF);
    if (count == -1)
        return -1;
    if (count == 0) /* closed / EOF */
        return -2;

    count = write (fd_out, buffer, count);
    if (count == -1)
        return -3;
    if (count == 0) /* closed / EOF */
        return -4;

    return count;
}
