#include <iostream>
using namespace std;

int rowSize;
int cnt = 0;

bool check(int checkRow, int queen[])
{
	for (int i = 1; i <= rowSize; i++)
	{
		// 같은 열에(col) 또 다른 퀸이 있다
		// 같은 대각선에 또 다른 퀸이 있다
		if ((queen[i] == queen[checkRow])||
			(abs(queen[i] - queen[checkRow]) == abs(i - checkRow)))
		{
			return false;
		}
	}

	return true;
}

void backTrack(int curRow, int queen[])
{
	// 퀸을 다 놓은 경우
	if (curRow == rowSize)
		cnt++;
	// 놓을 퀸이 남아 있는 경우
	else
	{
		for (int i = 1; i <= rowSize; i++)
		{
			// (curRow + 1)행 i열에 놓아보기
			queen[curRow + 1] = i;
			
			// 놓을 수 있는 경우
			if (check(curRow + 1, queen))
				backTrack(rowSize, queen);
			// 놓을 수 없는 경우
			else
				queen[curRow + 1] = 0;
		}

	}
}

int main()
{
	cin >> rowSize;

	int queen[15];
	for (int i = 1; i <= rowSize; i++)
	{
		// 1행 i열에 놓고 시작
		queen[1] = i;
		backTrack(1, queen);
	}

	cout << cnt;
}  
