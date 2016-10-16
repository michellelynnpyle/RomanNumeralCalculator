
/* RomanNumeralCalculator.h */
/* Written by Michelle Lynn Pyle */
/* October 3 2016 */
/* this file contains header code for the Roman Numeral Calculator */
#include <math.h>
#include <time.h>
#ifndef RomanNumeralCalculator_H
#define RomanNumeralCalculator_H

#endif

/* constant variable for roman numeral characters */
const char RNChars[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

/* constant variable for roman numeral values */
const int RNVals[] = {1, 5, 10, 50, 100, 500, 1000};

/* global variables to hold Roman Numerals and Values */
char InputRomanNumeral[7];
int InputRomanNumeralValues[7];

/* function prototypes */
int SingleCharacterValue (char);
void VectorOfCharacterValues (void);

