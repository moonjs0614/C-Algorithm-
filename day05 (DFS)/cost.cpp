#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int nodeCnt;
int arr[1000][1000];
int st, en;
int visited[1000];
int minSum = 999999;
int maxSum;
int sum;
void func(int now)
{
	if (now == en)
	{
		minSum = min(minSum, sum);
		maxSum = max(maxSum, sum);
		return;
	}
	for (int i = 0; i < nodeCnt; i++)
	{
		if (visited[i] == 1)
			continue;
		if (arr[now][i] == 0)
			continue;
		sum += arr[now][i];
		visited[i] = 1;
		func(i);
		sum -= arr[now][i];
		visited[i] = 0;
	}
}
int main()
{
	freopen("sample_input_1.txt", "r", stdin);
	cin >> nodeCnt;
	for (int i = 0; i < nodeCnt; i++)
	{
		for (int j = 0; j < nodeCnt; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> st >> en;
	visited[st] = 1;
	func(st);
	cout << minSum << '\n'
		<< maxSum << '\n';
	return 0;
}