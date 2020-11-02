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
