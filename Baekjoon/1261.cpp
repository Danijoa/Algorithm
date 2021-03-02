#include <iostream>
#include <queue>
#define INF 987654321
#define MAX 101
using namespace std;

int garo, searo;	//가로, 세로
int maze[MAX][MAX];	//미로(벽) 저장
int minCost[MAX][MAX];	//시작노드(1, 1) ~ 현재노드(i, j)까지의 최단거리(=최단비용) dist[i][j]에 저장

typedef struct _nD
{
	int cost;	// 현재노드 까지 최단 비용
	int coor[2];	//현재노드 좌표
}nodeData;
bool operator<(nodeData a, nodeData b)	//우선 순위 결정 방법 정해주기
{
	return a.cost < b.cost;	//최대값 부터
}
priority_queue<nodeData> nodeQ;//우선순위 큐(최대 힙: 루트가 항상 최대값인 트리)
//priority_queue<pair<int, pair<int, int>>> myQ;	← (cost, x, y)


int dX[4] = { -1, 1, 0, 0 };	//좌우
int dY[4] = { 0, 0, -1, 1 };	//상하

void dijkstra()
{
	nodeQ.push({ -1 * minCost[1][1],{1,1} });	//최대힙이기에, 최단 비용을 루트로 두려면 음수를 붙혀서 저장해야한다
	
	while (!nodeQ.empty())
	{
		int curCost = -1 * nodeQ.top().cost;	//출력할때는 다시 양수로 변환시켜서 계산
		int curX = nodeQ.top().coor[0];
		int curY = nodeQ.top().coor[1];
		nodeQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dX[i];	//이웃노드
			int nextY = curY + dY[i];	//이웃노드
			if ((nextX>=1 && nextX <= searo) && (nextY >= 1 && nextY <= garo))	//범위 안에 있을때
			{
				int nextCost = curCost + maze[nextX][nextY]; //현재노드 까지의 비용 + (nextX, nextY)를 지나기 위한 비용
				if (minCost[nextX][nextY] > nextCost)	//출발노드에서 현재지점까지 거리 > 출발노드에서 중간노드를 지나 현재지점까지 거리
				{
					minCost[nextX][nextY] = nextCost;
					nodeQ.push({ -1 * minCost[nextX][nextY],{nextX,nextY} });
				}
			}
		}
	}
}

int main()
{
	//입력
	cin >> garo >> searo;
	for (int i = 1; i <= searo; i++)
	{
		for (int j = 1; j <= garo; j++)
		{
			scanf_s("%1d", &maze[i][j]);	//0: 빈방 1: 벽
		}
	}

	//다익스트라 사용을 위한 초기화
	for (int i = 1; i <= searo; i++)
	{
		for (int j = 1; j <= garo; j++)
		{
			minCost[i][j] = INF;	//무한값
		}
	}
	minCost[1][1] = 0;	//시작노드는 0

	//벽을 최소한으로 지나는 길 찾기 = 시작노드 부터 타겟노드 까지 최단 거리 = 다익스트라
	dijkstra();

	//결과값
	cout << minCost[searo][garo];

	return 0;
}
