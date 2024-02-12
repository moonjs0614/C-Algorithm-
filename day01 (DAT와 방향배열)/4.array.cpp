#include <iostream>
using namespace std;

int main() {
	
	int arr[3][3] = {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 7, 7 }};
	
	int x, y;
	cin >> x >> y;
	int sum = 0;

	////상
	//if (y - 1 >= 0)
	//{
	//	sum += arr[y - 1][x];
	//}
	////하
	//if (y + 1 <= 2)
	//{
	//	sum += arr[y + 1][x];
	//}
	////좌
	//if (x - 1 >= 0)
	//{
	//	sum += arr[y][x - 1];
	//}
	////우
	//if (x + 1 <= 2)
	//{
	//	sum += arr[y][x + 1];
	//}
	//
	//// 좌상
	//if (x - 1 >= 0 and y - 1 >= 0)
	//{
	//	sum += arr[y - 1][x - 1];
	//}
	//// 우상
	//if (x + 1 <= 2 and y - 1 >= 0)
	//{
	//	sum += arr[y - 1][x + 1];
	//}
	//// 좌하
	//if (x - 1 >= 0 and y + 1 <= 2)
	//{
	//	sum += arr[y + 1][x - 1];
	//}
	//// 우하
	//if (x + 1 <= 2 and y + 1 <= 2)
	//{
	//	sum += arr[y + 1][x + 1];
	//}

	//cout << sum << endl;

	
	// 방향 배열
	int ydir[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
	int xdir[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
	
	for (int i = 0; i < 8; i++) //탐색하려고 하는 방향의 개수
	{
		int ny = y + ydir[i];
		int nx = x + xdir[i];

		if (ny > 3 || ny < 0 || nx >= 3 || nx < 0)
		{
			continue;
			}
		sum += arr[ny][nx];
	}

	cout << sum;


	// 방향배열의 장점 : 유지보수가 쉽고 간결하게 처리 -> 불필요한 if 사용을 획기적으로 감소
	// 방향배열의 활용 : 완전탐색, 맵 등등


return 0;
}