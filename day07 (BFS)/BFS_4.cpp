#include <iostream>
#include <queue>
using namespace std;
int arr[3][3] = {
 {0, 1, 0},
 {1, 0, 1},
 {0, 1, 0},
};
int visited[3];

void bfs(int st)
{
	queue<int> q;
	visited[st] = 1;

	// 유효성 검증은 push 전에 끝낸다


	q.push(st);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			if (arr[now][i] == 1)
			{
				if (visited[i] == 1)
					continue;
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}
int main()
{
	int st = 0;
	bfs(st);
}