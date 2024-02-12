#include <iostream>
#include <queue>
using namespace std;

int arr[7][7] = {
 {0, 1, 1, 0, 0, 0, 0},
 {0, 0, 0, 1, 1, 0, 0},
 {0, 0, 0, 0, 0, 1, 1},
 {0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0} };

void bfs(int st)
{
	queue<int>q;
	q.push(st);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < 7; i++)
		{
			if (arr[now][i] == 1)
			{
				q.push(i);
			}
			/* 위는 아래와 같음
			if (arr[now][i] == 0)
			{
				continue;
			}
			q.push(i);
			*/
		}
	}
}

int main()
{
	int st = 0;
	bfs(st);
}