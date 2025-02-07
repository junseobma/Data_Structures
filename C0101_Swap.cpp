#include <iostream>

using namespace std;

int main()
{
	//Swap two numbers
	int a = 5;
	int b = 10;

	cout << "Before swapping: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	int temp = a;
	a = b;
	b = temp;

	cout << "After swapping: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}