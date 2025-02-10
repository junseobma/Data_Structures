// 버블 정렬
// 전반적인 효율성은 떨어진다.
// 하지만 이미 정렬이 되어 있는 경우, 거의 대부분 정렬이된 경우에는 더 빨리 끝난다.
// 위키피디아 링크 - https://en.wikipedia.org/wiki/Bubble_sort

#include <iostream>
#include <cassert>

using namespace std;

struct Element
{
	int key;
	char value;
};

void Print(int* arr, int size);
void Print(Element* arr, int size);

int main()
{
	// Bubble Sort
	{
		// int arr[] = { 5, 1, 4, 2, 8, 3, 1, 7, 2, 1 };
		int arr[] = { 5, 4, 3, 2, 1 }; // Worst Case
		int n = sizeof(arr) / sizeof(arr[0]);
		Print(arr, n);
		cout << endl;

		int m = n;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < m - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
				}
				Print(arr, n);
			}
			m--;
			cout << endl;
		}

		// 다른 구현법1 - 불필요한 반복이 있음
		//for (int i = 0; i < n - 1; i++)
		//{
		//	for (int j = 0; j < n - 1; j++)
		//	{
		//		if (arr[j] > arr[j + 1])
		//		{
		//			swap(arr[j], arr[j + 1]);
		//		}
		//		Print(arr, n);
		//	}
		//	cout << endl;
		//}

		// 다른 구현법2 - 불필요한 반복 줄임
		//for (int i = 0; i < n - 1; i++)
		//{
		//	for (int j = 0; j < n - i - 1; j++) // 'n-1' -> 'n-i-1'
		//	{
		//		if (arr[j] > arr[j + 1])
		//		{
		//			swap(arr[j], arr[j + 1]);
		//		}
		//		Print(arr, n);
		//	}
		//	cout << endl;
		//}
	}

	// Best case
	{
		int arr[] = { 1, 2, 3, 5, 4 }; // Best Case
		int n = sizeof(arr) / sizeof(arr[0]);
		Print(arr, n);
		cout << endl;

		int loopCount = 0;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
				}
				else
				{
					loopCount++;
				}
				Print(arr, n);
			}
			cout << endl;

			if (loopCount == n - i - 1)
				break;
			else 
				loopCount = 0;
		}

		// 다른 구현법
		//for (int i = 0; i < n - 1; i++)
		//{
		//	bool swapped = false;
		//	for (int j = 0; j < n - i - 1; j++)
		//	{
		//		if (arr[j] > arr[j + 1])
		//		{
		//			swap(arr[j], arr[j + 1]);
		//			swapped = true;
		//		}
		//		Print(arr, n);
		//	}
		//	cout << endl;
		//	if (swapped == false)
		//		break;
		//}
	}

	// Stability
	// 안정성 확인(stable)
	{
		Element arr[] = { {2, 'a'}, {2, 'b'}, {1, 'c'} };
		int size = sizeof(arr) / sizeof(arr[0]);

		Print(arr, size); // arr이 Element의 배열

		// TODO:
		for (int i = 0; i < size - 1; i++)
		{
			bool swapped = false;
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j].key > arr[j + 1].key)
				{
					swap(arr[j], arr[j + 1]);
					swapped = true;
				}
				Print(arr, size);
			}
			cout << endl;
			if (swapped == false)
				break;
		}

		Print(arr, size); // arr이 Element의 배열
	}

	return 0;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Print(Element* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i].key << " ";
	cout << endl;

	for (int i = 0; i < size; i++)
		cout << arr[i].value << " ";
	cout << endl;
}

// 출력 결과
/*
// Bubble Sort
5 4 3 2 1

4 5 3 2 1
4 3 5 2 1
4 3 2 5 1
4 3 2 1 5

3 4 2 1 5
3 2 4 1 5
3 2 1 4 5

2 3 1 4 5
2 1 3 4 5

1 2 3 4 5

// Best case
1 2 3 5 4

1 2 3 5 4
1 2 3 5 4
1 2 3 5 4
1 2 3 4 5

1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

// Stability - (stable)
2 2 1
a b c
2 2 1
a b c
2 1 2
a c b

1 2 2
c a b

1 2 2
c a b

*/