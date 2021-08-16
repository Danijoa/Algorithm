#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

int start = 0;
int target = 123456789;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int main()
{
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 2; j >= 0; j--)
		{
			int num;
			cin >> num;

			if (num == 0)
				num = 9;

			//start += pow(10,  (3 * i + j)) * num;
			start = start * 10 + num;
		}
	}
  
	//cout << start << "\n";

	queue<int> puzzleQ;
	puzzleQ.push(start);

	map<int, int> visitedM;	// <key, value>
	visitedM[start] = 0;	// <start, 0>

	while (!puzzleQ.empty())
	{
		int curNumI = puzzleQ.front();
		puzzleQ.pop();
		
		if (curNumI == target)
			break;

		string curNumS = to_string(curNumI);
		int emptyIndex = curNumS.find('9');	// 시작 위치 인덱스 반환
		
		int curX = emptyIndex / 3;
		int curY = emptyIndex % 3;

		//cout << curX << ", " << curY << "\n";

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dir[i][0];
			int nextY = curY + dir[i][1];

			if (nextX < 0 || nextX >= 3 || nextY < 0 || nextY >= 3)
				continue;

			string temp = curNumS;
			swap(temp[curX * 3 + curY], temp[nextX * 3 + nextY]);

			int nextNumI = stoi(temp);	//string to in
			if (visitedM.count(nextNumI) == 0)	// map.count(x) x를 key로 가진 갯수 반환
			{
				visitedM[nextNumI] = visitedM[curNumI] + 1;
				puzzleQ.push(nextNumI);
			}
		}
	}

	if (visitedM.count(target) != 0)
		cout << visitedM[target];
	else
		cout << -1;
	
	return 0;
}
