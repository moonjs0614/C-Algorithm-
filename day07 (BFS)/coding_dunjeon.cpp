#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge
{
	int to;
	int cost;
};

int N, M, K;
vector<Edge> v[10];
int dist[11];

void bfs(int st)
{
	queue<int> q;
	q.push(st);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i].to;
			int sum = dist[now] + v[now][i].cost;

			if (sum > K)continue;

			dist[next] = sum;
			q.push(next);
		}
	}
}

int main()
{
	//freopen("sample_input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}

	bfs(0);

	for (int i = 0; i < 11; i++)
	{
		if (dist[i] != 0)
		{
			cout << i << " ";
		}
	}
}