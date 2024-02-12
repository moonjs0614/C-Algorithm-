#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		// �� �� ¦�� or �� �� Ȧ��
		if (a % 2 == b % 2)
		{
			if (a % 2 == 0)
			{
				return a > b;
			}
			return a < b;
		}
		// �� �� �ϳ��� ¦�����, ¦�� �켱
		// ���� a�� Ȧ����� true => a �� ����
		// ���� a�� ¦����� false => a �� �켱
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