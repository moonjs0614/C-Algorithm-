#include <iostream>
using namespace std;

void func(char path[], int level)
{
    if (level == 2)
    {
        cout << path << endl;;
        return;
    }
    for (char i = 'A'; i <= 'C'; i++)
    {
        path[level] = i;

        func(path, level + 1);
    }
}

int main() {

    char path[3];
    func(path, 0);

    return 0;
}