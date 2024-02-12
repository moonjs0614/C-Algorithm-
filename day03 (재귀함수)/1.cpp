#include <iostream>
using namespace std;

// backtracking 문제인지 어떻게 알까?
// N의 크기가 20~30
// N! 11 ---> 가지치기
// 키워드 : 조합, 경우의 수, 경로의 수, 최대/최소의 차이 등등


int N, K;
int arr[1000];
int DAT[11];

//void func(int now, int sum) --> 매개변수 활용
//{
//	// 2. 기저 조건 // base case // 언제 멈출것인가?
//	if (now >= K)
//	{
//		for (int i = 0; i < K; i++)
//		{
//			cout << DAT[i] << " ";
//		}
//		cout << " = " << sum << endl;
//		return;
//	}
//
//	// 1. 재귀 기본 recursive case
//	for (int i = 0; i < N; i++)
//	{
//		// 3. 앞으로 진행하면서 실행되는 코드
//		DAT[now] = arr[i]; // index = now번째, value = 뽑은 수
//		func(now + 1, sum + arr[i]);
//	}
//}

int sum;
//void func(int now)
//{
//	// 2. 기저 조건 // base case // 언제 멈출것인가?
//	if (now >= K)
//	{
//		for (int i = 0; i < K; i++) //
//		{
//			cout << DAT[i] << " ";
//		}
//		cout << "= " << sum << endl;
//		return;
//	}
//
//	// 1. 재귀 기본 recursive case
//	for (int i = 0; i < N; i++)
//	{
//		// 5. 판별 - 내가 이 선택을 하는게 맞는가? -> 불필요한 연산 줄이기
//		if (arr[i] - now > 1)
//		{
//			continue;
//		}
//
//		// 3. 앞으로 진행하면서 실행되는 코드
//		DAT[now] = arr[i]; // index = now번째, value = 뽑은 수
//		sum += arr[i]; // sum 계산
//		func(now + 1);
//		sum -= arr[i]; // 계산 복구
//		DAT[now] = 0; // 초기화
//	}
//}

int path[10];
//void func(int now) // 인접한 수로 차이가 1나면 뽑을 수 없다 조건 포함
//{
//	// 2. 기저 조건 // base case // 언제 멈출것인가?
//	if (now >= K) // K - 1 까지는 뽑고, K는 뽑지 마라
//	{
//		int flag = 0;
//		for (int i = 0; i < K; i++) //
//		{
//			cout << path[i] << " ";
//		}
//		cout << "= " << sum << endl;
//		return;
//	}
//
//	// 1. 재귀 기본 recursive case
//	for (int i = 0; i < N; i++)
//	{
//		// 5. 판별 - 내가 이 선택을 하는게 맞는가? -> 불필요한 연산 줄이기
//		// 앞에있는것만 보면 된다 -> 굳이 지난 선택을 돌아볼 필요가 없다
//		if (now > 0 and
//			(path[now - 1] - arr[i] == 1 or path[now - 1] - arr[i] == -1))
//		{
//			continue;
//		}
//
//		// 3. 앞으로 진행하면서 실행되는 코드
//		path[now] = arr[i]; // index = now번째, value = 뽑은 수
//		sum += arr[i]; // sum 계산
//
//		func(now + 1);
//
//		sum -= arr[i]; // 계산 복구
//		path[now] = 0; // 초기화
//	}
//}

void func(int now) // 이미 뽑았던 수는 뽑을 수 없다 조건 포함
{
	// 2. 기저 조건 // base case // 언제 멈출것인가?
	if (now >= K) // K - 1 까지는 뽑고, K는 뽑지 마라
	{
		for (int i = 0; i < K; i++) //
		{
			cout << path[i] << " ";
		}
		cout << "= " << sum << endl;
		return;
	}

	// 1. 재귀 기본 recursive case
	for (int i = 0; i < N; i++)
	{
		// 5. 판별 - 내가 이 선택을 하는게 맞는가? -> 불필요한 연산 줄이기
		// 앞에있는것만 보면 된다 -> 굳이 지난 선택을 돌아볼 필요가 없다
		if (now > 0 and
			(path[now - 1] - arr[i] == 1 or path[now - 1] - arr[i] == -1))
		{
			continue;
		}
		if (DAT[arr[i]] == 1)
		{
			continue;
		}

		// 3. 앞으로 진행하면서 실행되는 코드
		path[now] = arr[i]; // index = now번째, value = 뽑은 수
		DAT[arr[i]] = 1; // index = 뽑은 숫자, value = 사용되었는가
		sum += arr[i]; // sum 계산

		func(now + 1);

		sum -= arr[i]; // 계산 복구
		path[now] = 0; // 초기화
		DAT[arr[i]] = 0;
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		arr[i] = i+1;
	}
	func(0);
	return 0;
}

// 합을 계산하는 방법
// 1. 뽑고 나서 계산
// 
// 
// 2. 뽑아가면서 계산
// -> 1) 매개변수 활용 : sum+arr[i]
// -> 2) 전역변수 활용