#include <iostream>
using namespace std;


// DFS : Depth First Search / ���� �켱 Ž��
// -> ����Ž��(Ư�� ��忡�� �湮 ������ ��� ��带 Ȯ���ϴ� Ž�� ���)

int mat[5][5];
int N, M;

void dfs(int node)
{
	cout << node << " ";

	//��������
	for (int i = 0; i < N; i++)
	{
		// �Ǻ�
		if (mat[node][i] == 0)
		{
			continue;
		}

		// ��� �� ó��

		// �������� �̵� (i = ��� ��ȣ)
		dfs(i);

		// ��� ���� �� ����
	}
}

int main() {

	/*
	5 4
	0 1
	0 2
	1 3
	1 4
	*/

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		mat[from][to] = 1;
	}

	dfs(0);
}