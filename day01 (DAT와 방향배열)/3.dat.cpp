#include <iostream>
using namespace std;

// DAT : Direct Address(Access) Table;

// DAT�� index : � ����
// DAT�� value : �ִ� or ����

// DAT�� size : ���� ���� + 1

int main() {

	int arr[10] = { 27, 30, 28, 22, 7, 10, 20, 1, 11, 5 };
	int Q;
	cin >> Q;

	int DAT[31] = { 0, };
	for (int i = 0; i < 10; i++)
	{
		DAT[arr[i]] = 1; // �ִ�. ���
						 // index = � ����
						 // value = �ִ� / ����
	}
	// N�� ���

	for (int i = 0; i < Q; i++)
	{
		int num = 0;
		cin >> num;
		cout << num << " : " << DAT[num] << endl;
	}
	// Q�� Ȯ��

	// ���귮 = Q + N   (DAT �Ⱦ��� Q*N)


	// DAT�� ����: �ӵ��� ������
	// DAT�� ����: �޸� ���� ��뷮�� ���� / ���� �ε���, ���ڿ� �ε��� �Ұ� / out of index�� ���� ����

	// DAT: �迭 Ȱ��. �迭�� �ε����� �ǹ��ְ� ���.


	return 0;
}