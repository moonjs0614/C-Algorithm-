#include <iostream>
using namespace std;

// ����Լ� : �ٽ� ���ƿ���(����Ǵ�) �Լ�
// CS������ ���� : �ڱ� �ڽ��� ȣ���ؼ� ���� �۾��� �����ϴ� ���

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

// stack overflow �߻�

int n;
void func(int now)
{
	// 2. ���� ����
	cout << now << " ";

	if (n == now)
	{
		
		return;
	}

	// 1. �⺻���� ���ȣ��
	
	func(now + 1);

	cout << now << " ";
}

//int main() {

	//n = 5;
	//func(0);

	// ��ø�� �ؾ��ϴµ�, Ƚ���� �������� ���� ���
	// --> ��͸� ���°��� ����

	/*for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			for (int k = 1; k <= 6; k++)
				cout << i << j << k << endl;
		}
	}*/
	// ���� �ݺ����� �޸𸮿� ���� ����


//	return 0;
//}


// recursive case : ���������� ����. / ���� ������ �� �ִ� ����� ���� �ִ°�?
// base case : ���� ����(return) �� ���ΰ�?


// �ֻ��� �������� ����

int DAT[10];

void func2(int now)
{
	// 2. ��������
	if (n == now)
	{
		for (int i = 0; i < n; i++)
		{
			cout << DAT[i] << " ";
		}
		cout << endl;
		return;
	}

	// 1. �⺻���� ���ȣ��
	for (int i = 1; i <= 6; i++)
	{
		DAT[now] = i; // index = now��° �ֻ��� value : ������ �ֻ��� ����
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