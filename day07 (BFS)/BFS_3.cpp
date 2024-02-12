#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[7];

int N;
int edge;

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
			int next = v[now][i];
			q.push(next);
		}
	}
}

int main()
{
	//freopen("sample_input.txt", "r", stdin);
	cin >> N >> edge;

	for (int i = 0; i < edge; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}

	return 0;
}