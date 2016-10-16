
/* RomanNumeralCalculator.c */
/* Written by Michelle Lynn Pyle */
/* October 3 2016 */
/* this code creates a program to add or subtract two Roman Numerals */
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "RomanNumeralCalculator.h"


int main(void) {

printf("\n\nthe code did Comp  ile\n\n");
return 0;


}

int SingleCharacterValue( char RomanNumeral)
{/* start of SingleCharacterValue */
/* This function takes in a single character and determines it's value */
/* 0 is returned if the character is not part of the roman numeral */
/* system. other functions will check for zero values and return errors */

/* recode to a linear search using constant values for the roman numeral */
/* characters and corresponding values and loop s.t. search terminates */ 
/* when value is found */

	int SCV;

	if(RomanNumeral == 'I'){
		SCV = 1;}
	if(RomanNumeral == 'V'){
		SCV = 5;}
	if(RomanNumeral == 'X'){
		SCV = 10;}
	if(RomanNumeral == 'L'){
		SCV = 50;}
	if(RomanNumeral == 'C'){
		SCV = 100;}
	if(RomanNumeral == 'D'){
		SCV = 500;}
	if(RomanNumeral == 'M'){
		SCV = 1000;}
	if(RomanNumeral != 'I' && RomanNumeral != 'V' && RomanNumeral != 'X' && RomanNumeral != 'L' && RomanNumeral != 'C' && RomanNumeral != 'D' && RomanNumeral != 'M'){
		SCV = 0;}
	return SCV;
/* end of SingleCharacterValue */}

void VectorOfCharacterValues (void)
{/* start of VectorOfCharacterValues */
/* This function is called to determine the value of each character in */
/* a Roman Numeral. Global variables (declared in the header file */
/* RomanNumeralCalculator.h) are used to store the information */

InputRomanNumeralValues[2] = SingleCharacterValue(InputRomanNumeral[2]);

/* end of VectorOfCharacterValues */}
