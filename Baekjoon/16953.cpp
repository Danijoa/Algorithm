#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int main()
{
	int start, target;
	cin >> start >> target;
	
	int cnt = 0;
	while (true)
	{
		if (start > target)	//가망이 없음
		{
			cout << -1;
			break;
		}
		if (start == target)	//같아지면 출력
		{
			cnt++;
			cout << cnt;
			break;
		}
		if (target % 10 == 1)	//홀수면 마지막에 2를 곱해서 도달한 결과는 아니니까..
		{
			target--;
			target /= 10;
		}
		else if (target % 2 == 0)	//짝수면 2를 곱해서 도달한 결과이까...
		{
			target /= 2;
		}
		else	//일어날 수 없음
		{
			cout << -1;
			break;
		}
		cnt++;
	}
	return 0;
}
