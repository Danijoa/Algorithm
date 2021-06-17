#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int h, w;
int map[11][11] = { 0, };
int labelMap[11][11] = { 0, };

int parent[7] = { 0, };	// 각 섬의 부모 저장

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

set<pair<int, pair<int, int>>> myS;	// 거리, 섬1, 섬2 (중복 제거를 위해 사용)
vector<pair<int, pair<int, int>>> myV;	// (정렬 및 ...)

/* find: 재귀를 통해 루트 노드 찾아 저장한다 */
int find(int num)
{
	if (parent[num] == num)	// 루트 노드의 부모는 자기 자신으로 저장되어 있다
		return num;
	else
		return parent[num] = find(parent[num]);	// 현재 num 노드의 현재 부모 노드를 타고 올라가 root 노드를 찾은 후 저장한다
}

/* union(합) : 바로 위 부모 노드를 저장해 준다 */
void merge(int island_1, int island_2)
{
	island_1 = find(island_1);
	island_2 = find(island_2);

	if (island_1 < island_2)	// 거리 짧은걸 부모로
		parent[island_2] = island_1;
	else
		parent[island_1] = island_2;
}

/* kruskal 알고리즘 : 그래프 내 모든 정점들을 가장 적은 비용으로 연결(MST: 최소 신장 트리)*/
int kruskal()
{
	// 거리 순으로 정렬
	sort(myV.begin(), myV.end()); 

	int len = 0;
	for (int i = 0; i < myV.size(); i++)
	{
		int dist = myV[i].first;
		int island_1 = myV[i].second.first;
		int island_2 = myV[i].second.second;

		if (find(island_1) == find(island_2))
			continue;

		merge(island_1, island_2);
		len += dist;
	}
	return len;
}

bool isAllConnected(int label)
{
	// 
	int parent = find(1);
	for (int i = 2; i <= label; i++)
		if (parent != find(i))
			return false;
	return true;
}

void makeBridge(int x, int y)
{
	// 상 하 좌 우 
	for (int i = 0; i < 4; i++)
	{
		int bridgeLen = 0;

		// 시작 섬 좌표에서
		int idxX = x;
		int idxY = y;
		int curLabel = labelMap[idxX][idxY];

		while (true)
		{
			// 한쪽 방향으로 직진하면서 확인
			idxX += dir[i][0];
			idxY += dir[i][1];
			int nextLabel = labelMap[idxX][idxY];

			// 범위 확인
			if (idxX < 0 || idxX >= h || idxY < 0 || idxY >= w || nextLabel == curLabel)
				break;

			// 바다가 아닌 다른 섬에 도착 한 경우
			if (nextLabel != 0 && nextLabel != curLabel)
			{
				if (nextLabel < curLabel)	// 섬 번호가 작은 것 부터 저장하기 위한 확인
					swap(nextLabel, curLabel);

				if (bridgeLen > 1)	// 현재까지 지어진 다리 길이가 1보다 크면 저장
					myS.insert({ bridgeLen, {curLabel, nextLabel} });

				break;
			}
			else
				bridgeLen ++;
		}
	}
}

void dfs(int x, int y, int label)
{
	labelMap[x][y] = label;

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dir[i][0];
		int nextY = y + dir[i][1];

		if (nextX >=0 && nextX < h && nextY >= 0 && nextY < w)
		{
			if (map[nextX][nextY] == 1 && labelMap[nextX][nextY] == 0)
			{
				dfs(nextX, nextY, label);
			}
		}
	}
}

int main()
{
	// 섬 만들기
	cin >> h >> w;
	for (int x = 0; x < h; x++)
	{
		for (int y = 0; y < w; y++)
		{
			cin >> map[x][y];
		}
	}

	// 섬 라벨링 
	int label = 0;
	for (int x = 0; x < h; x++)
	{
		for (int y = 0; y < w; y++)
		{
			if (map[x][y] == 1 && labelMap[x][y] == 0)
			{
				label++;
				dfs(x, y, label);
			}
		}
	}

	// 다리 저장
	for (int x = 0; x < h; x++)
	{
		for (int y = 0; y < w; y++)
		{
			if (map[x][y] == 1)
				makeBridge(x, y);
		}
	}

	// set 내용을 vector에 옮기기
	for (auto i : myS)
		myV.push_back(i);

	// 초기 부모 설정
	for (int i = 1; i <= label; i++)
		parent[i] = i;

	// 다리 길이 총합 저장
	int totalLen = kruskal();

	// 모든 섬이 연결되어 있으면 출력
	if (isAllConnected(label) == true)
		cout << totalLen << "\n";
	else
		cout << "-1" << "\n";

	return 0;
}
