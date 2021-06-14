#include <iostream>
#include <vector>
#include <queue>
#define MAX 501
using namespace std;

int main()
{
	// 총 빌딩 개수
	int build;	
	cin >> build;

	// 각 빌딩 짓기 위한 시간
	int buildTime[MAX];	
	fill(&buildTime[0], &buildTime[MAX - 1], 0);
	// 선 빌딩 개수 
	int buildDegree[MAX];	
	fill(&buildDegree[0], &buildDegree[MAX - 1], 0);
	//선 빌딩 번호
	vector<int> preBuildNum[MAX];	

	// 셋팅
	for (int i = 1; i <= build; i++)
	{
		cin >> buildTime[i];

		while (true)
		{
			int pre;
			cin >> pre;
			if (pre == -1)
				break;

			buildDegree[i]++;
			// 1: [0] 
			// 2: [1]
			// 3: [1]
			// 4: [2]
			// 5: [1]

			preBuildNum[pre].push_back(i);	
			// 1 -> 2, 3, 4 
			// 2 ->
			// 3 -> 4, 5
			// 4 ->
			// 5 ->
		}
	}
	
	// 빌딩 짓기 위한 총 시간
	int totalBuildTime[MAX];
	fill(&totalBuildTime[0], &totalBuildTime[MAX - 1], 0);

	// 선 빌딩 없는 것 부터 시작(가장  먼저 시작해야 하는 것 부터)
	queue<int> myQ;
	for (int i = 1; i <= build; i++)
	{
		if (buildDegree[i] == 0)	//1
		{
			myQ.push(i);
			totalBuildTime[i] = buildTime[i];
		}
	}

	// 계산
	while (!myQ.empty())
	{
		int curBuildNum = myQ.front();	// 1 // 2 // 3
		myQ.pop();

		for (int i = 0; i < preBuildNum[curBuildNum].size(); i++)	// 2 3 4	// - // 4 5
		{
			int nextBuildNum = preBuildNum[curBuildNum][i];
			buildDegree[nextBuildNum] -= 1;

			totalBuildTime[nextBuildNum]
				= max(totalBuildTime[nextBuildNum], totalBuildTime[curBuildNum] + buildTime[nextBuildNum]);
			// result[2] = max(0, 10+10) = 20
			// result[3] = max(0, 10+4) = 14
			// result[4] = max(0, 10+4) = 14
			// -
			// result[4] = max(14, 14+4) = 18
			// result[5] = max(0, 14+3) = 17 ...

			if (buildDegree[nextBuildNum] == 0)
				myQ.push(nextBuildNum);	// 2 3 // - // 4 5 
		}
	}


	for (int i = 1; i <= build; i++)
	{
		cout << totalBuildTime[i] << "\n";
	}

	return 0;
}
 
