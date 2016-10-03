
/* Roman Numeral Calculator Test Code                                   */
/* Written by Michelle Lynn Pyle                                                */
/* for Pillar Technologies interview KATA                               */
/* September 2016                                                                               */
/* void RNCalculator(char, char, char)                                  */
/* void RNCalculator(1stRN, 2ndRN, operator)                    */
/* Write a progression of tests for Roman Numeral (RN)  */
/* calculator Code                                                                              */
/* include Check Test Code Package */
#include <check.h>

/* Test I: The program takes user input                         */
/* Test I.a: The program requests input                                 */
/* [maybe this is just a human test? or does not even need to be tested?] */
/* Test I.b: The program reads input                    */
/* [pass input to function, test value of variable where input is to be placed] */
/* Test II: The program correctly interprets input              */
/* Test II.a: The program calculates the value of RNs           */
/* Test II.a.i: The program assigns correct value to each character*/
/* [test determined value for all RN characters (single characters only)]       */

START_TEST (DetermineValueOfSingleCharacterRomanNumerals)
{
/* test code to determine if the program correctly calculates the value of a single character roman numeral */

}
END_TEST
/* Test II.a.ii: The program knows the relative value of RN characters          */
/* [test determined value for 2-character RNs]  */
/* Test II.a.iii: The program uses applies order of operations to determine RN string value     */
/* [test determined value for 3+ character RNs] */
/* Test II.b: The program determines the operation to perform on RNs            */
/* [test that program adds when "+" is passed and subtracts when "-" is passed] */
/* Test III: The program outputs the computed number                            */
/* Test III.a: The program correctly calculates outputs                         */
/* [this may be unecessary...computers know math...]    */
/* Test III.b: The program determines if the result can be expressed as RN      */
/* [test that program displays error message when result is greater than 3999]*/
/* Test III.c: The program converts the result to an RN                         */
/* [test output value with some value RN + one ]        */
/* Test III.d: The program displays the resulting RN                            */
/* [just a human test, not sure if it needs to be tested...]    */
