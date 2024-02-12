#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Member
{
	int id;
	string name;
};

struct compare
{
	bool operator()(Member a, Member b)
	{
		return a.name < b.name;
	}
};

priority_queue<Member, vector<Member>, compare> pq;

int main() {
	
	pq.push({ 3, "������" });
	pq.push({ 1, "�輼��" });
	pq.push({ 2, "���ϸ�" });
	//pq.push({ 4, "��ټ�" });

	while (!pq.empty())
	{
		Member now = pq.top();
		pq.pop();
		cout << now.id << " : " << now.name << " " << endl;
	}
}