#include <iostream>
using namespace std;

int arr[5] = {5, 4, 3, 9, 1};
int sum;
int cnt;
int visited[10];

void func(int now)
{
	if (now == 5)
	{
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		if (visited[arr[i]] == 1)
		{
			continue;
		}
		if (sum + arr[i] > 20)
		{
			continue;
		}
		sum += arr[i];
		visited[arr[i]] = 1;
		if (sum >= 10 and sum <= 20)
		{
			cnt++;
		}
		func(now + 1);
		sum -= arr[i];
		visited[arr[i]] = 0;
	}
}

int main() {

	/*for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}*/

	func(0);

	cout << cnt;
}