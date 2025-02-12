// 순차 탐색(SequentialSearch)

// Count(): 정렬이 안된 상태에서는 한번씩은 다 비교를 해봐야된다. 
// SortedCount(): 정렬이 되있으면 탐색의 효율을 높일 수 있다. 

#include <iostream>

using namespace std;

int Count(int* arr, int n, int x);
int SequentialSearch(int* arr, int n, int x); // LinearSearch
int SortedCount(int* arr, int n, int x);
int SortedCountHelper(int* arr, int n, int x, int start);
void InsertionSort(int* arr, int n);
void Print(int* arr, int size);

int main()
{
	int arr[] = { 8, 1, 1, 3, 2, 5, 1, 2 , 1, 1 }; // 정렬되지 않은 데이터를 가정
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Count 9 = " << Count(arr, n, 9) << endl;
	cout << "Count 2 = " << Count(arr, n, 2) << endl;
	cout << "Count 8 = " << Count(arr, n, 8) << endl;
	cout << "Count 1 = " << Count(arr, n, 1) << endl;
	cout << endl;

	cout << "Search 2 = " << SequentialSearch(arr, n, 2) << endl;
	cout << "Search 5 = " << SequentialSearch(arr, n, 5) << endl;
	cout << "Search 9 = " << SequentialSearch(arr, n, 9) << endl;
	cout << endl;

	InsertionSort(arr, n);

	Print(arr, n);

	cout << "Sorted Count 9 = " << SortedCount(arr, n, 9) << endl;
	cout << "Sorted Count 2 = " << SortedCount(arr, n, 2) << endl;
	cout << "Sorted Count 8 = " << SortedCount(arr, n, 8) << endl;
	cout << "Sorted Count 1 = " << SortedCount(arr, n, 1) << endl;
	cout << endl;

	return 0;
}

// 배열 arr에 x가 몇 번 나오는지 반환
int Count(int* arr, int n, int x)
{
	// TODO:
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			count++;
		}
	}

	return count;
}

// 배열 arr에 x가 있으면 index 반환, 없으면 -1 반환
int SequentialSearch(int* arr, int n, int x)
{
	// TODO:
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			return i;
		}
	}

	return -1;
}

// 정렬된 배열에서 x가 몇 번 나오는지 반환
int SortedCount(int* arr, int n, int x)
{
	int i = SequentialSearch(arr, n, x);

	if (i >= 0)
		return SortedCountHelper(arr, n, x, i + 1) + 1;
	else
		return 0;
}

int SortedCountHelper(int* arr, int n, int x, int start)
{
	// TODO: 
	int count = 0;
	for (int i = start; i < n; i++)
	{
		if (arr[i] == x)
		{
			count++;
		}
		else
		{
			return count; // 조기 종료
		}
	}

	return 0;
}

// 정렬할 때 사용
void InsertionSort(int* arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// 출력 결과
/*
Count 9 = 0
Count 2 = 2
Count 8 = 1
Count 1 = 5

Search 2 = 4
Search 5 = 5
Search 9 = -1

1 1 1 1 1 2 2 3 5 8
Sorted Count 9 = 0
Sorted Count 2 = 2
Sorted Count 8 = 1
Sorted Count 1 = 5
*/