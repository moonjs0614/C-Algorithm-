#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Flood Fill = BFS + 2�����̻� ��ǥ
// Ư�� ��ǥ�� �ִ� ��� �������� BFS Ž���ϴ� ���
// �ִܰ�θ� �ʻ󿡼� �� �� �ִ�


// BFS�� ����
// 1. ť�� �����
// 2. �������� ť�� ���
// 3. ť�� �� �� �� Ȯ��
// 4. Ȯ���� �� ����(���� ���)
// 5. ����� ���� ��� Ž��(next �ĺ��� �˻�)
// 6. ����� ��ǥ�� ť�� ���
// 3~6 �ݺ� (until q.empty() == true)

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int M[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{-3, 0, -3, -3, -3},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0}
};
int visited[5][5];
int startY, startX;
struct Node
{
	int y;
	int x;
};

void bfs(int y, int x)
{
	// 1. ť �����
	queue<Node> q;

	// 2. ���� ��� ť�� ���
	q.push({ y, x });
	visited[y][x] = 1;

	while (!q.empty())
	{
		// 3. �� �տ� �ִ� ��� Ȯ��
		Node now = q.front();

		// 4. ����
		q.pop(); // ���� now �� ��ġ�� �ִ�

		// 5. next Ž��
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];

			//����üũ
			if (ny >= 5 or nx >= 5 or ny < 0 or nx < 0) continue;
			if (visited[ny][nx] != 0) continue;
			if (M[ny][nx] < 0) continue;

			// 6. �ĺ��� ��� ����
			q.push({ ny, nx });
			visited[ny][nx] = visited[now.y][now.x] + 1;
		}
	}
}


int main() {
	
	cin >> startY >> startX;
	bfs(startY, startX);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}