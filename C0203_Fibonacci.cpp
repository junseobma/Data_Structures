// 피보나치 수열(Fibonacci)

// F0 = 0, F1 = 1
// Fn = Fn-1 + Fn-2
// 피보나치 수열은 Recursion으로 구현하기가 훨씬 쉽다
// 스택이 오버플로우 나는 경우가 있기 때문에 재귀호출을 사용하지 않고 구현해야 될 때가 있다

#include <iostream>
#include <cassert>
#include <algorithm> // swap
#include <iomanip> // setw

using namespace std;

int Fibonacci(int n)
{
	if (n == 0)
		return 0; // F0 = 0 
	else if (n == 1)
		return 1; // F1 = 1
	else
	{
		int prev1 = 0;
		int prev2 = 1;

		int fn = 0;

		for (int i = 2; i <= n; i++)
		{
			fn = prev1 + prev2;

			prev1 = prev2;
			prev2 = fn;
		}

		return fn;
	}
}

int RecurFibonacci(int n)
{
	if (n == 0)
		return 0; // F0 = 0 
	else if (n == 1)
		return 1; // F1 = 1

	return RecurFibonacci(n-1) + RecurFibonacci(n-2);
}

int main()
{
	// Input      : 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
	// Fibonnacci : 0   1   1   2   3   5   8  13  21  34  55  89 144 233 377
	// Fibonnacci : 0   1   1   2   3   5   8  13  21  34  55  89 144 233 377

	cout << "Input     : ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << i << " ";
	cout << endl;

	// Fibonnacci
	cout << "Fibonnacci: ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << Fibonacci(i) << " ";
	cout << endl;

	cout << "Fibonnacci: ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << RecurFibonacci(i) << " ";
	cout << endl;

	return 0;
}

// 출력 결과
/*
Input     :   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
Fibonnacci:   0   1   1   2   3   5   8  13  21  34  55  89 144 233 377
Fibonnacci:   0   1   1   2   3   5   8  13  21  34  55  89 144 233 377
*/