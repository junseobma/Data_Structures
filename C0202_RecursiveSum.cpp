// 재귀로 합 구하기(RecursiveSum)

// Sum()은 공간복잡도가 O(1)
// RecurSum()은 겉으로 볼때는 변수의 개수가 적어서 메모리를 덜 사용한다고 생각할 수 있다 
// 하지만 재귀호출이 될때 마다 메모리가 누적되므로 오히려 메모리를 훨씬 더 많이 사용하며 공간복잡도는  O(n)이다

// 시간 복잡도는 둘다 O(n)

#include <iostream>

using namespace std;

int Sum(int* arr, int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

int RecurSum(int* arr, int n)
{
	// 나의 구현
	if (n > 0)
		return arr[n-1] + RecurSum(arr, n - 1);
	else
		return 0;

	// 이렇게 줄일수도 있다. n == 0 일 때 false가 된다.
	//if (n) return arr[n - 1] + RecurSum(arr, n - 1);
	//return 0;
}

int main()
{
	// Sum vs RecurSum
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << Sum(arr, n) << endl;
	cout << RecurSum(arr, n) << endl;

	return 0;
}

// 출력 결과
/*
55
55
*/