#include <iostream>
using namespace std;

char vect[9] = {'M', 'I', 'N' ,'C' ,'O' ,'D' ,'I' ,'N' ,'G'};
int DAT[150] = { 0, };

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < 9; i++)
	{
		DAT[vect[i]] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		char a;
		cin >> a;
		if (DAT[a] == 1)
		{
			cout << "O";
		}
		else
		{
			cout << "X";
		}
	}
}