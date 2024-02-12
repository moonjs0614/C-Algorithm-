#include <iostream>
using namespace std;

int N;
int visited[10];
int cnt;

void func(int row)
{
	if (row == N)
	{
		cnt++;
		return;
	}

	for (int col = 0; col < N; col++)
	{
		if (visited[col] == 1)
		{
			continue;
		}
		visited[col] = 1;
		func(row + 1);
		visited[col] = 0;
	}
}

int main() {
	cin >> N;
	func(0);
	cout << cnt;
}