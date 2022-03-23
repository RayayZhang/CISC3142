#include <iostream>
#include <cmath>

using namespace std;

struct Calculator
{
	double firstNum, secondNum;
	int op;
	//enum values for operations
	enum Operation 
	{
		Add = 1,
		Subtract = 2,
		Multiply = 3,
		Divide = 4,
		Square = 5,
		Exponent = 6,
		Sqrt = 7,
	};
	//Store the values
	Calculator (double firstInput, double secondInput, int opr)
	{
		firstNum = firstInput;
		secondNum = secondInput;
		op = opr;
	}

	int calculate(int a, int b, int op)
	{
		a = firstNum;
		b = secondNum;
		switch (op)
		{
			case Operation::Add:
				return a + b;
				break;
			case Operation::Subtract:
				return a - b;
				break;
			case Operation::Multiply: 
				return a * b;
				break;
			case Operation::Divide:
				return a / b;
				break;
			case Operation::Square:
				return pow(a, 2);
				break;
			case Operation:: Exponent:
				return pow(a, b);
				break;
			case Operation:: Sqrt:
				return sqrt(a);
				break;
			default:
				return -1;
		}
	}
};

int main()
{
	double firstInput, secondInput;
	int oprd;
	
	cout <<"This is a calculator that could only handle simple expression such as a+b, a-b, a*b, and etc\n";
	cout <<"Pleas enter your first input:\n";
	cin >> firstInput;
	if(cin.fail())
	{
		cout << "Your entered an invalid value!";
		return -1;
	}

	cout << "Please choose the operation from following options:\n";
	cout << "Add: 1\nSubtract: 2\nMultiply: 3\nDivide: 4\nSquare: 5\nExponent: 6\nSquareroot: 7\n";
	cin >> oprd;
	if(cin.fail())
	{
		cout << "You have chosen an invalid operation!";
		return -1;
	}
	if(oprd != 5 && oprd != 7)
	{
		cout << "Please enter your second number:\n";
		cin >> secondInput;
		if(cin.fail())
		{
			cout << "Your entered an invalid value!";
			return -1;
		}
	}
	//store the values into the Calculator
	Calculator calc(firstInput, secondInput, oprd);
	auto answer = calc.calculate(firstInput, secondInput, oprd);
	cout << "The result is: " << answer << "\n";
	return 0;
}


