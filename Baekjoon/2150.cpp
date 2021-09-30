#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 노드, 간선
int node, edge;

// 정방향, 역방향 그래프
vector<int> *graph;
vector<int> *rev_graph;

// 방문 번호
int numCnt = 1;
struct cmp
{
	// pair<numCnt, node index> 내림차순
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		if (a.first < b.first)	// 나중에 들어온게 더 크게
			return true;

		return false;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> storeNum;

// 노드 방문 여부
bool *visited;

// SCC 결과 
vector<vector<int>> SCC;

void DFS(int cur_node)
{
	// 방문 확인
	visited[cur_node] = true;

	for (int i = 0; i < graph[cur_node].size(); i++)
	{
		// 연결 노드
		int next_node = graph[cur_node][i];

		// 방문하지 않았다면 
		if (visited[next_node] != true)
			DFS(next_node);
	}

	// 번호 저장
	storeNum.push(make_pair(numCnt, cur_node));
	numCnt++;
}

void RE_DFS(int cur_node, vector<int> &temp)
{
	// 방문 확인
	visited[cur_node] = true;
	temp.push_back(cur_node);

	for (int i = 0; i < rev_graph[cur_node].size(); i++)
	{
		// 연결 노드
		int next_node = rev_graph[cur_node][i];

		// 방문하지 않았다면 
		if (visited[next_node] != true)
			RE_DFS(next_node, temp);
	}
}

int main()
{
	// 입력
	cin >> node >> edge;

	// vector 동적 할당
	graph = new vector<int>[node + 1];
	rev_graph = new vector<int>[node + 1];

	// 그래프 저장
	int s, e;
	for (int i = 0; i < edge; i++)
	{
		cin >> s >> e;
		graph[s].push_back(e);
		rev_graph[e].push_back(s);
	}

	// 동적 할당 후 초기화
	visited = new bool[node + 1];
	for (int i = 0; i < node + 1; i++)
		visited[i] = false;

	// 정방향 DFS
	for (int i = 1; i < node + 1; i++)
	{
		// 방문하지 않은 노드 선택
		if (visited[i] != true)
			DFS(i);
	}

	// 방문 기록 초기화
	for (int i = 0; i < node + 1; i++)
		visited[i] = false;

	// 역방향 DFS
	for (int i = 0; i < node; i++)
	{
		int node_index = storeNum.top().second;
		storeNum.pop();
		if (visited[node_index] != true)
		{
			vector<int> temp;
			RE_DFS(node_index, temp);
			sort(temp.begin(), temp.end());
			SCC.push_back(temp);
		}
	}

	// SCC 개수
	sort(SCC.begin(), SCC.end());
	cout << SCC.size() << "\n";
	for (int i = 0; i < SCC.size(); i++)
	{ 
		for (int j = 0; j < SCC[i].size(); j++)
		{
			// 정점 번호
			cout << SCC[i][j] << " ";
		}
		cout << "-1\n";
	}

	return 0;	
}
