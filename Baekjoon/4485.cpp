#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int num;
int myA[125][125];
int dist[125][125];
int dX[4] = { -1, 1, 0, 0 };
int dY[4] = { 0, 0, -1, 1 };

void dijkstra()
{
	dist[0][0] = myA[0][0];

	priority_queue<pair<int, pair<int, int>>> myQ;	//거리, 인덱스(x, y)
	myQ.push(make_pair(-dist[0][0], make_pair(0, 0)));

	while (myQ.empty() != true)
	{
		//현재 인덱스
		int curX = myQ.top().second.first;
		int curY = myQ.top().second.second;
		//현재 거리
		int curCost = -1 * myQ.top().first;

		myQ.pop();
		if (curCost > dist[curX][curY])
		{
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			//다음 인덱스
			int nextX = curX + dX[i];
			int nextY = curY + dY[i];
			//다음거리
			if ((nextX < 0 || nextX > num - 1) || (nextY < 0 || nextY > num - 1))
			{
				continue;
			}
			int nextCost = myA[nextX][nextY];

			if (dist[curX][curY] + nextCost < dist[nextX][nextY])
			{
				dist[nextX][nextY] = dist[curX][curY] + nextCost;
				myQ.push(make_pair(-dist[nextX][nextY], make_pair(nextX, nextY)));
			}
		}
	}
}

int main()
{
	int count = 0;
	while (true)
	{
		count++;

		//배열 크기
		cin >> num;
		if (num == 0)
			break;
		
		//배열 초기화
		fill(&myA[0][0], &myA[num - 1][num - 1], 10);

		//값 입력
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				cin >> myA[i][j];
			}
		}
		
		//거리 초기화
		//fill(&dist[0][0], &dist[num - 1][num - 1], 2250);
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				dist[i][j] = 2250;
			}
		}

		dijkstra();

		cout << "Problem " << count << ": " << dist[num - 1][num - 1]<<'\n';
	}

	return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 126
#define INF 2250
using namespace std;

typedef struct mapData
{
    int distance;
    int x;
    int y;
}; 

typedef struct cmp
{
    bool operator()(mapData& a, mapData& b)
    {
        return (a.distance > b.distance);
    }
};

pair<int, int> target;
int map[MAX][MAX];
int dist[MAX][MAX];
priority_queue<mapData, vector<mapData>, cmp> myQ;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int Dijkstra(int size, pair<int, int> target)
{
    // 시작 지점 저장
    dist[0][0] = map[0][0];
    myQ.push({ -1 * map[0][0], 0, 0 });

    while (!myQ.empty())
    {
        int curX = myQ.top().x;
        int curY = myQ.top().y;
        int curDist = -1 * myQ.top().distance;
        myQ.pop();

        if (curDist > dist[curX][curY])
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dir[i][0];
            int nextY = curY + dir[i][1];
            int nextDist = map[nextX][nextY];

            if (nextX < 0 || nextX >= size || nextY < 0 || nextY >= size)
                continue;

           if (dist[nextX][nextY] > dist[curX][curY] + nextDist)		//dist[curX][curY] curDist
            {
                dist[nextX][nextY] = dist[curX][curY] + nextDist;
                myQ.push({ -1 * dist[nextX][nextY], nextX , nextY });
            }
        }
    }

    return dist[size - 1][size - 1];
}

int main()
{
    int size;
    int cnt = 0;
    while (true)
    {
        cnt++;

        // 맵 크기
        cin >> size;
        if (size == 0)
            break;

        // 맵 셋팅
        fill(&map[0][0], &map[size - 1][size - 1], 0);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> map[i][j];
            }
        }

        // 거리 갱신 저장
        //fill(&dist[0][0], &dist[size - 1][size - 1], INF);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                dist[i][j] = INF;
            }
        }

        // 시작~도착 최단 거리
        cout << "Problem " << cnt << ": " << Dijkstra(size, target);
    }
}
*/
