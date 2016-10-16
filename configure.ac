AC_INIT([RomanNumeralCalculator], [0.01], [michellepyle@gmail.com], [RomanNumeralCalculator])

AM_PROG_AR
# force version of autoconf
AC_PREREQ([2.68])
# check for source file
AC_CONFIG_SRCDIR([src/RomanNumeralCalculator.c])
# where to place configuration results
AC_CONFIG_HEADERS([config.h])
# make a place for auxillary files
#AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

# enable automake to create makefiles
AM_INIT_AUTOMAKE([1.11 subdir-objects -Wall -Werror])
AC_CONFIG_FILES([Makefile])

# make sure Check is available on the system
AM_PATH_CHECK(,[have_check="yes"],
  AC_MSG_WARN([Check not found; cannot run unit tests!])
  [have_check="no"])
AM_CONDITIONAL(HAVE_CHECK, test x"$have_check" = "xyes")

# initialize Libtools
LT_INIT

# Looks for libraries needed for Check
# Check version 0.10.0 used
AC_CHECK_LIB(m, floor)
AC_CHECK_LIB(rt, setitimer)
AC_CHECK_LIB(pthread, pthread_create)
AC_CHECK_LIB(subunit, subunit_test_error)

# look for the c compiler
AC_PROG_CC

# do final output
AC_OUTPUT
