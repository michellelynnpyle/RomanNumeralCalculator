
/* RomanNumeralCalculator.c */
/* Written by Michelle Lynn Pyle */
/* October 3 2016 */
/* this file contains a function to add or subtract two Roman Numerals */
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "RomanNumeralCalculator.h"


int main(void) {
return 0;

}

int SingleCharacterValue( char RomanNumeral)
{/* start of SingleCharacterValue */
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
	if(RomanNumeral != 'I' && 'V' && 'X' && 'L' && 'C' && 'D' && 'M'){
		SCV = 0;}
	return SCV;
/* end of SingleCharacterValue */}


