

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Calculator.h"
#include "TestCalculator.h"


/*
    In main, call driver multiple times. Once in which there are all successes and once for each test function such that each one will fail once.
*/

int main(int argc, char* argv[])
{
	driver(10,2,24,1.5,6,4);
	driver(11,2,24,1.5,6,4);
	driver(10,22,24,1.5,6,4);
	driver(10,2,224,1.5,6,4);
	driver(10,2,24,21.5,6,4);
    return 0;
}
