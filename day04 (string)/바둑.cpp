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
                int now_y = i; // 첫 돌 좌표
                int now_x = j;
                for (int direction = 0; direction < 4; direction++) // 네 방향 탐색
                {
                    int ny = now_y + dy[direction]; // 다음 좌표
                    int nx = now_x + dx[direction];
                    if (ny > 19 or nx > 19) // 다음 좌표가 배열을 벗어나면 제외
                    {
                        continue;
                    }
                    if (board[ny][nx] == 1) // 다음 돌이 같을때
                    {
                        int cnt = 2; // 현재까지 2개 연속
                        for (int m = 0; m < 3; m++) // 앞으로 3개 더 보기
                        {
                            int y = ny; // 세번째 돌 좌표
                            y += dy[direction];
                            int x = nx;
                            x += dx[direction];
                            if (board[y][x] != 1) // 다음 돌이 다르면 break
                            {
                                break;
                            }
                            cnt++; // 다음 돌이 같으면 cnt++
                        }
                        if (cnt == 5 and board[ny + 4 * dy[direction]][nx + 4 * dx[direction]] != 1) // 돌 5개 연속이고, 다음 돌이 다르면
                        {
                            a = now_y; //첫 돌 좌표 반환 
                            b = now_x;
                            answer = 1; // 흑돌 승리
                        }
                        if (answer == 1) // 흑돌 승리일 경우
                        {
                            if (board[now_y - dy[direction]][now_x - dx[direction]] == 1) // 첫 돌 직전 돌이 같으면
                            {
                                answer = 0; //승리 취소
                                a = 0; // 첫 돌 좌표 초기화
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