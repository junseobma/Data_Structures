#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

struct Element
{
	int key;
	char value;
};

bool CheckSorted(int* arr, int size);
void Print(int* arr, int size);
void Print(Element* arr, int size);

int main()
{
	// 비교 횟수 세보기, 더 효율적인 방법은 없을까?
	// https://en.wikipedia.org/wiki/Sorting_algorithm
	{
		ofstream ofile("log.txt");
		for (int size = 1; size < 1000; size++)
		{
			int count = 0;
			int* arr = new int[size];
			for (int s = 0; s < size; s++) {
				arr[s] = size - s;
			}

			//TODO: count ++;

			//cout << size << ", " << count << endl;
			ofile << size << ", " << count << endl;
			// Print(arr, size);

			delete[] arr;
		}

		ofile.close();
	}



	// 안정성 확인(unstable)
	{
		Element arr[] = { {2, 'a'}, {2, 'b'}, {1, 'c'} };
		int size = sizeof(arr) / sizeof(arr[0]);

		Print(arr, size); // arr이 Element의 배열

		// TODO:
		int min_index;
		for (int i = 0; i < size - 1; i++)
		{
			min_index = i;

			for (int j = i + 1; j < size; j++)
			{
				if (arr[j].key < arr[min_index].key)
					min_index = j;
			}
			swap(arr[i], arr[min_index]);

			Print(arr, size);
			cout << endl;
		}

		Print(arr, size); // arr이 Element의 배열
	}
	// [2, 2, 1]
	// [1, 2, 2] // 첫 2가 마지막으로 이동

	return 0;
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
// log.txt 파일 생성. 구글 스프레드시트로 그래프 확인가능.

// 안정성 확인(unstable)
2 2 1
a b c
1 2 2
c b a

1 2 2
c b a

1 2 2
c b a
*/