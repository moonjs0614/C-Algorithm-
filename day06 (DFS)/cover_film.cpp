#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// 필름의 두께 D, 가로크기 W, 합격기준 K;
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
	//지금 path대로 처리하면 가능?
	for (int col = 0; col < W; col++)
	{
		//세로선 하나 선택
		int cont = 1; // 지금까지 연속한 개수
		int prev = film[0][col]; // 맨위의 특성
		int contMax = 1; // 연속한 개수의 최대값

		if (path[0] != -1) //약품이 처리되어있다
		{
			prev = path[0]; //맨위의 필름에 path 기록대로 약품처리
		}

		for (int row = 1; row < D; row++)
		{
			int nowValue = film[row][col];
			// 연속하는 필름 약품 종류의 최대값 구하기
			if (path[row] != -1) //약품이 처리되었다
			{
				nowValue = path[row]; //기록된 값으로 약품을 처리
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
		if (contMax < K) return false; //불합격
	}
	return true;
}

void func(int now)
{
	// now 층에서 어떻게 처리할 것인가?
	if (now >= D) // 0 ~ D-1 층까지 뽑았다 -> D만큼 뽑았다
	{
		if (isValid())
		{
			ans = min(ans, cnt);
		}
		return;
	}

	for (int i = -1; i <= 1; i++)
	{
		// 판별
		if (i != -1 && cnt + 1 > K) continue;
		if (i != -1 && cnt + 1 >= ans) continue;

		// i == -1 -> 약품선택 X
		// i == 0 -> 약품 A로 처리
		// i == 1 -> 약품 B로 처리

		// 기록
		path.push_back(i); //약품 선택을 기록
		if (i != -1) cnt += 1;
		func(now + 1);// 가라

		if (i != -1) cnt -= 1;
		path.pop_back(); //약품 선택 초기화
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