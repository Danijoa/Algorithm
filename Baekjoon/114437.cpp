#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

// 노드 개수
int nodeNum;

// 그래프
vector<int> graphV[50001];

// [노드번호]의 [2의n승]번쨰 조상 노드 번호 저장
int tree[50001][17];	// 2^15 < 50001 < 2^16
// [노드번호]의 깊이 저장
int depth[50001];

void makeConnect()
{
	queue<int> myQ;
	// 1번 노드를 시작(루트)으로
	myQ.push(1);
	// 1번 (2^0=1)조상은 나 자신 
	tree[1][0] = 1;
	// 깊이는 0
	depth[1] = 0;

	while (!myQ.empty())
	{
		// 현재 노드
		int curNode = myQ.front();
		myQ.pop();

		for (int i = 0; i < graphV[curNode].size(); i++)
		{
			// 인접 노드
			int nextNode = graphV[curNode][i];
			// 확인 전이라면
			if (depth[nextNode] == 0)
			{
				// 인접 노드의 (2^0 = 1)칸 위 조상 = 현재 노드
				tree[nextNode][0] = curNode;
				// 인접 노드 깊이 =  현재 노드 깊이 + 1
				depth[nextNode] = depth[curNode] + 1;
				myQ.push(nextNode);
			}
		}
	
	}

}

void calParent()
{
	// 2^j 번째 조상
	for (int i = 1; i < 17; i++)
	{
		// 1~nodeNum번 노드의
		for (int j = 1; j < nodeNum + 1; j++)
		{
			// (j의 2^i-1 조상)번 노드의 2^i-1 조상
			tree[j][i] = tree[tree[j][i - 1]][i - 1];
		}
	}
}

int LCA(int deep, int shallow)
{
	int depthDiff = depth[deep] - depth[shallow];

	// 2^i 번째 조상 노드를 확인하면서 내려오면서
	// 둘의 깊이를 맞추는 과정
	for (int i = 16; i >= 0; i--)
	{
		int jump = pow(2, i);
		if (jump <= depthDiff)
		{
			deep = tree[deep][i];
			depthDiff -= jump;
		}
	}

	// deep의 조상중 하나가 shallow인 경우
	if (deep == shallow)
		return deep;

	int calRemain = depth[deep] - 1;
	while (calRemain > 0)
	{
		if (tree[deep][0] == tree[shallow][0])
			break;

		// 하나씩 올라가면서 확인
		deep = tree[deep][0];
		shallow = tree[shallow][0];
		calRemain--;
	}

	return tree[deep][0];
}

int main()
{
	// 노드 개수
	cin >> nodeNum;

	// 정점
	int u, v;
	for (int i = 0; i < nodeNum - 1; i++)
	{
		cin >> u >> v;
		graphV[u].push_back(v);
		graphV[v].push_back(u);
	}

	// 조상 번호와 깊이 전처리
	makeConnect();

	// 조상 미리 계산해두기
	calParent();

	// (u, v) LCA 계산
	int returnNum; 
	cin >> returnNum;
	int result;
	for (int j = 0; j < returnNum; j++)
	{
		cin >> u >> v;

		// u와 v 중 더 깊은 곳에 위치한 노드를 시작으로 LCA 계산
		result = depth[u] > depth[v] ? LCA(u, v) : LCA(v, u);
		cout << result << "\n";
	}
} 
