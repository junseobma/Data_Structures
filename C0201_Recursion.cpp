// 재귀 호출(Recursion)

// 함수 내부에서 자기 자신과 동일한 함수를 호출하는 것
// 이렇게 하면 함수 호출이 스택에 쌓이면서 메모리를 점점 더 사용
// 만약 종료 조건이 없거나 잘못 설정되면 무한 재귀 호출이 발생하여 스택 오버플로우(Stack Overflow)가 발생

#include <iostream>

using namespace std;

void RecurFunc(int count);

int main()
{
	RecurFunc(5); // 이름이 같은 함수 호출

	return 0;
}

void RecurFunc(int count)
{
	if (count == 0) // <- 종료 조건
		return;

	RecurFunc(count - 1); // <- 출력2

	cout << count << endl;

	//RecurFunc(count - 1); // <- 출력1

	// 실행 위치에 따라 결과가 달라집니다.
}

// 출력 결과
/*
출력1
5
4
3
2
1

출력2
1
2
3
4
5
*/