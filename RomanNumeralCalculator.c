
/* RomanNumeralCalculator.c */
/* Written by Michelle Lynn Pyle */
/* October 3 2016 */
/* this file contains a function to add or subtract two Roman Numerals */

#include "RomanNumeralCalculator.h"


int SingleCharacterValue( int RomanNumeral)
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
	else
		SCV = 0;
	return SCV;
/* end of SingleCharacterValue */}
