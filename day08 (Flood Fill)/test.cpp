#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[1000][1000];
//int visited[1000][1000];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int cnt;

struct Point
{
	int y;
	int x;
};

int bfs(Point st)
{
	int minVal = 0;
	queue<Point> q;
	map[st.y][st.x] = 1;
	q.push(st);

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Point next;
			next.y = now.y + dy[i];
			next.x = now.x + dx[i];

			if (next.y < 0 or next.x < 0 or next.y >= N or next.x >= M) continue;
			if (map[next.y][next.x] != 0) continue;
			map[next.y][next.x] = map[now.y][now.x] + 1;
			minVal = map[next.y][next.x];

			q.push(next);
		}
	}
	return minVal;
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	Point st = { 0 };

	cin >> st.y >> st.x;

	int minVal = bfs(st);

	cout << minVal - 1;
}