#include <iostream>
using namespace std;

int main() {

	int arr[10] = { 27, 30, 28, 22, 7, 10, 20, 1, 11, 5 };

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int flag = 0;
		int num;
		cin >> num;
		for (int j = 0; j < 10; j++)
		{
			if (num == arr[j])
			{
				cout << num << " : " << "있다" << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << num << " : " << "없다" << endl;
		}
	}
	return 0;
}