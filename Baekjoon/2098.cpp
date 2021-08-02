#include <iostream> 
#include <cstring>
#define INF 987654321
#define MAX 16
using namespace std;

// TSP : 1도시 출발 1~N 모두 거쳐 1도착
// 비트 마스크 : 지금까지 들린 경로 표기를 위해 사용
// ex) 00001 (노드 0 방문) 10001 (노드 0->4 방문) 10011 (노드 0->4->1 방문) 

int city;
int cost[MAX][MAX];
int completePath;
// dp[i][j] : 현재 '정점' i + 지나온 '경로' j -> 지금까지 든 최소 비용
int dp[MAX][1 << MAX];	

int DFS(int curNode, int curPath)
{
	// 모든 도시를 방문하였다 (결국은 min 계산에 넘겨주는 값)
	if (completePath == curPath)
	{
		if (cost[curNode][0] == 0)
			return INF;
		else
			return cost[curNode][0];
	}

	// 이미 해당 경로의 최소 비용은 계산했다
	if (dp[curNode][curPath] != -1)
	{
		return dp[curNode][curPath];
	}

	// 현재 도시부터 특정 경로를 지나기 위한 최소 비용 구하기
	dp[curNode][curPath] = INF;
	for (int i = 0; i < city; i++)
	{
		// 연결 안된 도시 건너뛰기
		if(cost[curNode][i] == 0)
		{ 
			continue;
		}

		// 거쳐가려는 도시를 기존 경로에서 방문 한 적 있으면 건너뛰기
     // [&]는 경로 방문 여부 확인
		if ((curPath & (1 << i)) == (1 << i))
		{
			continue;
		}

		// 현재 저장된 비용과 다른 곳을 거친 비용을 비교하여 작은 값 저장
    // [|]는 경로 추가
		dp[curNode][curPath] 
			= min(dp[curNode][curPath], cost[curNode][i] + DFS(i, (curPath | (1 << i))));
	}

	// 최종 출력 값
	return dp[curNode][curPath];
}

int main()
{
	cin >> city;
	
	// 111 = 7 이고 1 << 3 = 1000 = 8 따라서  
	// 3개 도시를 모두 다 방문했다는 것은 (1 << 3) - 1 = 7 로 표현
	completePath = (1 << city) - 1;

	for (int i = 0; i < city; i++)
	{
		for (int j = 0; j < city; j++)
		{
			cin >> cost[i][j];
		}
	} 

	memset(dp, -1, sizeof(dp));

	cout << DFS(0, 1);

	return 0;	
}
