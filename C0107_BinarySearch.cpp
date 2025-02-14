// 이진 탐색

// 정렬된 상태에서 탐색(left 이상, right 이하)
// 전체에서 가운데를 추측(left + right / 2 = 정수 버림)
// 가운데 값을 찾으려는 값과 비교하여 탐색 범위를 축소
// 찾을 때까지 반복

#include <iostream>
#include <iomanip>      // std::setw

#include <cassert>

using namespace std;

void PrintHelper(int* arr, int n, int left, int right);
int BinarySearch(int* arr, int n, int x);

int main()
{
	// 정렬된 배열 (임의의 배열 사용 가능, 여기서는 디버깅 편의를 위해 index와 같은 값)
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int arr[] = { 2, 4, 5, 5, 6, 8, 9, 10, 12, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);

	assert(n > 0);

	// 정렬이 안된 배열은 미리 정렬

	BinarySearch(arr, n, 3);

	return 0;
}

void PrintHelper(int* arr, int n, int left, int right)
{
	cout << "[" << left << "," << right << "]" << endl;

	cout << "Indices: ";
	for (int i = left; i <= right; i++)
		cout << setw(2) << i << " ";
	cout << endl;

	cout << "Values : " << setw(2);
	for (int i = left; i <= right; i++)
		cout << setw(2) << arr[i] << " ";
	cout << endl;
}

int BinarySearch(int* arr, int n, int x) // 이진 탐색
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		PrintHelper(arr, n, left, right);

		int middle = (left + right) / 2 ; // 정수 나누기 (버림)
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
		else
		{
			cout << "Found " << middle << endl;
			return middle;
		}

		cout << endl;
	}

	cout << "Not found" << endl;
	return -1; // Not found
}


// 출력 결과
/*
[0,9]
Indices:  0  1  2  3  4  5  6  7  8  9
Values :  0  1  2  3  4  5  6  7  8  9
middle 4
right 3

[0,3]
Indices:  0  1  2  3
Values :  0  1  2  3
middle 1
left 2

[2,3]
Indices:  2  3
Values :  2  3
middle 2
left 3

[3,3]
Indices:  3
Values :  3
middle 3
Found 3
*/