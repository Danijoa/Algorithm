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
