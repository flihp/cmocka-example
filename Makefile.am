AM_CFLAGS = -I$(srcdir)/src

bin_PROGRAMS   = src/pipe-fds
check_PROGRAMS = test/pipe-fds_unit
TESTS = $(check_PROGRAMS)

src_pipe_fds_SOURCES       = src/pipe-fds.c src/main.c

test_pipe_fds_unit_CFLAGS  = $(CMOCKA_CFLAGS) $(AM_CFLAGS)
test_pipe_fds_unit_LDADD   = $(CMOCKA_LIBS)
test_pipe_fds_unit_LDFLAGS = -Wl,--wrap=read,--wrap=write
test_pipe_fds_unit_SOURCES = test/pipe-fds_unit.c src/pipe-fds.c
