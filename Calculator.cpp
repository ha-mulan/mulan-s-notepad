#include "Calculator.h"
#include <iostream>

void Calculator::InitCalculation(void) {
	numOfAdd = 0;
	numOfMin = 0;
	numOfDiv = 0;
	numOfMul = 0;
}
void Calculator::ShowCalculationCount(void) {
	std::cout << numOfAdd << std::endl;
	std::cout << numOfMin << std::endl;
	std::cout << numOfDiv << std::endl;
	std::cout << numOfMul << std::endl;
}