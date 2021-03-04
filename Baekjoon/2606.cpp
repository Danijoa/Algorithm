//	BFS version
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101

int n;	//컴터수
int m;	//간선수
vector<int> myGraph[MAX];	//인접리스트
int answer = 0;

void BFS(int s)
{
	int* visited = new int[n+1];
	for (int i = 0; i < n+1; i++)
	{
		visited[i] = 0;
	}
	visited[s] = 1;
	
	queue<int> myQ;
	myQ.push(s);

	while (myQ.empty() != true)
	{
		s = myQ.front();
		myQ.pop();

		for (int i = 0; i < myGraph[s].size(); i++)
		{
			if(visited[myGraph[s][i]] == 0)
			{
				myQ.push(myGraph[s][i]);
				visited[myGraph[s][i]] = 1;
				answer++;
			}
		}
	}
}

int main()
{
	cin >> n;

	cin >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		myGraph[a].push_back(b);
		myGraph[b].push_back(a);
	}
		
	BFS(1);

	cout << answer;
}

/*	DFS version
#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int com;
int vertex;
vector<int> verV[MAX];
int visited[MAX];
int cnt = 0;

void dfs(int node)
{
	visited[node] = 1;
	cnt++;

	for (int i = 0; i < verV[node].size(); i++)
	{
		int cur = verV[node][i];	//이웃노드 확인
		if (visited[cur] == 0)	//방문안했으면
		{
			dfs(cur);
		}
	}
}


int main()
{
	//입력
	cin >> com;
	cin >> vertex;

	for (int i = 0; i < vertex; i++)
	{
		int a, b;
		cin >> a >> b;

		verV[a].push_back(b);
		verV[b].push_back(a);
	}

	//초기화
	for (int i = 0; i < com + 1; i++)
		visited[i] = 0;

	//dfs
	dfs(1);

	//출력
	cout << (cnt - 1);	//첫시작 빼주기

	return 0;
}
*/
