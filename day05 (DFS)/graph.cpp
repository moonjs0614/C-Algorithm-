#include <iostream>
#include <vector>

using namespace std;

// �׷��� : ������ ���� ������ ���踦 ��Ÿ���� �ڷ� ����
// ������ �������� �̷���� �ڷ� ����

// �׷����� ���� (������ ����, ����ġ�� ����)
// ����(�ܹ���) �׷��� / ����(�����) �׷���
// ����ġ �׷��� / ������ġ(����ġ�� ���� ����) �׷���  ==> ����ġ ���ο� ���� ������ �� �ִ� �˰����� �ٲ��
// ex) �ִ� ��� / �ִ� �Ÿ�
// �ִ� ��� : BFS
// �ִ� �Ÿ�(����ġ �ִ� ���) : Dijkstra(��� ����ġ)
//                             : BellmanFord(���� ����ġ)

// ��� ������ ���ΰ�?
// index : ��� ��ȣ
// value : ���� ���� (����Ǹ� 1. ���� �ȵǸ� 0)

int mat[4][4];
int N, M; // N���� ���, M���� ���� ����

int main() {

	/*
	4 4
	0 3
	1 0
	1 2
	2 3
	*/

	cin >> N >> M;

	//for (int i = 0; i < M; i++)
	//{
	//	int from, to;
	//	cin >> from >> to;
	//	mat[from][to] = 1;
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << mat[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	// ����Ǿ� �־�? Query
	//int a, b;
	//cin >> a >> b;
	//cout << mat[a][b] << endl;

	//===============================================================

	// vector : �޸� ���� �Ҵ�
	// vector<������ �ڷ���>�̸�;
	vector<int>v;

	// �����͸� �� �ڿ� �߰� -> .push_back(value);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// �����͸� �� �ڿ������� ���� -> .pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();

	//================================================================

	// ���� ����Ʈ ���
	// index : ��� ��ȣ
	// value : �� ��尡 ����� ��� ��ȣ

	vector<int>alis[4];
	for (int i = 0; i < N; i++)
	{
		int from, to;
		cin >> from >> to;
		alis[from].push_back(to); // from -> to ����ȣ�� �״�� ����
	}

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < alis[i].size(); j++)
		{
			cout << alis[i][j] << " ";
		}
		cout << endl;
	}
	
	int a, b;
	cin >> a >> b;
	int flag = 0;
	for (int i = 0; i < alis[a].size(); i++)
	{
		if (b == alis[a][i])
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		cout << "����Ǿ��ִ�" << endl;
	}


	// ���� ���
	// : ������ ����, ������ �޸𸮸� ���� �Ҹ��Ѵ� (V^2)
	// : ��ȸ�ÿ� ���� �ѹ����� ��ȸ ����

	// ���� ����Ʈ
	// : ������ ���� �ʴ�. ������ �޸𸮸� ���� �Ҹ��Ѵ� (V+E)
	// : �ٸ�, ��ȸ�ÿ� V ����� ������ŭ Ȯ���ؾ� ��
}