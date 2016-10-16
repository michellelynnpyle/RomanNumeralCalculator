# Recommended Automake Flags
ACLOCAL_AMFLAGS = -I m4 --install

# Creating a library for the bin program and check program
lib_LTLIBRARIES = libRomanNumeralCalculator-1.0.la
libRomanNumeralCalculator_1_0_la_SOURCES = src/RomanNumeralCalculator.c src/RomanNumeralCalculator.h
include_HEADERS = src/RomanNumeralCalculator.h

# Code to define the bin program (tells automake which executable to
# create when make is called
bin_PROGRAMS = RomanNumeralCalculator
# Declare source files for the bin program
RomanNumeralCalculator_SOURCES = src/RomanNumeralCalculator.c src/RomanNumeralCalculator.h
# Libraries for the bin program
RomanNumeralCalculator_LDADD = $(lib_LTLIBRARIES)
# Compiler flags (library flags needed for check to work)
RomanNumeralCalculator_CPPFLAGS = -DDEBUG -lsubunit -lm -lrt -lpthread

# Distributes a file in the m4 sub directory to automake does not delete it
EXTRA_DIST = m4/NOTES

# set up check program (automake creates this when "make check" is run)
# Check version 0.10.0 used
TESTS = check_RomanNumeralCalculator
check_PROGRAMS = check_RomanNumeralCalculator
# Declare source files for check program
check_RomanNumeralCalculator_SOURCES = test/check_RomanNumeralCalculator.c $(top_builddir)/src/RomanNumeralCalculator.h
# Compiler flags needed for check program
check_RomanNumeralCalculator_CFLAGS = @CHECK_CFLAGS@ -lsubunit -lm -lrt -lpthread
# Libraries needed for check program based on Check Unit Testing
check_RomanNumeralCalculator_LDADD = $(top_builddir)/libRomanNumeralCalculator-1.0.la @CHECK_LIBS@
