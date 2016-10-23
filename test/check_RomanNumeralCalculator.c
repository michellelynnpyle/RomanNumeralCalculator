

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
	char ii;
	for(ii=0;ii<126;ii++)
	{
		if(ii==67) /* skip 'C' and 'D' */
		{
			ii++;
			ii++;
		}
		if(ii==73) /* skip 'I' */
		{
			ii++;
		}
		if(ii==76) /* skip 'L' and 'M' */
		{
			ii++;
			ii++;
		}
		if(ii==86) /* skip 'V' */
		{
			ii++;
		}
		if(ii==88) /* skip 'X' */
		{
			ii++;
		}
		SCNV = SingleCharacterValue(ii);
	        ck_assert_int_eq(SCNV, 0);
	}
}
END_TEST

/* Test that code converts string of characters into separate characters */
START_TEST(RomanNumeralStringToCharVector){
/* fucntion prototype: void VectorOfCharacterValues (void) */
	RNString TestNumeral;
	RNValues TestValues;
	strcpy(TestNumeral.characters, "MXVII");
	TestValues = VectorOfCharacterValues(TestNumeral);
	ck_assert_int_eq(TestValues.Values[0], 1000);
	ck_assert_int_eq(TestValues.Values[1], 10);
	ck_assert_int_eq(TestValues.Values[2], 5);
	ck_assert_int_eq(TestValues.Values[3], 1);
	ck_assert_int_eq(TestValues.Values[4], 1);
	ck_assert_int_eq(TestValues.Values[6], NULL);


}
END_TEST

/* Test that code converts string of values into correct value */
START_TEST(RomanNumeraltoArabic){
/* function prototype: int RomanNumeralArabicValue (RNValues) */

	int theArabicValue;
	RNValues theRNCharacterValues;
	theRNCharacterValues.Values[0] = 10;
	theRNCharacterValues.Values[1] = 50;
	theRNCharacterValues.Values[2] = 1;
	theRNCharacterValues.Values[3] = 1;
	theRNCharacterValues.Values[4] = 1;
	theRNCharacterValues.Values[5] = 0;
	theArabicValue = RomanNumeralArabicValue(theRNCharacterValues);
	ck_assert_int_eq(theArabicValue, 43);
}
END_TEST

START_TEST(DifferentValueTest){
/* function prototype: int RomanNumeralArabicValue (RNValues) */

	int theArabicValue;
	RNValues theRNCharacterValues;
	theRNCharacterValues.Values[0] = 1000;
	theRNCharacterValues.Values[1] = 50;
	theRNCharacterValues.Values[2] = 100;
	theRNCharacterValues.Values[3] = 1;
	theRNCharacterValues.Values[4] = 5;
	theRNCharacterValues.Values[5] = 0;
	theArabicValue = RomanNumeralArabicValue(theRNCharacterValues);
	ck_assert_int_eq(theArabicValue, 1054);
}
END_TEST

START_TEST(TestCalculator){
/* function prototype: int Calculator (FirstValue, SecondValue, Operator) */
	int Output;
	Output = Calculator(25, 10, '-');
	ck_assert_int_eq(Output, 15);

}
END_TEST

START_TEST(TestArabicToRomanNumeral){
/* function prototype: RNString BackToRomanNumeral (ResultValue) */
	RNString ResultRomanNumeral;
	ResultRomanNumeral = BackToRomanNumeral(1024);
	ck_assert_int_eq(ResultRomanNumeral.characters[0], 1);
	ck_assert_int_eq(ResultRomanNumeral.characters[1], 0);
	ck_assert_int_eq(ResultRomanNumeral.characters[2], 2);
	ck_assert_int_eq(ResultRomanNumeral.characters[3], 4);
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
	TCase *tc_TestArabicValue;
	TCase *tc_TestCalculator;
	TCase *tc_TestBackToRomanNumeral;

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

	/* Test Case for arabic value of RN from arabic value of RN characters */
	tc_TestArabicValue = tcase_create("TestArabicValue");
	tcase_add_test(tc_TestArabicValue, RomanNumeraltoArabic);
	tcase_add_test(tc_TestArabicValue, DifferentValueTest);
	suite_add_tcase(s, tc_TestArabicValue);

	/* Test Case for making sure the right operation is performed */
	tc_TestCalculator = tcase_create("TestCalculator");
	tcase_add_test(tc_TestCalculator, TestCalculator);
	suite_add_tcase(s, tc_TestCalculator);

	/* Test Case for converting the resulting value back to roman Numeral */
	tc_TestBackToRomanNumeral = tcase_create("TestBackToRomanNumeral");
	tcase_add_test(tc_TestBackToRomanNumeral, TestArabicToRomanNumeral);
	suite_add_tcase(s, tc_TestBackToRomanNumeral);

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
