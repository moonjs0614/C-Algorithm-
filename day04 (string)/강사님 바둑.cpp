#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int dy[4] = { 1, 1, 1, 0 };
int dx[4] = { -1, 0, 1, 1 };
int board[20][20];

bool check(int y, int x, int color, int dir)
{
	int cnt = 1;
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	while (board[ny][nx] == color)
	{
		if (ny < 1 || ny > 19 || nx < 1 || nx > 19)
		{
			break;
		}
		cnt++;
		ny += dy[dir];
		nx += dx[dir];
	}

	if (cnt != 5)
		return false;
	
	ny = y - dy[dir];
	nx = x - dx[dir];


	if (ny < 1 || ny > 19 || nx < 1 || nx > 19)
	{
		return true;
	}

	if (board[ny][nx] == color)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	freopen("sample_input.txt", "r", stdin);

	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			if (board[i][j])
			{
				for (int dir = 0; dir < 4; dir++)
				{
					if (check(i, j, board[i][j], dir))
					{
						cout << board[i][j] << endl;
						if (dir == 0)
						{
							cout << i + 4 << " " << j - 4 << endl;
						}
						else
						{
							cout << i << " " << j << endl;
						}
						return 0;
					}
				}
			}
		}
	}

	cout << 0 << endl;
}