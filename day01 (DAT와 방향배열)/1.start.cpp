#include <iostream>
using namespace std;

int main() {

	int arr[10] = { 27, 30, 28, 22, 7, 10, 20, 1, 11, 5 };
	//������Ÿ�� + �̸� + ũ�� = {};
	//cout << arr[4]; // []�ǹ� = �迭�� ���� �ּ� + ������Ÿ�� ũ��(4byte)*2
					 // �ش��ϴ� �ּҿ� ������ ��

	cout << arr << endl; //�迭�� �̸�: �޸𸮻��� �ּҰ�
	cout << arr[0] << endl;
	cout << arr + 1 << endl;
	cout << arr + 2 << endl;
}