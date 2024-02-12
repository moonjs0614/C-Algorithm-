#include <iostream>
#include <vector>

using namespace std;

// 그래프 : 정점과 정점 사이의 관계를 나타내는 자료 구조
// 정점과 간선으로 이루어진 자료 구조

// 그래프의 종류 (방향의 유무, 가중치의 유무)
// 유향(단방향) 그래프 / 무향(양방향) 그래프
// 가중치 그래프 / 무가중치(가중치가 서로 같은) 그래프  ==> 가중치 여부에 따라 선택할 수 있는 알고리즘이 바뀐다
// ex) 최단 경로 / 최단 거리
// 최단 경로 : BFS
// 최단 거리(가중치 있는 경우) : Dijkstra(양수 가중치)
//                             : BellmanFord(음수 가중치)

// 어떻게 저장할 것인가?
// index : 노드 번호
// value : 연결 유무 (연결되면 1. 연결 안되면 0)

int mat[4][4];
int N, M; // N개의 노드, M개의 간선 정보

int main() {

	/*
	4 4
	0 3
	1 0
	1 2
	2 3
	*/

	cin >> N >> M;

	//for (int i = 0; i < M; i++)
	//{
	//	int from, to;
	//	cin >> from >> to;
	//	mat[from][to] = 1;
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << mat[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	// 연결되어 있어? Query
	//int a, b;
	//cin >> a >> b;
	//cout << mat[a][b] << endl;

	//===============================================================

	// vector : 메모리 동적 할당
	// vector<데이터 자료형>이름;
	vector<int>v;

	// 데이터를 맨 뒤에 추가 -> .push_back(value);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// 데이터를 맨 뒤에서부터 삭제 -> .pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();

	//================================================================

	// 인접 리스트 방식
	// index : 노드 번호
	// value : 각 노드가 연결된 노드 번호

	vector<int>alis[4];
	for (int i = 0; i < N; i++)
	{
		int from, to;
		cin >> from >> to;
		alis[from].push_back(to); // from -> to 노드번호가 그대로 저장
	}

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < alis[i].size(); j++)
		{
			cout << alis[i][j] << " ";
		}
		cout << endl;
	}
	
	int a, b;
	cin >> a >> b;
	int flag = 0;
	for (int i = 0; i < alis[a].size(); i++)
	{
		if (b == alis[a][i])
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		cout << "연결되어있다" << endl;
	}


	// 인접 행렬
	// : 구현이 쉽다, 하지만 메모리를 많이 소모한다 (V^2)
	// : 조회시에 연산 한번으로 조회 가능

	// 인접 리스트
	// : 구현이 쉽진 않다. 하지만 메모리를 적게 소모한다 (V+E)
	// : 다만, 조회시에 V 노드의 갯수만큼 확인해야 함
}