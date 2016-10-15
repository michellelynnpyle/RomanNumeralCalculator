

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

/* include standard libraries */
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* include header with RomanNumeralCalculator Function Declarations */
#include "src/RomanNumeralCalculator.h"

/* Test I: The program takes user input                         */
/* Test I.a: The program requests input                                 */
/* [maybe this is just a human test? or does not even need to be tested?] */
/* Test I.b: The program reads input                    */
/* [pass input to function, test value of variable where input is to be placed] */
/* Test II: The program correctly interprets input              */
/* Test II.a: The program calculates the value of RNs           */
/* Test II.a.i: The program assigns correct value to each character*/
/* [test determined value for all RN characters (single characters only)]       */

START_TEST(DetermineValueOfI)
{
	int SCNV;

	SCNV = SingleCharacterValue('I');
	ck_assert_int_eq(SCNV, 1);
	
}
END_TEST

START_TEST(DetermineValueofV)
{
	int SCNV;
	
	SCNV = SingleCharacterValue('V');
	ck_assert_int_eq(SCNV, 5);
}
END_TEST
	/*
        SCNV = SingleCharacterValue('X');
        ck_assert_int_eq(SCNV, 10);
        SCNV = SingleCharacterValue('L');
        ck_assert_int_eq(SCNV, 50);
        SCNV = SingleCharacterValue('C');
        ck_assert_int_eq(SCNV, 100);
        SCNV = SingleCharacterValue('D');
        ck_assert_int_eq(SCNV, 500);
        SCNV = SingleCharacterValue('M');
        ck_assert_int_eq(SCNV, 1000);
        SCNV = SingleCharacterValue('Q');
        ck_assert_int_eq(SCNV, 0);
START_TEST()
{

}
END_TEST
*/
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

/* Create Test Suite */
Suite *Calculator_Test_Suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("RomanNumeralCalculator");

	/* Core Test Case */
	tc_core = tcase_create("core");
	tcase_add_test(tc_core, DetermineValueOfI);
	tcase_add_test(tc_core, DetermineValueofV);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void)
{

	int number_failed;
	Suite *s;
	SRunner *sr;
	
	s = Calculator_Test_Suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

/* Test III.d: The program displays the resulting RN                            */
/* [just a human test, not sure if it needs to be tested...]    */
