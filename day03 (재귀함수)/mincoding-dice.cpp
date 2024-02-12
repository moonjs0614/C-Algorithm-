#include <iostream>
using namespace std;

int N; // �ֻ����� ��
int M; // ���
int path[6]; //���

void printpath(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

void roll1(int level) // ����
{
    // ���� ���� -> N���� �ֻ����� �����ٸ� ����
    if (level == N)
    {
        printpath(level);
        return;
    }

    // ����
    // ��� ���� -> 6���� ����� ���� ������ ������ �� �ִ�.
    for (int i = 1; i <= 6; i++)
    {
        path[level] = i; // level�� �ֻ����� i�� ������ ���ȴ�
        roll1(level + 1); // �� ����� ���� ������ ���� �ֻ����� ������.
        path[level] = 0; // path ��� �ʱ�ȭ
    }

}

// �Ű������� ����� ���
// �迭�� ��ó�� �յڷ� ���°� �⺻.
// �迭�� �ּҸ� �ѱ�� ����.
// �Ķ���͸� Ȱ���ϴ� ������ �� ��͸��� ������ ������ ���� �����ε�,
// �迭�� �ּҸ� �ѱ�Ƿ� ��ǻ� ���������� ���������� ��.
// �׷��Ƿ� �迭�� ���� �Ķ���ͷ� ���� ����.

void roll2(int level) // ����
{
    if (level > 1 and path[level - 1] < path[level - 2])
    {
        return;
    }

    // ���� ���� -> N���� �ֻ����� �����ٸ� ����
    if (level == N)
    {
        printpath(level);
        return;
    }

    // ����
    // ��� ���� -> 6���� ����� ���� ������ ������ �� �ִ�.
    for (int i = 1; i <= 6; i++)
    {
        // ����ġ�� -> ���� ���պ��� ���
        // ��, i��° ������ i-1��° ���ݺ��� �۴ٸ�,
        // �̿� ���� �� ���� ����/����� ���� �̹� ��µǾ����� Ȯ��
        //if (level > 0 and i < path[level - 1])
        //    continue;
        path[level] = i; // level�� �ֻ����� i�� ������ ���ȴ�
        roll2(level + 1); // �� ����� ���� ������ ���� �ֻ����� ������.
        path[level] = 0; // path ��� �ʱ�ȭ
    }

}

int visited[10]; // index : �ֻ����� ����, index : �ش� ������ ����� �� �ִ°�

void roll3(int level)
{
    if (level == N)
    {
        printpath(level);
        return;
    }

    for (int i = 1; i < 6; i++)
    {
        if (visited[i] == 1)
        {
            continue;
        }
        visited[i] = 1;
        path[level] = i;
        roll3(level + 1);
        visited[i] = 0;
        path[level] = 0;
    }

}

int main()
{
    cin >> N >> M;
    if (M == 1)
        roll1(0);
    else if (M == 2)
        roll2(0);
    else if (M == 3)
        roll3(0);
}