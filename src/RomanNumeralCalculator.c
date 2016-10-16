
/* RomanNumeralCalculator.c */
/* Written by Michelle Lynn Pyle */
/* October 3 2016 */
/* this code creates a program to add or subtract two Roman Numerals */
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "RomanNumeralCalculator.h"


int main(void) {

printf("\n\nthe code did Compile\n\n");
return 0;


}

int SingleCharacterValue( char RomanNumeral)
{/* start of SingleCharacterValue */
/* This function takes in a single character and determines it's value */
/* 0 is returned if the character is not part of the roman numeral */
/* system. other functions will check for zero values and return errors */

	int SCV, i;
	SCV = 0;
	for(i=0;i<=6;i++)
	{
		if(RomanNumeral == RNChars[i])
		{
			SCV = RNVals[i];
			i = 6;
		}
	}

	return SCV;
/* end of SingleCharacterValue */}

void VectorOfCharacterValues (void)
{/* start of VectorOfCharacterValues */
/* This function is called to determine the value of each character in */
/* a Roman Numeral. Global variables (declared in the header file */
/* RomanNumeralCalculator.h) are used to store the information */

InputRomanNumeralValues[2] = SingleCharacterValue(InputRomanNumeral[2]);

/* end of VectorOfCharacterValues */}
