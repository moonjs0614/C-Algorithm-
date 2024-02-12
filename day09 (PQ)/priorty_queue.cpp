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
		// 1.�ɷ�ġ�� ���� ����
		if (ability < right.ability) return true;
		if (ability > right.ability) return false;
		// 2.��ȣ�� ���� ��ȣ����
		if (number < right.number) return true;
		if (number > right.number) return false;
		// 3.�̸��� ������
		if (name > right.name) return true;
		if (name < right.name) return false;
	}
};

// function object
struct cmp_player {
	bool operator()(Player left, Player right)
	{
		// 1.�ɷ�ġ�� ���� ����
		if (left.ability < right.ability) return true;
		if (left.ability > right.ability) return false;
		// 2.��ȣ�� ���� ��ȣ����
		if (left.number < right.number) return false;
		if (left.number > right.number) return true;
		// 3.�̸��� ������
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

	//heap ����
	// 1. ��������Ʈ��(complete binary tree) ->  ���� = ���ʺ��� ä���
	// 2. heapify -> ���� ����Ǿ��մ� ��峢�� ���ؼ�
	// max heap ���� swap() -> ū ���� ���� �ø���
	// min heap ���� swap() -> ���� ���� ���� �ø���

	/*while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}*/

	priority_queue<Player, vector<Player>, cmp_player> pq;
	pq.push({"�����", 93, 7});
	pq.push({"�̰���", 90, 18});
	pq.push({"�̱���", 70, 13});
	pq.push({"�����", 93, 9});
	pq.push({"������", 98, 0});

	int de = -1;

	while (!pq.empty())
	{
		Player now = pq.top();
		cout << now.name << " | " << now.number << " | " << now.ability << endl;
		pq.pop();

	}
}