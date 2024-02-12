#include <iostream>
#include <vector>
using namespace std;

vector<int>alis[5];
int N, M;

void dfs(int node)
{
	cout << node << " ";

	for (int i = 0; i < alis[node].size(); i++)
	{
		int next = alis[node][i]; // alis[node] -> 현재 노드 / alis[node][i] -> 현재 노드에서 갈 수 있는 노드(간선 정보)
		dfs(next);
	}
}

int main() {

	/*
	5 4
	0 1
	0 2
	1 3
	1 4
	*/

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		alis[from].push_back(to);
	}
	dfs(0);
}