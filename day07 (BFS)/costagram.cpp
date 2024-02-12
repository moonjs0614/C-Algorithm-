#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> v[100001];
int visited[100001];

int bfs(int st)
{
	int cnt = 0;
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
			
			cnt++;
			visited[next] = 1;
			q.push(v[now][i]);
		}
	}
	return cnt;
}

int main()
{
	//freopen("sample_input.txt", "r", stdin);

	cin >> N >> M;
	int from, to;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	int st;
	cin >> st;

	int cnt = bfs(st);

	cout << cnt;
}