#include <unistd.h>

#include "pipe-fds.h"

int
main (int   argc,
      char *argv[])
{
    return pipe_fds (STDIN_FILENO, STDOUT_FILENO);
}
