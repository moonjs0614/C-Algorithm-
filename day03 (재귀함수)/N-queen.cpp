#include <iostream>
using namespace std;

int N;
int visited[100];
int LURD[100];
int LDRU[100];
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
		if (visited[col] == 1 or LURD[row - col + N - 1] == 1 or LDRU[row + col] == 1)
		{
			continue;
		}
		visited[col] = 1;
		LURD[row - col + N - 1] = 1;
		LDRU[row + col] = 1;
		func(row + 1);
		visited[col] = 0;
		LURD[row - col + N - 1] = 0;
		LDRU[row + col] = 0;
	}
}

int main() {
	cin >> N;
	func(0);
	cout << cnt;
}