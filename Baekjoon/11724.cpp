#include <iostream>
#include <queue>
using namespace std;

int n, m;	//정점개수, 간선개수
int** myList;	//인접행렬
int answer = 0;
int* visited;	//방문확인

void BFS(int vertex)
{
	answer++;

	queue<int> myQ;
	myQ.push(vertex);

	while (myQ.empty() != true)
	{
		vertex = myQ.front();
		myQ.pop();

		for (int i = 1; i < n+1; i++)
		{
			if (myList[vertex][i] == 1 && visited[i] != 1)
			{
				visited[i] = 1;
				myQ.push(i);
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	myList = new int* [n+1];	//인접행렬
	for (int i = 0; i < n+1; i++)
	{
		myList[i] = new int[n+1];
	}

	int a, b;
	for (int i = 1; i <= m; i++)	//연결되어있으면 1
	{
		cin >> a >> b;
		myList[a][b] = 1;
		myList[b][a] = 1;
	}

	visited = new int[n + 1];	//방문확인
	for (int i = 0; i < n + 1; i++)
	{
		visited[i] = 0;
	}
	for (int i = 1; i < n + 1; i++)	//0은 무시 1~n확인
	{
		if (visited[i] == 0)
		{
			BFS(i);
		}
	}

	cout << answer;
}
