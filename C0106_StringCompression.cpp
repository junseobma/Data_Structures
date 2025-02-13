// 문자열 압축(StringCompression)

//  
// 

#include <iostream>
#include <cassert>

using namespace std;

void InsertionSort(char* arr, int n);
int Count(char* arr, int n, char x);

int main()
{
	// 문제
	// - 어떤 알파벳에 몇 번 나오는지로 출력
	// - 예시) aaabbccdddeeeff -> a3b2c2d3e3f2
	// - 알파벳은 총 26 글자	
	// cout << int('a') << " " << int('z') << endl; // 97 122

	// char arr[] = "ababcdfdceeefda";
	// char arr[] = "a";
	char arr[] = "czxvopzxczxcababcdfdceeedag";
	int n = sizeof(arr) - 1; // - 1 마지막 안보이는 '\0' 제외

	assert(n >= 1); // 글자가 하나이상이라고 가정, 글자가 없으면 if로 아예 수행을 안하도록 처리 가능

	cout << arr << endl;

	// 풀이 1. 모든 알파벳에 대해서 Count()
	// 힌트: 소문자 알파벳 'a'~'z'는 int로는 97~122에 대응
	// 단점: 없는 알파벳도 세야 한다.

	int table[26] = { 0 }; // 표를 사용할 수도 있고 사용하지 않을 수도 있음, 모든 값을 0으로 초기화

	for (int i = 0; i < 26; i++)
	{
		// 방법1: 표를 만들고 나중에 몰아서 출력하는 방법

		// 나의 구현 1 - Count() 사용전
		//for (int j = 0; j < n; j++)
		//{
		//	if (arr[j] == char(i + 97)) // 특정 알파벳이라면
		//	{
		//		table[i]++;
		//	}
		//}

		// 나의 구현 2 - Count() 사용후
		table[i] = Count(arr, n, char(i + 97));


		// 방법2: 표를 만들지 않고 직접 출력하는 방법

		// 나의 구현 1 - Count() 사용전
		//int count = 0;
		//for (int j = 0; j < n; j++)
		//{
		//	if (arr[j] == char(i + 97)) // 특정 알파벳이라면
		//	{
		//		count++;
		//	}
		//}
		//if (count > 0)
		//{
		//	cout << char(i + 97) << count;
		//}

		// 나의 구현 2 - Count() 사용후
		int count = Count(arr, n, char(i + 97));
		if (count > 0)
		{
			cout << char(i + 97) << count;
			//cout << char(i+97) << table[i] << flush; // 다른 구현법
		}
	}
	cout << endl;

	// 방법1 출력
	for (int i = 0; i < 26; i++)
	{
		if (table[i] > 0)
			cout << char(i + 97) << table[i];
	}
	cout << endl << endl;


	// 풀이 2. 정렬 후 찾기
	// 여기서는 별도의 문자열을 만드는 것이 아니라 출력이 목표
	// Table도 만들지 않음

	InsertionSort(arr, n);

	cout << arr << endl;

	char character = arr[0];
	int count = 1;

	//cout << character;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == character)
		{
			// TODO: ...
			count++;
		}
		else
		{
			// TODO: ...
			cout << character << count;
			character = arr[i];
			count = 1;
		}
	}

	cout << character;
	cout << count << endl; // 마지막 count 출력

	return 0;
}

void InsertionSort(char* arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) // <- while 사용
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

int Count(char* arr, int n, char x)
{
	int count = 0;
	for (int i = 0; i < n; i++) // start index 사용
	{
		if (arr[i] == x)
			count++;
	}

	return count;
}

// 출력 결과
/*

*/