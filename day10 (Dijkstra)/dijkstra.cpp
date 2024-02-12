#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// Dijkstra : 그래프에 서로 다른 가중치가 포함된 최단거리

// 단순 최단경로 - BFS

// Bellman Ford : 그래프에 음수 가중치 포함. 싸이클 방지하는 코드 포함

// Floyd Warshall : 음수 가중치 포함. 싸이클 방지 코드 미포함



// Dijkstra -> BFS와 유사
// dist 정답배열 : 0 ~ 특정 노드까지의 최단 거리 기록
// Queue -> PQ : 노드 추출시 인접해있는 경로를 추출하는 것이 아니라, 최소 비용이 드는 경로를 추출

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
	// 1. PQ 준비
	priority_queue<Edge> pq;

	// 2. 정답배열 만들기
	int dist[100] = { 0, };

	// 2_1. 정답배열 초기화(MAX값으로)
	for (int i = 0; i < 100; i++)
	{
		dist[i] = 2134567890;
	}

	// 2_2. 시작 노드 dist에 기록
	dist[node] = 0;

	// 3. 시작노드 등록
	pq.push({ node, 0 });

	while (!pq.empty())
	{
		// 4. 큐 맨 앞 노드 확인 및 추출
		Edge now = pq.top(); // 현재 now 위치에 있다
		pq.pop(); // 특정 A 노드 ~ now 노드까지의 최단거리임을 확정

		// 5. 추출된 노드에서 갈 수 있는 다른 후보 탐색
		for (int i = 0; i < alis[now.num].size(); i++)
		{
			Edge next = alis[now.num][i]; //현재 now 에서 갈 수 있는 후보를 하나씩 확인
			int nextcost = next.cost + dist[now.num]; // now까지의 누적 cost + now->next costs

			if (dist[next.num] <= nextcost) continue; // dist에 이미 next 노드까지의 더 낮은 cost값이 기록되어있으면 continue
			
			pq.push({ next.num, nextcost });
			dist[next.num] = nextcost; // 시작 ~ 다음노드 까지의 cost 기록
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