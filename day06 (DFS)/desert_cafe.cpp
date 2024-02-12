#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// 다양한 경로 요구 -> 80% 이상은 재귀, 백트래킹 문제
// 특히, 가장 긴 or 가장 큰 ~~~ -> DFS 문제

// now -> now + 1 에서 어떤 규칙이 필요한가
// 1. 진행방향 그대로 -> dir = ndir(new dir)
// 2. 방향을 바꾼다 -> ndir = dir+1

int N;
int M[30][30];
int dr[] = { 1, 1, -1, -1 };
int dc[] = { 1, -1 ,-1, 1 };
int visited[110]; // index = 디저트 종류, value = 경로상에 있는가
vector<int>path;
int destRow, destCol; // 도착 좌표. 출발지의 좌하 방향 1칸 위치.
int ans;

void input()
{
	memset(visited, 0, sizeof(visited));
	path.clear();
	ans = 0;

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			M[i][j] = -1;
		}
	}

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> M[i][j];
		}
	}
}

void dfs(int row, int col, int dir)
{
	// 기저
	if (row == destRow && col == destCol)
	{
		if (ans < path.size())
		{
			ans = path.size();
			return;
		}
	}
	
	for (int ndir = dir; ndir <= dir + 1; ndir++)
	{
		if (ndir >= 4)continue;
		int nr = row + dr[ndir];
		int nc = col + dc[ndir];

		// 판별
		if (M[nr][nc] == -1)continue; //맵을 벗어났다
		if (visited[M[nr][nc]] == 1)continue; // 이미 들른 곳이다

		// 기록 및 처리
		visited[M[nr][nc]] = 1;
		path.push_back(M[nr][nc]);

		// 가라
		dfs(nr, nc, ndir);

		// 복구
		visited[M[nr][nc]] = 0;
		path.pop_back();
	}
}

void solution()
{
	// 모든 다양한 경로 진행하기
	for (int row = 1; row <= N; row++)
	{
		for (int col = 1; col <= N; col++)
		{
			destRow = row + 1;
			destCol = col - 1;

			//기록 및 처리
			visited[M[row][col]] = 1;
			path.push_back(M[row][col]);

			//가라
			dfs(row, col, 0); // 다음으로 진행할 때, 다음 좌표 계산 후 넣어줌
							  // 시작점에 대해 세팅을 하고 진행

			//복구
			visited[M[row][col]] = 0;
			path.pop_back();
		}
	}
	if (ans < 4)
	{
		ans = -1; // 사각형을 만들지 못한 경우
	}
}

int main() {
	int T;
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		input();
		solution();
		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}