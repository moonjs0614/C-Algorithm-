#include <iostream>
using namespace std;


// DFS : Depth First Search / 깊이 우선 탐색
// -> 완전탐색(특정 노드에서 방문 가능한 모든 노드를 확인하는 탐색 방법)

int mat[5][5];
int N, M;

void dfs(int node)
{
	cout << node << " ";

	//기저조건
	for (int i = 0; i < N; i++)
	{
		// 판별
		if (mat[node][i] == 0)
		{
			continue;
		}

		// 기록 및 처리

		// 다음으로 이동 (i = 노드 번호)
		dfs(i);

		// 기록 삭제 및 복구
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