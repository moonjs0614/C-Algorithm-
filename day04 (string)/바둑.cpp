#include <iostream>
using namespace std;

int board[20][20];
int dy[4] = { 0, 1, 1, 1 };
int dx[4] = { 1, 1, 0, -1 };


void who_is_winner(int &a, int &b)
{
    a = 0;
    b = 0;
    int answer = 0;
    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            if (board[i][j] == 0)
            {
                continue;
            }
            else if (board[i][j] == 1)
            {
                int now_y = i; // ù �� ��ǥ
                int now_x = j;
                for (int direction = 0; direction < 4; direction++) // �� ���� Ž��
                {
                    int ny = now_y + dy[direction]; // ���� ��ǥ
                    int nx = now_x + dx[direction];
                    if (ny > 19 or nx > 19) // ���� ��ǥ�� �迭�� ����� ����
                    {
                        continue;
                    }
                    if (board[ny][nx] == 1) // ���� ���� ������
                    {
                        int cnt = 2; // ������� 2�� ����
                        for (int m = 0; m < 3; m++) // ������ 3�� �� ����
                        {
                            int y = ny; // ����° �� ��ǥ
                            y += dy[direction];
                            int x = nx;
                            x += dx[direction];
                            if (board[y][x] != 1) // ���� ���� �ٸ��� break
                            {
                                break;
                            }
                            cnt++; // ���� ���� ������ cnt++
                        }
                        if (cnt == 5 and board[ny + 4 * dy[direction]][nx + 4 * dx[direction]] != 1) // �� 5�� �����̰�, ���� ���� �ٸ���
                        {
                            a = now_y; //ù �� ��ǥ ��ȯ 
                            b = now_x;
                            answer = 1; // �浹 �¸�
                        }
                        if (answer == 1) // �浹 �¸��� ���
                        {
                            if (board[now_y - dy[direction]][now_x - dx[direction]] == 1) // ù �� ���� ���� ������
                            {
                                answer = 0; //�¸� ���
                                a = 0; // ù �� ��ǥ �ʱ�ȭ
                                b = 0;
                            }
                        }
                    }
                }
            }

            else if (board[i][j] == 2)
            {
                int now_y = i;
                int now_x = j;
                for (int direction = 0; direction < 4; direction++)
                {
                    int ny = i + dy[direction];
                    int nx = j + dx[direction];
                    if (ny > 19 or nx > 19)
                    {
                        continue;
                    }
                    if (board[ny][nx] == 2)
                    {
                        int cnt = 2;
                        for (int m = 0; m < 3; m++)
                        {
                            int y = ny;
                            y += dy[direction];
                            int x = nx;
                            x += dx[direction];
                            if (board[y][x] != 2)
                            {
                                break;
                            }
                            cnt++;
                        }
                        if (cnt == 5 and board[ny + 4 * dy[direction]][nx + 4 * dx[direction]] != 2)
                        {
                            a = ny + 4 * dy[direction];
                            b = nx + 4 * dx[direction];
                            answer = 2;
                        }
                        if (board[now_y - dy[direction]][now_x - dx[direction]] == 2)
                        {
                            answer = 0;
                            a = 0;
                            b = 0;
                        }
                    }
                }
            }
        }
    }
    if (answer == 1)
    {
        cout << answer << endl;
    }
    else if (answer == 2)
    {
        cout << answer << endl;
    }
    else if (answer == 0)
    {
        cout << answer << endl;
    }
}

int main() {

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            cin >> board[i][j];
        }
    }

    int a, b;
    who_is_winner(a, b);

    if (a != 0 and b != 0)
    {
        cout << a << " " << b;
    }
}