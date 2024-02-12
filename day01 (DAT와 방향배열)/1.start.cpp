#include <iostream>
using namespace std;

int main() {

	int arr[10] = { 27, 30, 28, 22, 7, 10, 20, 1, 11, 5 };
	//데이터타입 + 이름 + 크기 = {};
	//cout << arr[4]; // []의미 = 배열의 시작 주소 + 데이터타입 크기(4byte)*2
					 // 해당하는 주소에 쓰여진 값

	cout << arr << endl; //배열의 이름: 메모리상의 주소값
	cout << arr[0] << endl;
	cout << arr + 1 << endl;
	cout << arr + 2 << endl;
}