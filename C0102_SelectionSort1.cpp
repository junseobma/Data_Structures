#include <iostream>

using namespace std;

bool CheckSorted(int* a, int b);

int main()
{
	// 3개 정렬
	{
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int i = 0; i < 3; i++)
				{
					int arr[3] = { i, j, k };
					int size = sizeof(arr) / sizeof(arr[0]);

					// 출력
					for (int e = 0; e < size; e++)
					{
						cout << arr[e] << " " << flush;
					}

					cout << " -> " << flush;

					// TODO: 정렬 해보기
					if (arr[1] > arr[2])
					{
						swap(arr[1], arr[2]);
					}
					if (arr[0] > arr[1])
					{
						swap(arr[0], arr[1]);
					}

					if (arr[1] > arr[2])
					{
						swap(arr[1], arr[2]);
					}

					// 다른 구현법
					//if (arr[0] > arr[1])
					//	swap(arr[0], arr[1]);
					//if (arr[1] > arr[2])
					//	swap(arr[1], arr[2]);
					//if (arr[0] > arr[1])
					//	swap(arr[0], arr[1]);

					// 출력
					for (int e = 0; e < size; e++)
					{
						cout << arr[e] << " " << flush;
					}

					cout << boolalpha;
					cout << CheckSorted(arr, size); // 정렬 확인
					cout << endl;
				}
			}
		}
	}

	return 0;
}

bool CheckSorted(int* arr, int size)
{
	// TODO: 정렬 확인 함수 구현
	if (arr[2] >= arr[1])
	{
		if (arr[1] >= arr[0])
		{
			return true;
		}
	}

	// 다른 구현법
	//for (int i = 0; i < size - 1; i++) {
	//	if (arr[i] > arr[i + 1])
	//		return false;
	//}
	//return true;

	return false;
}

// 출력 결과 정렬 전    |  정렬 후
/*
0 0 0  -> 0 0 0 true   |  0 0 0  -> 0 0 0 true
1 0 0  -> 1 0 0 false  |  1 0 0  -> 0 0 1 true
2 0 0  -> 2 0 0 false  |  2 0 0  -> 0 0 2 true
0 1 0  -> 0 1 0 false  |  0 1 0  -> 0 0 1 true
1 1 0  -> 1 1 0 false  |  1 1 0  -> 0 1 1 true
2 1 0  -> 2 1 0 false  |  2 1 0  -> 0 1 2 true
0 2 0  -> 0 2 0 false  |  0 2 0  -> 0 0 2 true
1 2 0  -> 1 2 0 false  |  1 2 0  -> 0 1 2 true
2 2 0  -> 2 2 0 false  |  2 2 0  -> 0 2 2 true
0 0 1  -> 0 0 1 true   |  0 0 1  -> 0 0 1 true
1 0 1  -> 1 0 1 false  |  1 0 1  -> 0 1 1 true
2 0 1  -> 2 0 1 false  |  2 0 1  -> 0 1 2 true
0 1 1  -> 0 1 1 true   |  0 1 1  -> 0 1 1 true
1 1 1  -> 1 1 1 true   |  1 1 1  -> 1 1 1 true
2 1 1  -> 2 1 1 false  |  2 1 1  -> 1 1 2 true
0 2 1  -> 0 2 1 false  |  0 2 1  -> 0 1 2 true
1 2 1  -> 1 2 1 false  |  1 2 1  -> 1 1 2 true
2 2 1  -> 2 2 1 false  |  2 2 1  -> 1 2 2 true
0 0 2  -> 0 0 2 true   |  0 0 2  -> 0 0 2 true
1 0 2  -> 1 0 2 false  |  1 0 2  -> 0 1 2 true
2 0 2  -> 2 0 2 false  |  2 0 2  -> 0 2 2 true
0 1 2  -> 0 1 2 true   |  0 1 2  -> 0 1 2 true
1 1 2  -> 1 1 2 true   |  1 1 2  -> 1 1 2 true
2 1 2  -> 2 1 2 false  |  2 1 2  -> 1 2 2 true
0 2 2  -> 0 2 2 true   |  0 2 2  -> 0 2 2 true
1 2 2  -> 1 2 2 true   |  1 2 2  -> 1 2 2 true
2 2 2  -> 2 2 2 true   |  2 2 2  -> 2 2 2 true
*/