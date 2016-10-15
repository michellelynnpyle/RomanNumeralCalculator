ACLOCAL_AMFLAGS = -I m4 --install
lib_LTLIBRARIES = libRomanNumeralCalculator-1.0.la
libRomanNumeralCalculator_1_0_la_SOURCES = src/RomanNumeralCalculator.c src/RomanNumeralCalculator.h
include_HEADERS = src/RomanNumeralCalculator.h
bin_PROGRAMS = RomanNumeralCalculator
RomanNumeralCalculator_SOURCES = src/RomanNumeralCalculator.c src/RomanNumeralCalculator.h
RomanNumeralCalculator_LDADD = $(lib_LTLIBRARIES)
RomanNumeralCalculator_CPPFLAGS = -DDEBUG -lsubunit -lm -lrt -lpthread

EXTRA_DIST = m4/NOTES

TESTS = check_RomanNumeralCalculator
check_PROGRAMS = check_RomanNumeralCalculator
check_RomanNumeralCalculator_SOURCES = test/check_RomanNumeralCalculator.c $(top_builddir)/src/RomanNumeralCalculator.h
check_RomanNumeralCalculator_CFLAGS = @CHECK_CFLAGS@ -lsubunit -lm -lrt -lpthread
check_RomanNumeralCalculator_LDADD = $(top_builddir)/libRomanNumeralCalculator-1.0.la @CHECK_LIBS@
