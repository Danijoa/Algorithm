#include <iostream>
#define MAX 15
using namespace std;

//queen[i] = j -> i열 j행에 퀸이 있다
//5x5 체스판에 5개의 퀸을 놓을 수 있는 경우 중 하나
//queen[1] = 1
//queen[2] = 3
//queen[3] = 5
//queen[4] = 2
//queen[5] = 4

int num;
int cnt = 0;
int queen[MAX];

bool check(int cur)
{
	//다음 퀸을 놓을 수 없는 경우
	for (int i = 1; i < cur; i++)
	{
		if (queen[i] == queen[cur] || (abs(queen[i] - queen[cur]) == abs(i - cur)))	//같은 행에 있지 않다 || 대각선에 있다
		{
			return false;
		}
	}
	return true;
}

void backTrack(int row)
{
	if (row == num)	//퀸을 다 놓은 경우
	{
		cnt++;
	}
	else	//놓을 퀸이 남은 경우
	{
		for (int i = 1; i <= num; i++)	//+1열씩 증가해가며 퀸 놓을 자리를 확인한다
		{
			queen[row + 1] = i;	//여기 놓을 수 있는가?
			if (check(row + 1))	//가능하면 진행
			{
				backTrack(row + 1);
			}
			else
			{
				queen[row + 1] = 0;
			}
		}
	}
}

int main()
{
	//체스판 크기, 퀸 개수
	cin >> num;
	
	//체스 첫 수를 1열 1행~num행에 퀸을 하나씩 놓아 보는 것으로 시작한다
	for (int i = 1; i <= num; i++)
	{
		queen[1] = i;
		backTrack(1);
	}

	//결과
	cout << cnt;

	return 0;
}
