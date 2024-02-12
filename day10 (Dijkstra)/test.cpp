#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int V, E, P;
struct Edge
{
	int num;
	int cost;
};

struct cmp
{
	bool operator()(Edge a, Edge b)
	{
		return a.cost > b.cost;
	}
};

vector<Edge> v[10001];
int dist[10001];

void input()
{
	cin >> V >> E >> P;
	for (int i = 0; i < E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}
}

void init()
{
	for (int i = 1; i <= V; i++)
	{
		dist[i] = 21e8;
	}
}

void dijkstra(int st)
{
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ st, 0 });
	dist[st] = 0;

	while (!pq.empty())
	{
		Edge now = pq.top();
		pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < v[now.num].size(); i++)
		{
			int nextCost = now.cost + v[now.num][i].cost;
			int tar = v[now.num][i].num;
			if (nextCost < dist[tar])
			{
				dist[tar] = nextCost;
				pq.push({ tar, nextCost });
			}
		}
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	input();
	init();
	dijkstra(1);
	int to_work = dist[V];

	int to_min = dist[P];

	init();
	dijkstra(P);
	int min_to_work = dist[V];

	if (to_min == 21e8)
	{
		cout << "SORRY";
	}
	else
	{
		if (to_min + min_to_work > to_work)
		{
			cout << "SORRY";
		}
		else
		{
			cout << "OKAY";
		}
	}
}