#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int vertex, edge, start;
int map[MAX][MAX];
int dVisited[MAX];
int bVisited[MAX];

void dfs(int curNode)
{
	cout << curNode << " ";	//루트 부터 노드 출력

	for (int i = 1; i <= vertex; i++)
	{
		if (map[curNode][i] == 1 && dVisited[i] == 0)	//방문 안한 인접 노드가 있다면 처리
		{
			dVisited[i] = 1;
			dfs(i);
		}
	}
}

void bfs(int startNode)
{
	queue<int> myQ;	//루트 노드에 대한 설정
	myQ.push(startNode);
	bVisited[startNode] = 1;

	while (!myQ.empty())
	{
		int curNode = myQ.front();
		myQ.pop();
		cout << curNode << " ";	//큐를 pop하며 방문 노드 출력

		for (int i = 1; i <= vertex; i++)
		{
			if (map[curNode][i] == 1 && bVisited[i] == 0)	//방문 안한 인접 노드가 있다면 처리
			{
				myQ.push(i);
				bVisited[i] = 1;
			}

		}
	}

}

int main()
{
	cin >> vertex >> edge >> start;
	int a, b;
	for (int i = 0; i < edge; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	//DFS
	dVisited[start] = 1;	//루트 노드 먼저 방문 처리
	dfs(start);
	cout << endl;

	//BFS
	bfs(start);

	return 0;
}
