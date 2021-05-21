#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 51

int dijkstra(int N, int map[MAX][MAX], int dist[MAX])
{
	queue<int> vill;
	vill.push(1);
	dist[1] = 0;

	while (vill.empty() != true)
	{
		int cur = vill.front();
		vill.pop();

		for (int i = 1; i <= N; i++)
		{
			if (dist[i] > dist[cur] + map[cur][i])
			{
				dist[i] = dist[cur] + map[cur][i];
				vill.push(i);
			}
		}
	}

	return dist[MAX];
}

int solution(int N, vector<vector<int>> road, int K) 
{
	int answer = 0;

	//fill_n
	int dist[MAX];
	int map[MAX][MAX];
	
	for (int m = 1; m <= N; m++)
	{
		dist[m] = 1000001;
		for (int n = 1; n <= N; n++)
		{
			map[m][n] = 1000001;
		}
	}
	for (int i = 0; i < road.size(); i++)
	{
		int vil1 = road[i][0];
		int vil2 = road[i][1];
		int dis = road[i][2];

		map[vil1][vil2] = min(map[vil1][vil2], dis);
		map[vil2][vil1] = min(map[vil2][vil1], dis);
	}

	dist[MAX] = dijkstra(N, map, dist);

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] <= K)
			answer++;
	}

	return answer;
}
