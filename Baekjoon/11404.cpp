#include <iostream>
#define MAX 101
using namespace std;

int cityNum;
int busNum;
int start, dest, cost;
int costGraph[MAX][MAX] = { 0, };

// 모든 노드 사이의 최단거리 구하기니까 플로이드와샬
void floydW()
{
	// via : 거쳐가는 노드
	for (int via = 1; via <= cityNum; via++)	
	{
		// from : 시작 노드
		for (int from = 1; from <= cityNum; from++)
		{
			if (costGraph[from][via] == 0)
				continue;

			// to : 도착노드
			for (int to = 1; to <= cityNum; to++)
			{
				if (from == to || costGraph[via][to] == 0)
					continue;

				// 갱신해서 저장 : 시작->도착 경로를 거쳐가는 노드를 바꿔가면서 확인
				if (costGraph[from][to] == 0 ||
					costGraph[from][to] > costGraph[from][via] + costGraph[via][to])
					costGraph[from][to] = costGraph[from][via] + costGraph[via][to];
			}
		}

	}

}

int main()
{
	cin >> cityNum;
	cin >> busNum;

	for (int i = 0; i < busNum; i++)
	{
		cin >> start >> dest >> cost;
		if ((costGraph[start][dest] != 0 && costGraph[start][dest] > cost)
			|| costGraph[start][dest] == 0)
			costGraph[start][dest] = cost;
	}

	floydW();

	for (int i = 1; i <= cityNum; i++)
	{
		for (int j = 1; j <= cityNum; j++)
		{
			cout << costGraph[i][j] << " ";
		}
		cout << endl;
	}  
}
