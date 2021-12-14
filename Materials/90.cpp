#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 정글
int jungleSize;
int jungleMap[25][25] = { 0, };
bool visit[25][25] = { false, };

// 심바
struct Lion
{
    int x, y;
    int size;
    int eaten;

    void sizeUp()
    { 
        size += 1;
        eaten = 0;
    }
};
Lion shimba;

// 이동 상태
struct State
{
    int x, y;
    int dist;

    State(int _x, int _y, int _d)
    {
        x = _x;
        y = _y;
        dist = _d;
    }

    // 우선순위 큐 정렬 조건
    bool operator<(const State& s) const
    {
        // 거리 짧은 순
        if (dist != s.dist)
            return dist > s.dist;
        // 거리 동일하면
        else
        {
            // 위쪽에 있는 순
            if (x != s.x)
                return x > s.x;
            // 동일하게 위에 있으면
            else
                // 왼쪽에 있는 순
                return y > s.y;
        }
    }
};
priority_queue<State> myQ;

// 방향은 상 왼 하 우
int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

// 이동
int moveSec = 0;

int main(void)
{   
    cin >> jungleSize;
    for (int i = 0; i < jungleSize; i++)
    {
        for (int j = 0; j < jungleSize; j++)
        {
            cin >> jungleMap[i][j];
            // 심바 초기 위치
            if (jungleMap[i][j] == 9)
            {
                jungleMap[i][j] = 0;
                shimba.x = i;
                shimba.y = j;
                // 초기 크기
                shimba.size = 2;
                shimba.eaten = 0;
            }
        }
    }

    myQ.push(State(shimba.x, shimba.y , 0));

    while (!myQ.empty())
    {
        int curX = myQ.top().x;
        int curY = myQ.top().y;
        int curD = myQ.top().dist;
        myQ.pop();

        // 이동할 수 있는 위치 중
        // 가장 가까운 위치의 '먹을 수 있는' 토끼를 발견한 경우
        if (jungleMap[curX][curY] != 0 && jungleMap[curX][curY] < shimba.size)
        {
            // 토끼를 먹고
            shimba.eaten++;
            jungleMap[curX][curY] = 0;
            // 마지막으로 먹은 순간 이동 시간 저장
            moveSec = curD;

            // 조건을 만족하면 심바의 몸짓을 키우고 
            if (shimba.eaten == shimba.size)
                shimba.sizeUp();

            // 현재 위치에서 재탐색
            shimba.x = curX;
            shimba.y = curY;

            // 심바 크기가 변경됨에 따라
            // 이동할 수 있는 범위가 달라졌으니
            // 큐를 비운다
            while (!myQ.empty())
                myQ.pop();

            for (int i = 0; i < jungleSize; i++)
                for (int j = 0; j < jungleSize; j++)
                    visit[i][j] = false;
        }

        // 상하좌우 확인하면서 이동할 수 잇는 곳 탐색
        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dir[i][0];
            int nextY = curY + dir[i][1];
            int nextD = curD + 1;

            if (nextX < 0 || nextX >= jungleSize || nextY < 0 || nextY >= jungleSize
                || jungleMap[nextX][nextY] > shimba.size
                || visit[nextX][nextY] == true)
                continue;

            // 범위 안에 있고 
            // 심바가 이동할 수 있는 위치이며
            // 이번턴에 이동하지 않았다면
            myQ.push(State(nextX, nextY, nextD));
            visit[nextX][nextY] = true;
        }
    }

    std::cout << moveSec;

    return 0;
}
