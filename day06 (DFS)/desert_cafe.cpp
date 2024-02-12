#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// �پ��� ��� �䱸 -> 80% �̻��� ���, ��Ʈ��ŷ ����
// Ư��, ���� �� or ���� ū ~~~ -> DFS ����

// now -> now + 1 ���� � ��Ģ�� �ʿ��Ѱ�
// 1. ������� �״�� -> dir = ndir(new dir)
// 2. ������ �ٲ۴� -> ndir = dir+1

int N;
int M[30][30];
int dr[] = { 1, 1, -1, -1 };
int dc[] = { 1, -1 ,-1, 1 };
int visited[110]; // index = ����Ʈ ����, value = ��λ� �ִ°�
vector<int>path;
int destRow, destCol; // ���� ��ǥ. ������� ���� ���� 1ĭ ��ġ.
int ans;

void input()
{
	memset(visited, 0, sizeof(visited));
	path.clear();
	ans = 0;

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			M[i][j] = -1;
		}
	}

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> M[i][j];
		}
	}
}

void dfs(int row, int col, int dir)
{
	// ����
	if (row == destRow && col == destCol)
	{
		if (ans < path.size())
		{
			ans = path.size();
			return;
		}
	}
	
	for (int ndir = dir; ndir <= dir + 1; ndir++)
	{
		if (ndir >= 4)continue;
		int nr = row + dr[ndir];
		int nc = col + dc[ndir];

		// �Ǻ�
		if (M[nr][nc] == -1)continue; //���� �����
		if (visited[M[nr][nc]] == 1)continue; // �̹� �鸥 ���̴�

		// ��� �� ó��
		visited[M[nr][nc]] = 1;
		path.push_back(M[nr][nc]);

		// ����
		dfs(nr, nc, ndir);

		// ����
		visited[M[nr][nc]] = 0;
		path.pop_back();
	}
}

void solution()
{
	// ��� �پ��� ��� �����ϱ�
	for (int row = 1; row <= N; row++)
	{
		for (int col = 1; col <= N; col++)
		{
			destRow = row + 1;
			destCol = col - 1;

			//��� �� ó��
			visited[M[row][col]] = 1;
			path.push_back(M[row][col]);

			//����
			dfs(row, col, 0); // �������� ������ ��, ���� ��ǥ ��� �� �־���
							  // �������� ���� ������ �ϰ� ����

			//����
			visited[M[row][col]] = 0;
			path.pop_back();
		}
	}
	if (ans < 4)
	{
		ans = -1; // �簢���� ������ ���� ���
	}
}

int main() {
	int T;
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		input();
		solution();
		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}