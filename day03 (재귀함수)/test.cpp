#include <iostream>
#include <string>
using namespace std;

string str;
int idx;

int main() {

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[idx] == ' ' or str[idx] == '\0')
        {
            break;
        }

        if (str[idx] == '(')
        {
            if (str[idx + 1] == '(')
            {
                str.erase(str[idx]);
            }
        }
        else if (str[idx] == ')')
        {
            if (str[idx + 1] == ')')
            {
                str.erase(str[idx]);
            }
            else
            {
                str.erase(str[idx]);
            }
        }
        else if (str[idx] == '^')
        {
            if (str[idx + 2] == '^')
            {
                if (str[idx + 1] == '^')
                {
                    str.erase(str[idx + 1]);
                }
                else if (str[idx + 1] != '_')
                {
                    str[idx + 1] = '_';
                }
            }
        }
    }

    cout << str;
}