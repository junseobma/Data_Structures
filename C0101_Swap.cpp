#include <iostream>

using namespace std;

void MySwapPtr(int* a, int* b);
void MySwapRef(int& a, int& b);
bool CheckSorted(int a, int b);

int main()
{
	// 교환(swap)
	{
		int a = 5;
		int b = 10;

		cout << "Before swapping: " << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;

		MySwapPtr(&a, &b);

		cout << "After MySwapPtr swapping: " << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;

		MySwapRef(a, b);

		cout << "After MySwapRef swapping: " << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}

	// 정렬(sorting)
	{
		int arr[] = { 3, 2 };

		cout << "Before sorting: " << endl;
		cout << arr[0] << " " << arr[1] << endl;

		if (arr[0] > arr[1])
		{
			MySwapRef(arr[0], arr[1]);
		}

		cout << "After MySwapRef sorting: " << endl;
		cout << arr[0] << " " << arr[1] << endl;


		cout << "Before sorting 5x5: " << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				//cout << j << " " << i << " " << (j <= i ? "true" : "false") << endl;
				cout << j << " " << i << " " << boolalpha << CheckSorted(j, i) << endl;
			}
		}

		cout << "After MySwapRef sorting 5x5: " << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				arr[0] = j;
				arr[1] = i;

				if (arr[0] > arr[1])
				{
					MySwapRef(arr[0], arr[1]);
				}

				cout << arr[0] << " " << arr[1] << " " << boolalpha << CheckSorted(arr[0], arr[1]) << endl;
			}
		}
	}

	return 0;
}

void MySwapPtr(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void MySwapRef(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool CheckSorted(int a, int b)
{
	return a <= b;
}