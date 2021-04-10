#include<iostream>
#include <cstring>
#include <queue>
using namespace std;

int memNum; //<50
int map[51][51];
queue<pair<int, int> > myP;	//회원번호, 연결수
int visited[51][51];

void BFS(int curNum)
{
	myP.push(make_pair(curNum, 0));
	visited[curNum][curNum] = -1;

	while (!myP.empty())
	{
		int cNum = myP.front().first;
		int cCount = myP.front().second;
		myP.pop();

		for (int i=1; i<= memNum; i++)
		{
			if (map[cNum][i] == 1 && visited[curNum][i] == 0)
			{
				myP.push(make_pair(i, cCount + 1));
				visited[curNum][i] = cCount + 1;
			}
		}
	}
}

int main()
{
	cin >> memNum;
	memset(map, 0, sizeof(map));
	int a, b;
	while (true)
	{
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= memNum; i++)
	{
		BFS(i);
	}
	/*for (int i = 1; i <= memNum; i++)
	{
		for (int j = 1; j <= memNum; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}*/
	
	//결과 출력
	int max[51];
	memset(max, 0, sizeof(max));
	for (int i = 1; i <= memNum; i++)
	{
		for (int j = 1; j <= memNum; j++)
		{
			if (max[j] < visited[i][j])
			{
				max[j] = visited[i][j];
			}
		}
	}

	int min = 100;
	for (int i = 1; i <= memNum; i++)
	{
		if (min > max[i])
			min = max[i];
	}
	cout << min <<" ";

	vector<int> sMem;
	int cnt = 0;
	for (int i = 1; i <= memNum; i++)
	{
		if (max[i] == min)
		{
			sMem.push_back(i);
			cnt++;
		}
	}
	cout << cnt << endl;

	for (int i = 0; i < sMem.size(); i++)
	{
		cout << sMem[i] << " ";
	}
	

//회장점수 회장후보수
//회장 오름차순 정렬
}
