#include <iostream>

using namespace std;

char arr[8];
int DAT[150];

int main()
{
    // BQTABAAA
    cin >> arr;

    for (int i = 0; i < 8; i++)
    {
        DAT[arr[i]]++;
    }

    char maxIdx = 'A';

    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (DAT[maxIdx] < DAT[i]) {
            maxIdx = i;
        }
    }

    cout << maxIdx;
}