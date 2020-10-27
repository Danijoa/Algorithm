#include <iostream>
#include <queue>
#define M 999999999
using namespace std;

int n, m;
int **graph;
int **cost;
int dirX[4] = { -1, 1, 0, 0 };	//좌우
int dirY[4] = { 0, 0, -1, 1 };	//상하

void solution()
{
	cost[0][0] = 0;
	priority_queue<pair<int, pair<int, int>>> myQ;	//(cost, x, y)
	myQ.push(make_pair(-1 * cost[0][0], make_pair(0, 0)));	//입력할때 음수

	while (!myQ.empty())
	{
		int curCost = -1 * myQ.top().first;	//출력할때 다시 양수
		int curX = myQ.top().second.first;
		int curY = myQ.top().second.second;
		myQ.pop();

		for (int i=0; i< 4; i++)
		{
			int nextX = curX + dirX[i];
			int nextY = curY + dirY[i];
			if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
			{
				continue;
			}
			
			int nextCost = curCost + graph[nextX][nextY];
			if (cost[nextX][nextY] > nextCost)
			{
				cost[nextX][nextY] = nextCost;
				myQ.push(make_pair(-1 * cost[nextX][nextY], make_pair(nextX, nextY)));	//입력할때 음수
			}
		}
	}
}

int main()
{
	cin >> m >> n;

	//벽 그래프 만들기
	graph = new int *[m];
	for (int i = 0; i < m; i++)
		graph[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d",&graph[j][i]);
	
	//값 저장 그래프 만들기
	cost = new int* [m];
	for (int i = 0; i < m; i++)
		cost[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cost[j][i] = M;
	
	//다익스트라
	solution();

	//결과값
	cout << cost[m-1][n-1];
}
