#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Flood Fill = BFS + 2차원이상 좌표
// 특정 좌표상에 있는 노드 기준으로 BFS 탐색하는 방법
// 최단경로를 맵상에서 갈 수 있다


// BFS의 과정
// 1. 큐를 만든다
// 2. 시작점을 큐에 등록
// 3. 큐의 맨 앞 값 확인
// 4. 확인한 값 추출(현재 노드)
// 5. 연결된 다음 경로 탐색(next 후보지 검색)
// 6. 연결된 좌표를 큐에 등록
// 3~6 반복 (until q.empty() == true)

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
	// 1. 큐 만든다
	queue<Node> q;

	// 2. 시작 노드 큐에 등록
	q.push({ y, x });
	visited[y][x] = 1;

	while (!q.empty())
	{
		// 3. 맨 앞에 있는 노드 확인
		Node now = q.front();

		// 4. 추출
		q.pop(); // 현재 now 의 위치에 있다

		// 5. next 탐색
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];

			//범위체크
			if (ny >= 5 or nx >= 5 or ny < 0 or nx < 0) continue;
			if (visited[ny][nx] != 0) continue;
			if (M[ny][nx] < 0) continue;

			// 6. 후보지 등록 예약
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