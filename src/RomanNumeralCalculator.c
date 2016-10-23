
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


int Calculator (int FirstValue, int SecondValue, char Operator)
{/* start of Calculator */
	int result;
	if(Operator == '+')
	{
		result = FirstValue+SecondValue;
	}
	if(Operator == '-')
	{
		result = FirstValue-SecondValue;
	}
	return result;
/* end of Calculator */}

RNString BackToRomanNumeral (int ResultValue)
{/* start of BackToRomanNumeral */
	RNString ResultRomanNumeral;
	char flag = 0;
	char placevalue[4];
	int i, k;
	if(ResultValue < 1)
	{
		flag = 1;
		/* change this to an error message later */
	}
	if(ResultValue > 3999)
	{
		flag = 1;
		/* change this to an error message later */
	}
	if(flag !=1){
		/* a loop to find the digits of the ResultValue */
		k = 1000;
		for(i=0;i<4;i++)
		{
			placevalue[i] = floor(ResultValue/k);
			ResultValue = ResultValue-(placevalue[i]*k);
			k = k/10;
		}
		/* a loop to convert each digit to roman numerals */
		/* uses conversion system based on base, fives, and tens characters for each place */
		k=0;
			/* writing thousands place */
		for(i=0;i<placevalue[0];i++)
		{
			ResultRomanNumeral.characters[k] = 'M';
			k++;
		}
			/* writing hundreds place */
		if(placevalue[1]<4)
		{
			for(i=0;i<placevalue[1];i++)
			{
				ResultRomanNumeral.characters[k] = HundredsChars[0];
				k++;
			}
		}
		if(placevalue[1]==4)
		{
			ResultRomanNumeral.characters[k] = HundredsChars[0];
			k++;
			ResultRomanNumeral.characters[k] = HundredsChars[1];
			k++;
		}
		if(placevalue[1]>4 && placevalue[1]<9)
		{
			ResultRomanNumeral.characters[k] = HundredsChars[1];
			k++;
			for(i=5;i<placevalue[1];i++)
			{
				ResultRomanNumeral.characters[k] = HundredsChars[0];
				k++;
			}
		}
		if(placevalue[1]==9)
		{
			ResultRomanNumeral.characters[k] = HundredsChars[0];
			k++;
			ResultRomanNumeral.characters[k] = HundredsChars[2];
			k++;
		}
	/* writing tens place */
		if(placevalue[2]<4)
		{
			for(i=0;i<placevalue[2];i++)
			{
				ResultRomanNumeral.characters[k] = TensChars[0];
				k++;
			}
		}
		if(placevalue[2]==4)
		{
			ResultRomanNumeral.characters[k] = TensChars[0];
			k++;
			ResultRomanNumeral.characters[k] = TensChars[1];
			k++;
		}
		if(placevalue[2]>4 && placevalue[1]<9)
		{
			ResultRomanNumeral.characters[k] = TensChars[1];
			k++;
			for(i=5;i<placevalue[2];i++)
			{
				ResultRomanNumeral.characters[k] = TensChars[0];
				k++;
			}
		}
		if(placevalue[2]==9)
		{
			ResultRomanNumeral.characters[k] = TensChars[0];
			k++;
			ResultRomanNumeral.characters[k] = TensChars[2];
			k++;
		}
			/* writing ones place */
		if(placevalue[3]<4)
		{
			for(i=0;i<placevalue[3];i++)
			{
				ResultRomanNumeral.characters[k] = OnesChars[0];
				k++;
			}
		}
		if(placevalue[3]==4)
		{
			ResultRomanNumeral.characters[k] = OnesChars[0];
			k++;
			ResultRomanNumeral.characters[k] = OnesChars[1];
			k++;
		}
		if(placevalue[3]>4 && placevalue[3]<9)
		{
			ResultRomanNumeral.characters[k] = OnesChars[1];
			k++;
			for(i=5;i<placevalue[3];i++)
			{
				ResultRomanNumeral.characters[k] = OnesChars[0];
				k++;
			}
		}
		if(placevalue[3]==9)
		{
			ResultRomanNumeral.characters[k] = OnesChars[0];
			k++;
			ResultRomanNumeral.characters[k] = OnesChars[2];
			k++;
		}
	ResultRomanNumeral.characters[k] = NULL;
	}
		
	return ResultRomanNumeral;
/* end of BackToRomanNumeral */}



