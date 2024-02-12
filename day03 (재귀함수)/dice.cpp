#include <iostream>
using namespace std;

// 주사위 갯수 N 입력
// N개의 주사위 눈의 조합으로 나올 수 있는 조합 모두 출력
// 같은 눈을 사용하는 case 제외

int sum;
int N;
int DAT[7]; // index : 1~6 까지의 주사위 눈
int path[100];

void func(int now)
{
	// 2. 기저
	if (now >= N)
	{
		for (int i = 0; i < N; i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i < 6; i++)
	{
		// 3. 판별
		if (DAT[i] == 1)
		{
			continue;
		}

		// 4. 기록 및 계산
		path[now] = i; // index : now번째, value : 선택한 눈
		DAT[i] = 1; // indexl : 해당 눈금을, value : 사용했는가

		func(now + 1);

		// 5.기록 및 계산 복구
		path[now] = 0;
		DAT[i] = 0;
	}
}


int main() {

	cin >> N;

	func(0);
}