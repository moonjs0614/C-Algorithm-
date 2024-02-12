#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string str;
string arr[256];
string a;
int k = 0;

void func(int now)
{
	if (now == 4)
	{
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		a += str[i];
		func(now + 1);
	}
	arr[k] = a;
	k++;
	a = '\0';
}

int main() {

	cin >> str;

	func(0);
}