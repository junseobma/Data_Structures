#include <iostream>
#include <cassert>

using namespace std;

bool CheckSorted(int* a, int b);
void Print(int* arr, int size);

int main()
{
	// 문제1: 가장 작은 수 찾기
	{
		int arr[] = { 5, 7, 3, 9, 5, 2, 8, 1, 4, 7 };
		int size = sizeof(arr) / sizeof(arr[0]);

		assert(size > 0); // size가 1이상이라고 가정

		// TODO:
		int min_number = arr[0];

		for (int i = 1; i < size; i++)
		{
			if (min_number > arr[i])
			{
				min_number = arr[i];
			}

			// 다른 구현법1
			//min_number = arr[i] < min_number ? arr[i] : min_number;

			// 다른 구현법2
			//min_number = std::min(min_number, arr[i]);
		}

		cout << "Minimum number is " << min_number << endl;
	}


	// 문제2: 가장 작은 수의 인덱스 찾기
	{
		int arr[] = { 5, 3, 7, 9, 7, 2, 8, 3, 4, 5 };
		int size = sizeof(arr) / sizeof(arr[0]);

		assert(size > 0); // size가 1이상이라고 가정

		// TODO:
		int min_number = arr[0];
		int min_index = 0;

		for (int i = 1; i < size; i++)
		{
			if (min_number > arr[i])
			{
				min_number = arr[i];
				min_index = i;
			}
		}

		// 다른 구현법
		//int min_index = 0;
		//for (int i = 1; i < size; i++)
		//{
		//	if (arr[i] < arr[min_index])
		//		min_index = i;
		//}

		cout << "The index of min is " << min_index << endl;
		cout << "Minimum number is " << arr[min_index] << endl;
	}


	// 문제3: Selection Sort
	// 힌트: Swap()
	{
		int arr[] = { 8, 5, 6, 7, 4, 2, 3, 9, 1, 7 };
		int size = sizeof(arr) / sizeof(arr[0]);

		int min_index;
		for (int i = 0; i < size - 1; i++)
		{
			// TODO:
			min_index = i;

			for (int j = i+1; j < size; j++)
			{
				if (arr[j] < arr[min_index])
					min_index = j;
			}
			swap(arr[i], arr[min_index]);

			Print(arr, size);

			cout << boolalpha;
			cout << CheckSorted(arr, size);
			cout << endl;

			// Sorting이 완료됐을 때 조기종료 할 수 없을까? 
			if (CheckSorted(arr, size))
			{
				cout << "i: " << i << endl;
				break;
			}
		}
	}

	return 0;
}

bool CheckSorted(int* arr, int size)
{
	// TODO: 정렬 확인 함수 구현
	//if (arr[2] >= arr[1])
	//{
	//	if (arr[1] >= arr[0])
	//	{
	//		return true;
	//	}
	//}
	//return false;

	// 다른 구현법
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// 출력 결과
/*
//문제1
Minimum number is 1

//문제2
The index of min is 5
Minimum number is 2

//문제3
1 5 6 7 4 2 3 9 8 7
false
1 2 6 7 4 5 3 9 8 7
false
1 2 3 7 4 5 6 9 8 7
false
1 2 3 4 7 5 6 9 8 7
false
1 2 3 4 5 7 6 9 8 7
false
1 2 3 4 5 6 7 9 8 7
false
1 2 3 4 5 6 7 9 8 7
false
1 2 3 4 5 6 7 7 8 9
true
i: 7
*/