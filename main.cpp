#include <iostream>
#include "Calculator.h"
int main(void) {
	Calculator cal;
	cal.InitCalculation();
	std::cout << cal.Add(3.2, 2.4) << std::endl;
	cal.ShowCalculationCount();
	return 0;
}