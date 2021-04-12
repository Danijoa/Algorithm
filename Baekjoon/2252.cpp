#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;

int main()
{
	int studentNUM, compareNUM;
	cin >> studentNUM >> compareNUM;

	vector<int> compVector[MAX];	 //학생들 끼리의 비교 방향그래프
	int stuIndegree[MAX] = { 0 }; 	//각 학생들의 진입차수(=앞에 누군가 있는 조건이면 +1)

	int stu1, stu2; //stu1은 stu2 앞에 있어야 한다
	for (int i = 0; i < compareNUM; i++)
	{
		cin >> stu1 >> stu2;
		compVector[stu1].push_back(stu2);
		stuIndegree[stu2]++;
	}

	queue<int> stuQueue; //진입차수 0인 학생 보관
	for (int i = 1; i <= studentNUM; i++)
	{
		if (stuIndegree[i] == 0)
		{
			stuQueue.push(i);
		}
	}

	while (!stuQueue.empty())
	{
		int curStu = stuQueue.front(); //진입차수 0인 학생 선택
		stuQueue.pop();
		cout << curStu << " ";

		for (int i = 0; i < compVector[curStu].size(); i++) //선택된 학생에 연결되어 있는 학생들
		{
			int neighborStu = compVector[curStu][i]; //차례로 한명씩
			stuIndegree[neighborStu]--; //진입치수 -1 만들기

			if (stuIndegree[neighborStu] == 0) //변경된 진입차수 값이 0인 학색 큐에 보관
			{
				stuQueue.push(neighborStu);
			}
		}
	}
}
