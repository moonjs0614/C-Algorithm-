#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int T;
int N;
int heights[1000001];
int nums[1000001];
int DAT[1000001];

void init()
{
    memset(DAT, 0, sizeof(DAT));
}

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
}

bool isSortedDesc()
{
    int minVal = 999999;
    for (int i = 1; i <= N; i++)
    {
        if (minVal >= DAT[i])
        {
            minVal = DAT[i];
            continue;
        }
        return false;
    }
    return true;
}

int main()
{
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        init();
        input();

        for (int i = 0; i < N; i++)
        {
            DAT[nums[i]] = heights[i];
        }

        bool ret = isSortedDesc();
        if (ret == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}