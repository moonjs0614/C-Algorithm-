#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> v[11];
int dist[11];
int T;
int visited[11];

void bfs(int st)
{
	queue<int> q;
	visited[st] = 1;
	q.push(st);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			
			if (visited[next] == 1)continue;
			if (next == T)continue;

			dist[next] = dist[now] + 1;
			visited[next] = 1;
			q.push(next);
		}
	}
}

int main() {

	freopen("sample_input.txt", "r", stdin);
	cin >> N >> M;
	int from, to;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	cin >> T;

	bfs(1);

	if (dist[N])
	{
		cout << dist[N];
	}
	else
	{
		cout << -1;
	}
}