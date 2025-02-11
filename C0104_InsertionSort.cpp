// 삽입 정렬(Insertion Sort)

// 1. 배열의 두 번째 요소부터 시작하여, 현재 요소를 정렬된 부분에 삽입할 위치를 찾습니다.
// 2. 올바른 위치를 찾을 때까지 왼쪽으로 이동하며 요소들을 한 칸씩 뒤로 밀어줍니다.
// 3. 위치를 찾으면 해당 자리에 현재 요소를 삽입합니다.
// 4. 이 과정을 배열 끝까지 반복하면 정렬이 완료됩니다.

// swap보다 shift가 더 효율적이므로 버블정렬 보다 삽입정렬이 더 효율적이다. 
// 3 value assignments per swap / 1 value assignment per spot

#include <iostream>

using namespace std;

bool CheckSorted(int* arr, int size);
void Print(int* arr, int size);

int main()
{
	// 오른쪽으로 하나씩 밀기 (삽입 정렬의 중간 단계)
	{
		int arr[] = { 1, 2, 4, 5, 3, 6 };
		int n = sizeof(arr) / sizeof(arr[0]);

		Print(arr, n);

		// i = 4인 경우에 대해서 구현
		int i = 4;
		int key = arr[i];
		int j = i;
		for (; j > 0 && arr[j - 1] > key; j--)
		{
			// TODO:
			//if (arr[j - 1] <= key)
			//	break;

			arr[j] = arr[j - 1];
			
			Print(arr, n);
		}

		// 삽입
		arr[j] = key;

		Print(arr, n);
		cout << endl;
	}

	// Insertion Sort
	{
		//int arr[] = { 8, 3, 2, 5, 1, 2 };
		int arr[] = { 6, 5, 4, 3, 2, 1 }; // Worst
		//int arr[] = { 1, 2, 3, 4, 5, 6 }; // Best
		int n = sizeof(arr) / sizeof(arr[0]);

		// 나의 구현
		cout << "start ";
		Print(arr, n);
		cout << endl;

		for (int i = 1; i < n; i++)
		{
			int key = arr[i];
			int j = i;
			for (; j > 0 && arr[j - 1] > key; j--)
			{
				arr[j] = arr[j - 1];

				cout << "Inner ";
				Print(arr, n);
			}

			// 삽입
			arr[j] = key;

			cout << "Outer ";
			Print(arr, n);
			cout << endl;
		}
		
		cout << "result ";
		Print(arr, n);
		cout << endl;
	}

	// Stability
	// 옆으로 한칸씩 이동할 때 순서가 바뀌지 않으므로 stable 하다. 
}

bool CheckSorted(int* arr, int size)
{
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
1 2 4 5 3 6
1 2 4 5 5 6
1 2 4 4 5 6
1 2 3 4 5 6

start 6 5 4 3 2 1

Inner 6 6 4 3 2 1
Outer 5 6 4 3 2 1

Inner 5 6 6 3 2 1
Inner 5 5 6 3 2 1
Outer 4 5 6 3 2 1

Inner 4 5 6 6 2 1
Inner 4 5 5 6 2 1
Inner 4 4 5 6 2 1
Outer 3 4 5 6 2 1

Inner 3 4 5 6 6 1
Inner 3 4 5 5 6 1
Inner 3 4 4 5 6 1
Inner 3 3 4 5 6 1
Outer 2 3 4 5 6 1

Inner 2 3 4 5 6 6
Inner 2 3 4 5 5 6
Inner 2 3 4 4 5 6
Inner 2 3 3 4 5 6
Inner 2 2 3 4 5 6
Outer 1 2 3 4 5 6

result 1 2 3 4 5 6
*/