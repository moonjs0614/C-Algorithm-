#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Player
{
	string name;
	int ability;
	int number;
	bool operator<(Player right) const
	{
		// 1.능력치는 높은 순서
		if (ability < right.ability) return true;
		if (ability > right.ability) return false;
		// 2.번호는 빠른 번호부터
		if (number < right.number) return true;
		if (number > right.number) return false;
		// 3.이름은 사전순
		if (name > right.name) return true;
		if (name < right.name) return false;
	}
};

// function object
struct cmp_player {
	bool operator()(Player left, Player right)
	{
		// 1.능력치는 높은 순서
		if (left.ability < right.ability) return true;
		if (left.ability > right.ability) return false;
		// 2.번호는 빠른 번호부터
		if (left.number < right.number) return false;
		if (left.number > right.number) return true;
		// 3.이름은 사전순
		if (left.name < right.name) return false;
		if (left.name > right.name) return true;

		return false;
	}
};


int main() {

	/*priority_queue<int> pq;
	pq.push(5);
	pq.push(15);
	pq.push(7);
	pq.push(3);
	pq.push(2);
	pq.push(9);
	pq.push(10);*/

	//heap 구조
	// 1. 완전이진트리(complete binary tree) ->  순서 = 왼쪽부터 채운다
	// 2. heapify -> 직접 연결되어잇는 노드끼리 비교해서
	// max heap 기준 swap() -> 큰 값을 위로 올린다
	// min heap 기준 swap() -> 작은 값을 위로 올린다

	/*while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}*/

	priority_queue<Player, vector<Player>, cmp_player> pq;
	pq.push({"손흥민", 93, 7});
	pq.push({"이강인", 90, 18});
	pq.push({"이기제", 70, 13});
	pq.push({"김민재", 93, 9});
	pq.push({"조현우", 98, 0});

	int de = -1;

	while (!pq.empty())
	{
		Player now = pq.top();
		cout << now.name << " | " << now.number << " | " << now.ability << endl;
		pq.pop();

	}
}