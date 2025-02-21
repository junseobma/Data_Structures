// 순열(Permutations)

#include <iostream>
#include <algorithm> // swap

using namespace std;

void RecurPermutations(char* arr, int left, int right);


int main()
{
	// Permutations
	char arr[] = "abcd";

	RecurPermutations(arr, 0, 0);
	cout << endl;

	RecurPermutations(arr, 0, 1);
	cout << endl;

	RecurPermutations(arr, 0, 2);
	cout << endl;

	RecurPermutations(arr, 0, 3);
	cout << endl;

	return 0;
}

void RecurPermutations(char* arr, int left, int right)
{
	if (left == right)
	{
		for (int i = 0; i <= right; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = left; i <= right; i++)
		{
			swap(arr[left], arr[i]);

			RecurPermutations(arr, left + 1, right);

			swap(arr[left], arr[i]);
		}
	}
}

// 출력 결과
/*
a

a b
b a

a b c
a c b
b a c
b c a
c b a
c a b

a b c d
a b d c
a c b d
a c d b
a d c b
a d b c
b a c d
b a d c
b c a d
b c d a
b d c a
b d a c
c b a d
c b d a
c a b d
c a d b
c d a b
c d b a
d b c a
d b a c
d c b a
d c a b
d a c b
d a b c
*/