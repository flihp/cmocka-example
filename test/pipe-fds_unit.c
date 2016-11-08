#include <stdio.h>
#include <unistd.h>

#include <setjmp.h>
#include <cmocka.h>

#include "pipe-fds.h"

ssize_t
__wrap_read (int       fd,
             void     *buffer,
             size_t    count)
{
    return (ssize_t)mock ();
}

ssize_t
__wrap_write (int       fd,
              void     *buffer,
              size_t    count)
{
    return (ssize_t)mock ();
}

static void
pipe_fds_read_error_unit (void **state)
{
    will_return (__wrap_read, -1);
    assert_int_equal (pipe_fds (3, 4), -1);
}

static void
pipe_fds_read_eof_unit (void **state)
{
    will_return (__wrap_read, 0);
    assert_int_equal (pipe_fds (3, 4), -2);
}

static void
pipe_fds_write_error_unit (void **state)
{
    will_return (__wrap_read,   5);
    will_return (__wrap_write, -1);
    assert_int_equal (pipe_fds (3, 4), -3);
}

static void
pipe_fds_write_eof_unit (void **state)
{
    will_return (__wrap_read, 5);
    will_return (__wrap_write, 0);
    assert_int_equal (pipe_fds (3, 4), -4);
}

static void
pipe_fds_success_unit (void **state)
{
    will_return (__wrap_read, 5);
    will_return (__wrap_write, 5);
    assert_int_equal (pipe_fds (3, 4), 5);
}

int
main (int   argc,
      char *argv[])
{
    UnitTest const tests [] = {
        unit_test (pipe_fds_read_error_unit),
        unit_test (pipe_fds_read_eof_unit),
        unit_test (pipe_fds_write_error_unit),
        unit_test (pipe_fds_write_eof_unit),
        unit_test (pipe_fds_success_unit),
    };
    return run_tests (tests);
}
