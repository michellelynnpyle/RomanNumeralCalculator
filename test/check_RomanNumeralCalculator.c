

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

START_TEST(DetermineValueOfI)
{/* function prototype: int SingleCharacterValue (char) */
	int SCNV;

	SCNV = SingleCharacterValue('I');
	ck_assert_int_eq(SCNV, 1);
	
}
END_TEST

START_TEST(DetermineValueOfV)
{/* function prototype: int SingleCharacterValue (char) */
	int SCNV;
	
	SCNV = SingleCharacterValue('V');
	ck_assert_int_eq(SCNV, 5);
}
END_TEST

START_TEST(DetermineValueOfX)
{/* function prototype: int SingleCharacterValue (char) */
	int SCNV;
	
	SCNV = SingleCharacterValue('X');
        ck_assert_int_eq(SCNV, 10);
}
END_TEST

START_TEST(DetermineValueOfL)
{/* function prototype: int SingleCharacterValue (char) */
	int SCNV;

	SCNV = SingleCharacterValue('L');
        ck_assert_int_eq(SCNV, 50);
}
END_TEST

START_TEST(DetermineValueOfC)
{/* function prototype: int SingleCharacterValue (char) */
	int SCNV;
	
        SCNV = SingleCharacterValue('C');
        ck_assert_int_eq(SCNV, 100);
}
END_TEST

START_TEST(DetermineValueOfD)
{/* function prototype: int SingleCharacterValue (char) */
	int SCNV;
	
        SCNV = SingleCharacterValue('D');
        ck_assert_int_eq(SCNV, 500);
}
END_TEST

START_TEST(DetermineValueOfM)
{/* function prototype: int SingleCharacterValue (char) */
	int SCNV;
	
        SCNV = SingleCharacterValue('M');
        ck_assert_int_eq(SCNV, 1000);
}
END_TEST

START_TEST(CheckRandomCharacter)
{/* function prototype: int SingleCharacterValue (char) */
	int SCNV;
	
	SCNV = SingleCharacterValue('Q');
        ck_assert_int_eq(SCNV, 0);
}
END_TEST

/* Test that code converts string of characters into separate characters */
START_TEST(RomanNumeralStringToCharVector){
/* fucntion prototype: void VectorOfCharacterValues (void) */
	
	InputRomanNumeral[0] = 'M' ;
	InputRomanNumeral[1] = 'X' ;
	InputRomanNumeral[2] = 'V' ;
	InputRomanNumeral[3] = 'I' ;
	InputRomanNumeral[4] = 'I' ;
	VectorOfCharacterValues();
	ck_assert_int_eq(InputRomanNumeralValues[2], 5);

}
END_TEST

/* Create Test Suite */
Suite *SingleCharacterSuite(void)
{
	Suite *s;
	TCase *tc_SingleVal;
	TCase *tc_AllSingleCharacterValues;
	TCase *tc_OtherValues;
	TCase *tc_TestStringValues;

	s = suite_create("SingleCharacterSuite");

	/* Test Case for Value of I */
	tc_SingleVal = tcase_create("SingleVal");
	tcase_add_test(tc_SingleVal, DetermineValueOfI);
	suite_add_tcase(s, tc_SingleVal);

	/* Test Case for all Single Characters */
	tc_AllSingleCharacterValues = tcase_create("AllSingleCharacterValues");
	tcase_add_test(tc_AllSingleCharacterValues, DetermineValueOfI);
	tcase_add_test(tc_AllSingleCharacterValues, DetermineValueOfV);
	tcase_add_test(tc_AllSingleCharacterValues, DetermineValueOfX);
	tcase_add_test(tc_AllSingleCharacterValues, DetermineValueOfL);	
	tcase_add_test(tc_AllSingleCharacterValues, DetermineValueOfC);
	tcase_add_test(tc_AllSingleCharacterValues, DetermineValueOfD);
	tcase_add_test(tc_AllSingleCharacterValues, DetermineValueOfM);
	suite_add_tcase(s, tc_AllSingleCharacterValues);
	/* Test Case for other characters = 0 */
	tc_OtherValues = tcase_create("OtherValues");
	tcase_add_test(tc_OtherValues, CheckRandomCharacter);
	suite_add_tcase(s, tc_OtherValues);

	/* Test Case for string of characters put in to vector */
	tc_TestStringValues = tcase_create("TestStringVals");
	tcase_add_test(tc_TestStringValues, RomanNumeralStringToCharVector);
	suite_add_tcase(s, tc_TestStringValues);

	return s;
}

int main(void)
{

	int number_failed;
	Suite *SCSuite;
	SRunner *sr;
	
	SCSuite = SingleCharacterSuite();

	sr = srunner_create(SCSuite);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

/* Test III.d: The program displays the resulting RN                            */
/* [just a human test, not sure if it needs to be tested...]    */
