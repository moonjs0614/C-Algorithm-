#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		// 둘 다 짝수 or 둘 다 홀수
		if (a % 2 == b % 2)
		{
			if (a % 2 == 0)
			{
				return a > b;
			}
			return a < b;
		}
		// 둘 중 하나는 짝수라면, 짝수 우선
		// 만약 a가 홀수라면 true => a 가 나중
		// 만약 a가 짝수라면 false => a 가 우선
		return a % 2 != 0;
	}
};


priority_queue<int, vector<int>, compare> pq;

int main() {
	
	pq.push(1);
	pq.push(3);
	pq.push(2);
	pq.push(4);

	while (!pq.empty())
	{
		int now = pq.top();
		pq.pop();
		cout << now << " ";
	}
}