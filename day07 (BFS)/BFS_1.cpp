#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// 그래프(노드와 간선으로 구성) 완전 탐색
// 특정 노드에서 갈 수 있는 모든 노드를 확인

// DFS : Depth First Search. 깊이 우선 탐색
// -> 탐색 방법 : 재귀

// BFS : Breadth First Search. 넓이 우선 탐색
// -> 탐색 방법 : Queue
// -> 특징 : 발견된 순서대로 기록할 수 있는 자료구조가 있으면 된다(그게 큐)
//         : 그래프에 있는 "연결된 모든 노드"가 일렬로 나열되어 있는것을 확인


// 큐 명령어
// q.push(value) : value를 큐의 맨 마지막에 등록
// q.front() : 큐의 맨 앞에 있는 value 확인
// q.pop() : 큐의 맨 앞에 있는 value부터 추출
// q.empty() : 큐가 비었는지 확인

// 1. 큐 라는 대기열을 준비
// 2. 특정 노드(시작점)를 큐에 등록
// 3. 맨 앞에 있는 노드를 확인하고 추출
// 4. 지금 추출된 노드와 연결되어 있었던 다른 노드를 탐색 (now -> next)
// 5. next에 해당하는 다른 노드들을 큐에 등록

/*
Test Case

6 7
1 2
1 4
2 3
2 5
4 5
4 6
3 6

*/

int N, M;
vector<int>alis[15];
int visited[15];

void bfs(int node)
{
	// 1. 큐 대기열 준비
	queue<int>q;

	// 2. 시작점 큐에 등록
	q.push(node); // 시작점(1번 노드) 등록
	visited[node] = 1;


	while (!q.empty())
	{
		// 3. 맨 앞 노드 확인하고 추출
		int now = q.front(); // 맨 앞 값 확인
		q.pop(); // 노드 추출

		cout << now << " ";

		// 4. 추출된 노드와 연결되어 있었던 다른 노드 탐색
		for (int i = 0; i < alis[now].size(); i++)
		{
			// now > next 가 될 수 있는 다른 후보들 찾기
			int next = alis[now][i];

			if (visited[next] != 0)continue; //판별

			// 5. next에 해당하는 다른 노드를 큐에 등록
			q.push(next); // now -> next 로 가도 된다
			visited[next] = visited[now] + 1; // 기록
		}
	}
	cout << endl;

	for (int i = 1; i <= 6; i++)
	{
		cout << i << " = " << visited[i] << endl;
	}
}

// visited 체크 : index = 노드번호 / value = 방문했는가?


/*
BFS 기본 탐색방법
1. 큐 대기열 준비
2. 시작점을 큐에 등록
3. 맨 앞 노드를 확인하고 추출
4. 추출된 노드와 연결되어있던 다른 노드 탐색
5. next 에 해당하는 다른 노드를 큐에 등록

3~5를 큐가 빌 때까지 반복
*/



int main() {

	/*q.push(1);
	q.push(11);
	q.push(123);
	q.push(14);
	q.push(156);
	q.push(124);
	q.push(1);
	q.pop();*/

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		alis[from].push_back(to);
		alis[to].push_back(from);
	}
	bfs(1);
}

// DFS VS BFS
// 1. DFS
// : 다양한 경로를 탐색. 한 방향으로 갈 수 있는데까지 간다
// : ex) 최장 경로, 모든 case, 다양한 case
// : 효율을 위해 가지치기 고려 필요

// 2. BFS
// : 발견되는 순서대로 간다. 인접한 노드부터 탐색
// : 몇 차만에 발견되는지
// : ex) 최대한 적은 개수의 노드를 거치면서 목적지까지 갈 수 있는 방법