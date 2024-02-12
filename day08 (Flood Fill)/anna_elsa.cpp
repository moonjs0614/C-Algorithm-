#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int y;
	int x;
};

int elsa_y, elsa_x;
int anna_y, anna_x;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int N;
char map[5][5];
int visited[5][5];

void bfs(int y, int x)
{
	queue<Node> q;

	q.push({ y, x });
	visited[y][x] = 1;
	map[y][x] = 1;

	while (!q.empty())
	{
		Node now = q.front();

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];

			if (ny >= N or nx >= N or ny < 0 or nx < 0) continue;
			if (visited[ny][nx] != 0) continue;
			if (map[ny][nx] == '#') continue;

			q.push({ ny, nx });
			visited[ny][nx] = visited[now.y][now.x] + 1;
		}
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j];
		}
	}

	cin >> elsa_y >> elsa_x >> anna_y >> anna_x;

	bfs(elsa_y, elsa_x);

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}