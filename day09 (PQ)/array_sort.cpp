#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// sort�� ���� => merge, select, burble, quick, insertion, heap

// c++ => intro sort : quick, insertion, heap => nlogn�� �ӵ� ����
// quick -> �⺻
// quick�� nlogn���� ���� �ɸ��ٸ� -> heap sort
// �迭�� ũ�Ⱑ �ſ� �۴� -> insertion sort

bool cmp(int left, int right)
{
	if (left < right) return true;
	if (left > right) return false;
	return false;
}


int main() {

	int arr[12] = { -1, 3, 26, 28, 17, 27342, 21, 4, 30, 12, 22 , -1};

	sort(arr + 1, arr + 11, cmp); // sort(�迭 ���� �ּ�, �迭 �� �ּ� + 1, �����Լ�)

	for (int i = 0; i < 12; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	vector<int> v;
	v.push_back(3);
	v.push_back(26);
	v.push_back(28);
	v.push_back(17);
	v.push_back(27342);
	v.push_back(21);
	v.push_back(4);
	v.push_back(30);
	v.push_back(12);
	v.push_back(22);
	sort(v.begin(), v.end());
}