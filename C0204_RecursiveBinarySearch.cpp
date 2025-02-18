// 재귀 이진 탐색(RecursiveBinarySearch)

// 어떤 문제를 풀 때 문제의 범위를 점점 쪼개간다면 재귀 호출을 통해서도 풀 수 있다

#include <iostream>

using namespace std;

int BinarySearch(int* arr, int n, int x)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2; // 정수 나누기 (버림)

		cout << "middle " << middle << endl;

		if (x < arr[middle])
		{
			right = middle - 1;
			cout << "right " << right << endl;
		}
		else if (x > arr[middle])
		{
			left = middle + 1;
			cout << "left " << left << endl;
		}
		else {
			cout << "Found " << middle << endl;
			return middle;
		}
	}

	cout << "Not found" << endl;
	return -1; // Not found
}

int RecurBinarySearch(int* arr, int left, int right, int x) // n 대신에 left, right
{
	if (left <= right)
	{
		int middle = (left + right) / 2;

		if (x < arr[middle])
		{
			return RecurBinarySearch(arr, left, middle - 1, x); 
		}
		else if (x > arr[middle])
		{
			return RecurBinarySearch(arr, middle + 1, right, x); 
		}
		else
		{
			return middle; 
		}
	}

	cout << "Not found" << endl;
	return -1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << BinarySearch(arr, n, -2) << endl;
	
	cout << endl;
	cout << RecurBinarySearch(arr, 0, n - 1, -2) << endl;
	
	cout << endl;
	cout << RecurBinarySearch(arr, 0, n - 1, 3) << endl;
	
	cout << endl;
	cout << RecurBinarySearch(arr, 0, n - 1, 7) << endl;

	return 0;
}


// 출력 결과
/*
middle 4
right 3
middle 1
right 0
middle 0
right -1
Not found
-1

Not found
-1

2

6
*/