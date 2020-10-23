#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int n;	//마을 개수
int m;	//길 개수
int x;	//파티 마을 번호
int** backVill;	//마을 인접 행렬
int** goVill;	//반대로 마을 인접 행렬
int* back;
int* go;
int* temp;
int* visited;

int* dijkstra(int x, int** v)
{
	//temp(거리저장)생성 및 초기화
	temp = new int[n+1];
	for (int i = 0; i < n + 1; i++)
	{
		temp[i] = MAX;
	}
	temp[x] = 0;

	//visited생성 및 초기화
	visited = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		visited[i] = 0;
	}

	int cur = x;
	int check = 0;
	while (check != n)
	{
		check++;

		//cur찾기
		int minimun = MAX;
		for (int i = 1; i < n + 1; i++)
		{
			if ((visited[i] == 0) && (minimun >= temp[i]))
			{
				minimun = temp[i];
				cur = i;
			}
		}
		visited[cur] = 1;

		//cur에서 인접 거리 더하기
		for (int i = 1; i < n+1; i++)
		{
			//i누적거리 > cur누적 거리+ cur에서i까지 거리
			if (temp[i] > temp[cur] + v[cur][i])
			{
				temp[i] = temp[cur] + v[cur][i];
			}
		}
	}

	return temp;
}

int main()
{
	cin >> n >> m >> x;

	//back, go, vill 생성
	back = new int[n + 1];

	go = new int[n + 1];
	
	backVill = new int* [n+1];
	for (int i = 0; i < n+1; i++)
	{
		backVill[i] = new int[n+1];
	}
	
	goVill = new int* [n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		goVill[i] = new int[n + 1];
	}

	//초기화
	for (int i = 0; i < n+1; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			backVill[i][j] = MAX;
			goVill[i][j] = MAX;
		}
	}

	//거리 입력
	int start, end, dis;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> dis;
		backVill[start][end] = dis;
		goVill[end][start] = dis;
	}

	//돌아오는길
	back = dijkstra(x, backVill);

	//가는길
	go = dijkstra(x, goVill);

	//비교 및 결과
	int answer = back[1]+go[1];
	for (int i = 2; i < n + 1; i++)
	{
		answer = max(answer, back[i]+go[i]);
	}
	cout << answer;
}
