#include <iostream>
using namespace std;

// backtracking �������� ��� �˱�?
// N�� ũ�Ⱑ 20~30
// N! 11 ---> ����ġ��
// Ű���� : ����, ����� ��, ����� ��, �ִ�/�ּ��� ���� ���


int N, K;
int arr[1000];
int DAT[11];

//void func(int now, int sum) --> �Ű����� Ȱ��
//{
//	// 2. ���� ���� // base case // ���� ������ΰ�?
//	if (now >= K)
//	{
//		for (int i = 0; i < K; i++)
//		{
//			cout << DAT[i] << " ";
//		}
//		cout << " = " << sum << endl;
//		return;
//	}
//
//	// 1. ��� �⺻ recursive case
//	for (int i = 0; i < N; i++)
//	{
//		// 3. ������ �����ϸ鼭 ����Ǵ� �ڵ�
//		DAT[now] = arr[i]; // index = now��°, value = ���� ��
//		func(now + 1, sum + arr[i]);
//	}
//}

int sum;
//void func(int now)
//{
//	// 2. ���� ���� // base case // ���� ������ΰ�?
//	if (now >= K)
//	{
//		for (int i = 0; i < K; i++) //
//		{
//			cout << DAT[i] << " ";
//		}
//		cout << "= " << sum << endl;
//		return;
//	}
//
//	// 1. ��� �⺻ recursive case
//	for (int i = 0; i < N; i++)
//	{
//		// 5. �Ǻ� - ���� �� ������ �ϴ°� �´°�? -> ���ʿ��� ���� ���̱�
//		if (arr[i] - now > 1)
//		{
//			continue;
//		}
//
//		// 3. ������ �����ϸ鼭 ����Ǵ� �ڵ�
//		DAT[now] = arr[i]; // index = now��°, value = ���� ��
//		sum += arr[i]; // sum ���
//		func(now + 1);
//		sum -= arr[i]; // ��� ����
//		DAT[now] = 0; // �ʱ�ȭ
//	}
//}

int path[10];
//void func(int now) // ������ ���� ���̰� 1���� ���� �� ���� ���� ����
//{
//	// 2. ���� ���� // base case // ���� ������ΰ�?
//	if (now >= K) // K - 1 ������ �̰�, K�� ���� ����
//	{
//		int flag = 0;
//		for (int i = 0; i < K; i++) //
//		{
//			cout << path[i] << " ";
//		}
//		cout << "= " << sum << endl;
//		return;
//	}
//
//	// 1. ��� �⺻ recursive case
//	for (int i = 0; i < N; i++)
//	{
//		// 5. �Ǻ� - ���� �� ������ �ϴ°� �´°�? -> ���ʿ��� ���� ���̱�
//		// �տ��ִ°͸� ���� �ȴ� -> ���� ���� ������ ���ƺ� �ʿ䰡 ����
//		if (now > 0 and
//			(path[now - 1] - arr[i] == 1 or path[now - 1] - arr[i] == -1))
//		{
//			continue;
//		}
//
//		// 3. ������ �����ϸ鼭 ����Ǵ� �ڵ�
//		path[now] = arr[i]; // index = now��°, value = ���� ��
//		sum += arr[i]; // sum ���
//
//		func(now + 1);
//
//		sum -= arr[i]; // ��� ����
//		path[now] = 0; // �ʱ�ȭ
//	}
//}

void func(int now) // �̹� �̾Ҵ� ���� ���� �� ���� ���� ����
{
	// 2. ���� ���� // base case // ���� ������ΰ�?
	if (now >= K) // K - 1 ������ �̰�, K�� ���� ����
	{
		for (int i = 0; i < K; i++) //
		{
			cout << path[i] << " ";
		}
		cout << "= " << sum << endl;
		return;
	}

	// 1. ��� �⺻ recursive case
	for (int i = 0; i < N; i++)
	{
		// 5. �Ǻ� - ���� �� ������ �ϴ°� �´°�? -> ���ʿ��� ���� ���̱�
		// �տ��ִ°͸� ���� �ȴ� -> ���� ���� ������ ���ƺ� �ʿ䰡 ����
		if (now > 0 and
			(path[now - 1] - arr[i] == 1 or path[now - 1] - arr[i] == -1))
		{
			continue;
		}
		if (DAT[arr[i]] == 1)
		{
			continue;
		}

		// 3. ������ �����ϸ鼭 ����Ǵ� �ڵ�
		path[now] = arr[i]; // index = now��°, value = ���� ��
		DAT[arr[i]] = 1; // index = ���� ����, value = ���Ǿ��°�
		sum += arr[i]; // sum ���

		func(now + 1);

		sum -= arr[i]; // ��� ����
		path[now] = 0; // �ʱ�ȭ
		DAT[arr[i]] = 0;
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		arr[i] = i+1;
	}
	func(0);
	return 0;
}

// ���� ����ϴ� ���
// 1. �̰� ���� ���
// 
// 
// 2. �̾ư��鼭 ���
// -> 1) �Ű����� Ȱ�� : sum+arr[i]
// -> 2) �������� Ȱ��