#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// Dijkstra : �׷����� ���� �ٸ� ����ġ�� ���Ե� �ִܰŸ�

// �ܼ� �ִܰ�� - BFS

// Bellman Ford : �׷����� ���� ����ġ ����. ����Ŭ �����ϴ� �ڵ� ����

// Floyd Warshall : ���� ����ġ ����. ����Ŭ ���� �ڵ� ������



// Dijkstra -> BFS�� ����
// dist ����迭 : 0 ~ Ư�� �������� �ִ� �Ÿ� ���
// Queue -> PQ : ��� ����� �������ִ� ��θ� �����ϴ� ���� �ƴ϶�, �ּ� ����� ��� ��θ� ����

struct Edge
{
	int num;
	int cost;
	bool operator<(const Edge& right) const
	{
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};

vector<Edge> alis[10];
int N, M;

void dijkstra(int node)
{
	// 1. PQ �غ�
	priority_queue<Edge> pq;

	// 2. ����迭 �����
	int dist[100] = { 0, };

	// 2_1. ����迭 �ʱ�ȭ(MAX������)
	for (int i = 0; i < 100; i++)
	{
		dist[i] = 2134567890;
	}

	// 2_2. ���� ��� dist�� ���
	dist[node] = 0;

	// 3. ���۳�� ���
	pq.push({ node, 0 });

	while (!pq.empty())
	{
		// 4. ť �� �� ��� Ȯ�� �� ����
		Edge now = pq.top(); // ���� now ��ġ�� �ִ�
		pq.pop(); // Ư�� A ��� ~ now �������� �ִܰŸ����� Ȯ��

		// 5. ����� ��忡�� �� �� �ִ� �ٸ� �ĺ� Ž��
		for (int i = 0; i < alis[now.num].size(); i++)
		{
			Edge next = alis[now.num][i]; //���� now ���� �� �� �ִ� �ĺ��� �ϳ��� Ȯ��
			int nextcost = next.cost + dist[now.num]; // now������ ���� cost + now->next costs

			if (dist[next.num] <= nextcost) continue; // dist�� �̹� next �������� �� ���� cost���� ��ϵǾ������� continue
			
			pq.push({ next.num, nextcost });
			dist[next.num] = nextcost; // ���� ~ ������� ������ cost ���
		}
	}
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		cout << i << " : " << dist[i] << endl;
	}
}

int main() {

	freopen("sample_input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		alis[from].push_back({ to, cost });
	}

	dijkstra(0);
	return 0;
}