#include <iostream>
using namespace std;

// �ֻ��� ���� N �Է�
// N���� �ֻ��� ���� �������� ���� �� �ִ� ���� ��� ���
// ���� ���� ����ϴ� case ����

int sum;
int N;
int DAT[7]; // index : 1~6 ������ �ֻ��� ��
int path[100];

void func(int now)
{
	// 2. ����
	if (now >= N)
	{
		for (int i = 0; i < N; i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i < 6; i++)
	{
		// 3. �Ǻ�
		if (DAT[i] == 1)
		{
			continue;
		}

		// 4. ��� �� ���
		path[now] = i; // index : now��°, value : ������ ��
		DAT[i] = 1; // indexl : �ش� ������, value : ����ߴ°�

		func(now + 1);

		// 5.��� �� ��� ����
		path[now] = 0;
		DAT[i] = 0;
	}
}


int main() {

	cin >> N;

	func(0);
}