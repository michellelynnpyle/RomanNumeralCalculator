
/* RomanNumeralCalculator.c */
/* Written by Michelle Lynn Pyle */
/* October 3 2016 */
/* this code creates a program to add or subtract two Roman Numerals */
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "RomanNumeralCalculator.h"


int main(void) {

printf("\n\nthe code did Compileee\n\n");
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
			i = 7;
		}
	}

	return SCV;
/* end of SingleCharacterValue */}

RNValues VectorOfCharacterValues (RNString InputRN)
{/* start of VectorOfCharacterValues */
/* This function is called to determine the value of each character in */
/* a Roman Numeral. Global variables (declared in the header file */
/* RomanNumeralCalculator.h) are used to store the information */
/* InputRomanNumeral must be a string of characters ending in NULL */
	int k;
	RNValues InputRNValues;
	for(k=0;k<MAXLEN;k++)
	{
		InputRNValues.Values[k] = SingleCharacterValue(InputRN.characters[k]);
	}

	return InputRNValues;
/* end of VectorOfCharacterValues */}

int RomanNumeralArabicValue (RNValues InputRNValues)
{/* start of RomanNumeralArabicValue */

	int working, total;
	int i,k;
	working = InputRNValues.Values[0];
	total = 0;
	for(i=1;i<MAXLEN;i++)
	{	k = i-1;
		if(InputRNValues.Values[i] == InputRNValues.Values[k])
		{
			working += InputRNValues.Values[i];
		}
		if(InputRNValues.Values[i] > InputRNValues.Values[k])
		{
			total += (InputRNValues.Values[i]-working);
			working = 0;
		}
		if(InputRNValues.Values[i] < InputRNValues.Values[k] && InputRNValues.Values[i] != 0)
		{
			total += working;
			working = InputRNValues.Values[i];
		}
		if(InputRNValues.Values[i] == 0)
		{
			total += working;
			i = MAXLEN;
		}
	}
return total;
/* end of RomanNumeralArabicValue */}



