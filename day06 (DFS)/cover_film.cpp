#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// �ʸ��� �β� D, ����ũ�� W, �հݱ��� K;
int D, W, K;
int film[15][25];
vector<int>path;
int ans = 999999;
int cnt;

void input()
{
	ans = 999999;
	path.clear();
	cnt = 0;
	memset(film, 0, sizeof(film));

	cin >> D >> W >> K;
	for (int row = 0; row < D; row++)
	{
		for (int col = 0; col < W; col++)
		{
			cin >> film[row][col];
		}
	}
}

bool isValid()
{
	//���� path��� ó���ϸ� ����?
	for (int col = 0; col < W; col++)
	{
		//���μ� �ϳ� ����
		int cont = 1; // ���ݱ��� ������ ����
		int prev = film[0][col]; // ������ Ư��
		int contMax = 1; // ������ ������ �ִ밪

		if (path[0] != -1) //��ǰ�� ó���Ǿ��ִ�
		{
			prev = path[0]; //������ �ʸ��� path ��ϴ�� ��ǰó��
		}

		for (int row = 1; row < D; row++)
		{
			int nowValue = film[row][col];
			// �����ϴ� �ʸ� ��ǰ ������ �ִ밪 ���ϱ�
			if (path[row] != -1) //��ǰ�� ó���Ǿ���
			{
				nowValue = path[row]; //��ϵ� ������ ��ǰ�� ó��
			}

			if (prev == nowValue)
			{
				cont++;
			}
			else
			{
				cont = 1;
			}
			prev = nowValue;
			contMax = max(contMax, cont);
		}
		if (contMax < K) return false; //���հ�
	}
	return true;
}

void func(int now)
{
	// now ������ ��� ó���� ���ΰ�?
	if (now >= D) // 0 ~ D-1 ������ �̾Ҵ� -> D��ŭ �̾Ҵ�
	{
		if (isValid())
		{
			ans = min(ans, cnt);
		}
		return;
	}

	for (int i = -1; i <= 1; i++)
	{
		// �Ǻ�
		if (i != -1 && cnt + 1 > K) continue;
		if (i != -1 && cnt + 1 >= ans) continue;

		// i == -1 -> ��ǰ���� X
		// i == 0 -> ��ǰ A�� ó��
		// i == 1 -> ��ǰ B�� ó��

		// ���
		path.push_back(i); //��ǰ ������ ���
		if (i != -1) cnt += 1;
		func(now + 1);// ����

		if (i != -1) cnt -= 1;
		path.pop_back(); //��ǰ ���� �ʱ�ȭ
	}
}

void solution()
{
	func(0);
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		input();
		solution();
		cout << "#" << tc << " " << ans << endl;
	}
}