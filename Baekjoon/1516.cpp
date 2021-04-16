#include <iostream>
#include <vector>
#include <queue>
#define MAX 501
using namespace std;

int main()
{
	int num;
	cin >> num;

	int buildTime[MAX] = { 0 }; //각 빌딩 짓는 시간 저장 + 선행 빌딩 시간 추가
	int indegree[MAX] = { 0 };
	vector<int> preV[MAX];
	for (int i = 1; i <= num; i++)
	{
		int time;
		cin >> time;
		buildTime[i] = time;

		while (true)
		{
			int pre;
			cin >> pre;
			if (pre == -1)
			{
				break;
			}
			preV[pre].push_back(i); //pre->i
			indegree[i]++;
		}
	}
/*
[indegree]
0 1 1 2 1
[preV]
1 ->2->3->4
2
3 ->4->5
4
5
*/

	int resultTime[MAX] = { 0 }; 
	//result[i] = 우선적으로 지어야 하는 건물들 중에서 가장 오래 걸리는 시간 + i건물 짓기 위해 걸리는 시간

	queue<int> buildQ;
	for (int i = 1; i <= num; i++)
	{
		if (indegree[i] == 0)
		{
			buildQ.push(i); //1
			resultTime[i] = buildTime[i]; //resultTime[1] = 10
		}
	}

	while (!buildQ.empty())
	{
		int curBuild = buildQ.front(); //1 //2 //3
		buildQ.pop();

		for (int i = 0; i < preV[curBuild].size(); i++) //2 3 4 //- //4 5
		{
			int nextBuild = preV[curBuild][i];
			indegree[nextBuild]--;

			resultTime[nextBuild] = max(resultTime[nextBuild], resultTime[curBuild] + buildTime[nextBuild]);
			//result[2] = max(0, 10+10) = 20
			//result[3] = max(0, 10+4) = 14
			//result[4] = max(0, 10+4) = 14
			//-
			//result[4] = max(14, 14+4) = 18
			//result[5] = max(0, 14+3) = 17 ...

			if (indegree[nextBuild] == 0)
			{
				buildQ.push(nextBuild); //2 3 //- //4 5 
			}
		}

	}

	for (int i = 1; i <= num; i++)
	{
		cout << resultTime[i] << "\n";
	}
}
