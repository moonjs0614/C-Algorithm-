#include <iostream>
using namespace std;

// 재귀함수 : 다시 돌아오는(실행되는) 함수
// CS에서의 정의 : 자기 자신을 호출해서 하위 작업을 수행하는 기법

//int hello()
//{
//	cout << "hello" << endl;
//
//	return hello();
//}
//
//int main() {
//
//	hello();
//
//	return 0;
//}

// stack overflow 발생

int n;
void func(int now)
{
	// 2. 종료 조건
	cout << now << " ";

	if (n == now)
	{
		
		return;
	}

	// 1. 기본적인 재귀호출
	
	func(now + 1);

	cout << now << " ";
}

//int main() {

	//n = 5;
	//func(0);

	// 중첩을 해야하는데, 횟수가 정해지지 않은 경우
	// --> 재귀를 쓰는것이 용이

	/*for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			for (int k = 1; k <= 6; k++)
				cout << i << j << k << endl;
		}
	}*/
	// 다중 반복문은 메모리에 좋지 않음


//	return 0;
//}


// recursive case : 다음층으로 진행. / 내가 선택할 수 있는 경우의 수가 있는가?
// base case : 언제 종료(return) 할 것인가?


// 주사위 여러개의 눈금

int DAT[10];

void func2(int now)
{
	// 2. 종료조건
	if (n == now)
	{
		for (int i = 0; i < n; i++)
		{
			cout << DAT[i] << " ";
		}
		cout << endl;
		return;
	}

	// 1. 기본적인 재귀호출
	for (int i = 1; i <= 6; i++)
	{
		DAT[now] = i; // index = now번째 주사위 value : 선택한 주사위 눈금
		//cout << i << " ";

		func2(now + 1);

		// cout << now << " ";
	}
}

int main()
{
	cin >> n;
	func2(0);

	return 0;
}