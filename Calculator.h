#ifndef __CALCULATOR_H_
#define __CALCULATOR_H_


class Calculator {
private:
	int numOfAdd;
	int numOfMin;
	int numOfDiv;
	int numOfMul;
	
public:
	void InitCalculation(void);
	double Add(double a, double b);
	double Min(double a, double b);
	double Div(double a, double b);
	double Mul(double a, double b);
	void ShowCalculationCount(void);
};
inline double Calculator::Add(double a, double b) {
	numOfAdd++;
	return a + b;
}
inline double Calculator::Min(double a, double b) {
	numOfMin++;
	return a - b;
}
inline double Calculator::Div(double a, double b) {
	numOfDiv++;
	return a / b;
}
inline double Calculator::Mul(double a, double b) {
	numOfMul++;
	return a * b;
}
#endif