#include <iostream>
using namespace std;

int n;
int tarX, tarY;
int cnt = 0;

void solution(int size, int curX, int curY)
{
	if (curX == tarX && curY == tarY)
	{
		cout << cnt;
		return;
	}
	cnt++;	//해당 위치와 일치하지 않으면 +1씩 증가해나감
	if (curX == tarX && curY + 1 == tarY)
	{
		cout << cnt;
		return;
	}
	cnt++;
	if (curX + 1 == tarX && curY == tarY)
	{
		cout << cnt;
		return;
	}
	cnt++;
	if (curX + 1 == tarX && curY + 1 == tarY)
	{
		cout << cnt;
		return;
	}
	cnt++;

	return;
}

int main()
{
	cin >> n >> tarX >> tarY;
	int size = 1 << n;	//2진수 shift 연산

	//타겟 위치가 사각형에서 몇사분면에 있는지 4등분으로 나누어 가며 확인
	int position;
	while (size != 2)
	{
		if (tarX < size / 2)
		{
			if (tarY < size / 2)
			{
				position = 1;
			}
			else
			{
				position = 2;
				tarY -= (size / 2);
			}
		}
		else
		{
			if (tarY < size / 2)
			{
				position = 3;
				tarX -= (size / 2);
			}
			else
			{
				position = 4;
				tarX -= (size / 2);
				tarY -= (size / 2);
			}
		}

		size = size / 2;
		cnt += size * size * (position - 1);
	}

	solution(size, 0, 0);

	return 0;
}
