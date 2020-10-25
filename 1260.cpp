#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001
int myGraph[MAX][MAX];
int D_visited[MAX];
int B_visited[MAX];

int N, M, V; //정점 개수, 간선 개수, 시작 정점 번호

void DFS(int v)
{
	cout << v << ' ';

	for (int i = 1; i <= N; i++)
	{
		if (myGraph[v][i] == 1 && D_visited[i] != 1)
		{
			D_visited[i] = 1;
			DFS(i);
		}
	}
	
}

void BFS(int v)
{
	B_visited[v] = 1;

	queue<int> myQ;
	myQ.push(v);

	while (myQ.empty() != true)
	{
		v = myQ.front();
		cout << v << ' ';
		myQ.pop();

		for (int i = 1; i <= N; i++)
		{
			if (myGraph[v][i] == 1 && B_visited[i] != 1)
			{
				myQ.push(i);
				B_visited[i] = 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> V;

	//인접행렬 그래프
	int s, e;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e; // 간전 두 정점 번호
		myGraph[s][e] = 1;
		myGraph[e][s] = 1;
	}

	D_visited[V] = 1;
	DFS(V);
	cout << endl;

	BFS(V);

	return 0;
}
