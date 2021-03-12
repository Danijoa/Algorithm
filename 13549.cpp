#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

//시간 가중치가 다르기에 우선순위 큐를 사용하여 3가지 방향을 큐에 넣어주어야 한다

//오름차순 정렬
struct cmp
{
	bool operator()(pair<int, int>&a, pair<int, int>&b)
	{
		if (a.first == b.first)	//첫 인덱스가 같으면 뒤에 인덱스 비교
		{
			return a.second > b.second;	//위치도 더 작은것...이 우선....
		}
		else
			return a.first > b.first; //a가 b보다 큰게 참일 때, true 반환 , a가 더 크다
	}
};

int subin, target;
int answer = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> myQ;	//cost, position
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myQ;
bool visited[MAX];

void BFS()
{
	myQ.push(make_pair(0, subin));
	visited[subin] = true;

	while (!myQ.empty())
	{
		int curTime = myQ.top().first;
		int curPos = myQ.top().second;
		myQ.pop();

		if (curPos == target)
		{ 
			answer = curTime;
			return;
		}

		//순서를 a-(b-c) 가 아닌 (b-c)-a 로 작성하면
		//1->(1+1)=2가 push되고 visited가 참이 되는 순간
		//2의 위치는 이미 vidited되어 있기에 1 ->(1*2)=2는 push 되지 못한다
		//따라서 시간 가중치가 더 적은 1*2가 우선순위큐에 들어가지 못하게 된다
		if (curPos * 2 < MAX && visited[curPos * 2] != true)	//a
		{
			myQ.push(make_pair(curTime, curPos * 2));
			visited[curPos * 2] = true;
		}
		if (curPos + 1 < MAX && visited[curPos + 1] != true)	//b
		{
			myQ.push(make_pair(curTime + 1, curPos + 1));
			visited[curPos + 1] = true;
		}
		if (curPos - 1 >= 0 && visited[curPos - 1] != true)		//c
		{
			myQ.push(make_pair(curTime + 1, curPos - 1));
			visited[curPos - 1] = true;
		}
	}
}

int main()
{
	cin >> subin >> target;
	BFS();
	cout << answer;
	return 0;
}
