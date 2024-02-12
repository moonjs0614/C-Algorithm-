#include <iostream>
using namespace std;

int N; // 주사위의 수
int M; // 모드
int path[6]; //경로

void printpath(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

void roll1(int level) // 순열
{
    // 기저 조건 -> N개의 주사위를 던졌다면 종료
    if (level == N)
    {
        printpath(level);
        return;
    }

    // 수행
    // 재귀 구성 -> 6개의 경우의 수를 가지고 내려갈 수 있다.
    for (int i = 1; i <= 6; i++)
    {
        path[level] = i; // level번 주사위는 i번 눈금을 굴렸다
        roll1(level + 1); // 이 경우의 수를 가지고 다음 주사위를 굴린다.
        path[level] = 0; // path 기록 초기화
    }

}

// 매개변수를 사용할 경우
// 배열은 위처럼 앞뒤로 놓는게 기본.
// 배열은 주소를 넘기기 때문.
// 파라미터를 활용하는 이유는 각 재귀마다 고유한 변수를 갖기 위함인데,
// 배열은 주소를 넘기므로 사실상 전역변수와 마찬가지가 됨.
// 그러므로 배열은 보통 파라미터로 쓰지 않음.

void roll2(int level) // 조합
{
    if (level > 1 and path[level - 1] < path[level - 2])
    {
        return;
    }

    // 기저 조건 -> N개의 주사위를 던졌다면 종료
    if (level == N)
    {
        printpath(level);
        return;
    }

    // 수행
    // 재귀 구성 -> 6개의 경우의 수를 가지고 내려갈 수 있다.
    for (int i = 1; i <= 6; i++)
    {
        // 가지치기 -> 작은 조합부터 출력
        // 즉, i번째 눈금이 i-1번째 눈금보다 작다면,
        // 이에 대한 더 작은 조합/경우의 수는 이미 출력되었음이 확정
        //if (level > 0 and i < path[level - 1])
        //    continue;
        path[level] = i; // level번 주사위는 i번 눈금을 굴렸다
        roll2(level + 1); // 이 경우의 수를 가지고 다음 주사위를 굴린다.
        path[level] = 0; // path 기록 초기화
    }

}

int visited[10]; // index : 주사위의 눈금, index : 해당 눈금을 사용한 적 있는가

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