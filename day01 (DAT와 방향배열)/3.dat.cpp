#include <iostream>
using namespace std;

// DAT : Direct Address(Access) Table;

// DAT의 index : 어떤 숫자
// DAT의 value : 있다 or 없다

// DAT의 size : 숫자 범위 + 1

int main() {

	int arr[10] = { 27, 30, 28, 22, 7, 10, 20, 1, 11, 5 };
	int Q;
	cin >> Q;

	int DAT[31] = { 0, };
	for (int i = 0; i < 10; i++)
	{
		DAT[arr[i]] = 1; // 있다. 기록
						 // index = 어떤 숫자
						 // value = 있다 / 없다
	}
	// N번 기록

	for (int i = 0; i < Q; i++)
	{
		int num = 0;
		cin >> num;
		cout << num << " : " << DAT[num] << endl;
	}
	// Q번 확인

	// 연산량 = Q + N   (DAT 안쓰면 Q*N)


	// DAT의 장점: 속도가 빠르다
	// DAT의 단점: 메모리 공간 사용량이 많다 / 음수 인덱싱, 물자열 인덱싱 불가 / out of index가 뜨지 않음

	// DAT: 배열 활용. 배열의 인덱스를 의미있게 사용.


	return 0;
}