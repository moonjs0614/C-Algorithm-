#include <iostream>
using namespace std;

int main() {
	
	int arr[3][3] = {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 7, 7 }};
	
	int x, y;
	cin >> x >> y;
	int sum = 0;

	////��
	//if (y - 1 >= 0)
	//{
	//	sum += arr[y - 1][x];
	//}
	////��
	//if (y + 1 <= 2)
	//{
	//	sum += arr[y + 1][x];
	//}
	////��
	//if (x - 1 >= 0)
	//{
	//	sum += arr[y][x - 1];
	//}
	////��
	//if (x + 1 <= 2)
	//{
	//	sum += arr[y][x + 1];
	//}
	//
	//// �»�
	//if (x - 1 >= 0 and y - 1 >= 0)
	//{
	//	sum += arr[y - 1][x - 1];
	//}
	//// ���
	//if (x + 1 <= 2 and y - 1 >= 0)
	//{
	//	sum += arr[y - 1][x + 1];
	//}
	//// ����
	//if (x - 1 >= 0 and y + 1 <= 2)
	//{
	//	sum += arr[y + 1][x - 1];
	//}
	//// ����
	//if (x + 1 <= 2 and y + 1 <= 2)
	//{
	//	sum += arr[y + 1][x + 1];
	//}

	//cout << sum << endl;

	
	// ���� �迭
	int ydir[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
	int xdir[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
	
	for (int i = 0; i < 8; i++) //Ž���Ϸ��� �ϴ� ������ ����
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


	// ����迭�� ���� : ���������� ���� �����ϰ� ó�� -> ���ʿ��� if ����� ȹ�������� ����
	// ����迭�� Ȱ�� : ����Ž��, �� ���


return 0;
}