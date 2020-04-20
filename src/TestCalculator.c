

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Calculator.h"
#include "TestCalculator.h"
#include <assert.h>

void driver(double expectedSum, double expectedDifference, double expectedProduct, double expectedQuotient, double a, double b)
{
	Calculator* calc = newCalculator();
	printf("\n\ndouble a : %.2f\n",a);
	printf("double b : %.2f\n",b);
	printf("Expected Sum : %.2f\n", expectedSum);
	printf("Expected Difference: %.2f\n", expectedDifference);
	printf("Expectedt Product: %.2f\n",expectedProduct);
	printf("Expected Quotient: %.2f\n",expectedQuotient);
	
	printf("\nCalling testSubtract\n");
	int subTest = testSubtract(expectedDifference,a,b,calc->subtract);
	if(subTest == 0) {
		goto subsuccess;
		subsuccess: printf("Expected value of subtract: %.2f |result of subtract : %.2f \ntestSubtract \033[32;1m Success \033[0m\n",expectedDifference,subtract(a,b));
	}
	if(subTest == -1) {
		goto subfail;
		subfail: printf("Expected value of subtract: %.2f |result of subtract : %.2f \ntestSubtract \033[31;1m Fail \033[0m\n",expectedDifference,subtract(a,b));
	}
	
	printf("\nCalling testAdd\n");
	int addTest = testAdd(expectedSum,a,b,calc->add);
	if(addTest == 0) {
		goto addsuccess;
		addsuccess: printf("Expected value of add: %.2f |result of add : %.2f \ntestAdd \033[32;1m Success \033[0m\n",expectedSum,add(a,b));
	}
	if(addTest == -1) {
		goto addfail;
		addfail: printf("Expected value of add: %.2f |result of add : %.2f \ntestAdd \033[31;1m Fail \033[0m\n",expectedSum,add(a,b));
	}
	
	printf("\nCalling testMultiply\n");
	int mulTest = testMultiply(expectedProduct,a,b,calc->multiply);
	if(mulTest == 0) {
		goto mulsuccess;
		mulsuccess: printf("Expected value of multiply: %.2f |result of multiply : %.2f \ntestMultiply \033[32;1m Success \033[0m\n",expectedProduct,multiply(a,b));
	}
	if(mulTest == -1) {
		goto mulfail;
		mulfail: printf("Expected value of multiply: %.2f |result of multiply : %.2f \ntestMultiply \033[31;1m Fail \033[0m\n",expectedProduct,multiply(a,b));
	}
	
	printf("\nCalling testDivide\n");
	int divTest = testDivide(expectedQuotient,a,b,calc->divide);
	if(divTest == 0) {
		goto divsuccess;
		divsuccess: printf("Expected value of divide: %.2f |result of divide : %.2f \ntestDivide \033[32;1m Success \033[0m\n",expectedQuotient,divide(a,b));
	}
	if(divTest == -1) {
		goto divfail;
		divfail: printf("Expected value of divide: %.2f |result of divide : %.2f \ntestDivide \033[31;1m Fail \033[0m\n",expectedQuotient,divide(a,b));
	}
	
	
    return;
}

int testSubtract(double expectedResult, double a, double b, double (*subtract)(double a, double b))
{
    if(subtract(a,b) == expectedResult)
    {
		return 0;
	}
	else
	{
		return -1;
	}
}

int testAdd(double expectedResult, double a, double b, double (*add)(double a, double b))
{
    if(add(a,b) == expectedResult)
    {
		return 0;
	}
	else
	{
		return -1;
	}
}

int testMultiply(double expectedResult, double a, double b, double (*multilpy)(double a, double b))
{
    if(multiply(a,b) == expectedResult)
    {
		return 0;
	}
	else
	{
		return -1;
	}
}

int testDivide(double expectedResult, double a, double b, double (*divide)(double a, double b))
{
    if(divide(a,b) == expectedResult)
    {
		return 0;
	}
	else
	{
		return -1;
	}
}
