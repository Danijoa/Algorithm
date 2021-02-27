#include <iostream>
#define MAX 101
using namespace std;

int num, use;
int order[MAX];	//use개 저장
int store[MAX];	//num개 저장
int cnt = 0;

int main()
{
	cin >> num >> use;
	for (int i = 0; i < use; i++)
	{
		cin >> order[i];
		store[i] = 0;
	}

	for (int i = 0; i < use; i++)
	{
		int cur = order[i];

		//이미 꽂혀있는 경우
		bool plugged = false;
		for (int j = 0; j < num; j++)
		{
			if (store[j] == cur)
			{
				plugged = true;
				break;
			}
		}
		if (plugged == true)
			continue;

		//아래 코드가 작동 된다는 것은 
		//꽂혀 있지 않는 경우
		
		//플로그에 빈곳이 있는 경우
		for (int j = 0; j < num; j++)
		{
			if (store[j] == 0)
			{
				store[j] = cur;
				plugged = true;
				break;
			}
		}
		if (plugged == true)
			continue;

		//플로그에 빈곳이 없는 경우
		//단 한번도 사용되지 않을 기기
		//제일 마지막에 쓰일 기기
		int changeIndex = 0, tempIndex = -1;
		for (int j = 0; j  < num; j++)
		{
			int lastIndex = 0;
			for (int k = i + 1; k < use; k++)	//뒤에 남은 순서 확인
			{
				if (store[j] == order[k])	//뒤에 사용되는 경우
					break;
				lastIndex++;	//인덱스 위치 확인
			}

			if (lastIndex > tempIndex)	//가장 나중에 사용되는 기기 or 영영 사용되지 않을 기기 확인
			{
				changeIndex = j;
				tempIndex = lastIndex;
			}
		}
		cnt++;
		store[changeIndex] = order[i];
	}

	cout << cnt;
	return 0;
}
