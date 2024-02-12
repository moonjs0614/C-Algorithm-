#include <iostream>
using namespace std;

// 1. 함수 + 매개변수 활용
// 2. 지역변수/전역변수 같이 활용


// 1. 지역변수인 경우
//void func()
//{
//	int a = 10;
//}
//
//int main() {
//	int a = 5;
//	cout << a;
//	func();
//	cout << a;
//
//	return 0;
//}

// ======> 출력 : 55

// 2. 전역변수인 경우
//int a;
//void func() {
//	a = 10;
//}
//
//int main() {
//	a = 5;
//	cout << a;
//	func();
//	cout << a;
//
//	return 0;
//}

// =========> 출력 : 510


// 스코프 : 영향을 미치는 범위
// 파일 스코프 : 파일 전체에 영향
// 블록 스코프 : {}블록 내부에서만 영향
// 전역변수 : 파일 스코프에 쓰인 변수들
// 지역변수 : 블록 스코프에 쓰인 변수들

// 어떤 메모리 영역에 쓰인 것인지 구분해서 쓰자


// 매개변수가 있는 경우
int a;
void func(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	
	func(7);

	return 0;
}