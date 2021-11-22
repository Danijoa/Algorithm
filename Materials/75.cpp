#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Data
{
	int pay;
	int day;
};

bool cmp(Data& a, Data& b)
{
	if (a.day == b.day)
		return a.pay > b.pay;

	return a.day > b.day;
}


int main() 
{
	int lecNum;
	cin >> lecNum;

	// 우선 날짜 순으로 내림차순 정렬
	vector<Data> myV;
	int day, pay;
	for (int i = 0; i < lecNum; i++)
	{
		cin >> pay >> day;
		myV.push_back({ pay, day });
	}
	sort(myV.begin(), myV.end(), cmp);

	// 페이 값을 내림 차순으로 넣을 것이다
	priority_queue<int> myQ;
	int maxDay = myV[0].day;
	int result = 0;

	int jIdx = 0;
	for (int i = maxDay; i >= 1; i--)
	{
		for (int j= jIdx; j< lecNum; j++)
		{
			if (myV[j].day < i)
			{
				jIdx = j;
				break;
			}
			
			// 마지막 날짜의 최고 페이를 먼저 선택하게 되며 
			// 이후에는 날자 별로 큐에 페이를 넣게 된다
			myQ.push(myV[j].pay);
		}

		// 큐에 있는 최고 페이를 먼저 선택한다
		if(!myQ.empty())
		{
			result += myQ.top();
			myQ.pop();
		}
	}
	
	cout << result;

	return 0;
}
