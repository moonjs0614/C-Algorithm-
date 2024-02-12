#include <iostream>
using namespace std;

int map[3][3] = {
	3, 5, 4,
	1, 1, 2,
	1, 3, 9,
};


int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {

	int y, x;
	cin >> y >> x;

	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 and ny >= 2 and nx < 0 and nx >= 2)
		{
			continue;
		}
		sum += map[ny][nx];
	}
	cout << sum;
}