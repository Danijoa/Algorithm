#include <iostream>
#include <queue>
using namespace std;

struct myData
{
	int time;	//
	int out;
	int store;
};

int main()
{
	int smile;
	cin >> smile;

	int hwaMeun = 1;
	int clipBoard = 0;

	int visit[2001];
	queue<myData> myQ;
	myQ.push({ 0, hwaMeun, clipBoard });
	visit[hwaMeun] = 1;

	while (!myQ.empty())
	{
		int curT = myQ.front().time;
		int curH = myQ.front().out;
		int curC = myQ.front().store;
		myQ.pop();
		
		if (curH == smile)
		{
			cout << curT;
			break;
		}

		//화면에 있는 이모티콘 중 하나를 삭제한다
		if (curH != 0 && visit[curH - 1] != 1)
		{
			myQ.push({ curT + 1, curH - 1, curC });
			visit[curH - 1] = 1;
		}
		//클립보드에 있는 이모티콘을 화면에 붙여넣기
		if (curC != 0 && curH + curC <= 2000)
		{
			myQ.push({ curT + 1, curH + curC, curC });
			visit[curH + curC] = 1;
		}
		//화면에 있는 이모티콘을 복사해서 클립보드에 저장
		if (curH != 0)
		{
			myQ.push({ curT + 1, curH, curH });
		}
	}

	return 0;
} 
