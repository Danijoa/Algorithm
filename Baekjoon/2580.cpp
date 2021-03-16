#include <iostream>
using namespace std;

int sudo[9][9];
bool stop = false;

bool checkRow(int x, int num)	//행 확인
{
	for (int y = 0; y < 9; y++)
	{
		if (sudo[x][y] == num)
			return false;
	}
	return true;
}

bool checkCol(int y, int num)	//num과 같은 숫자가 있는지 sudo[ ][y]열 확인
{
	for (int x = 0; x < 9; x++)
	{
		if (sudo[x][y] == num)
			return false;
	}
	return true;
}

bool checkBox(int x, int y, int num)	//네모칸 확인
{
	int sX = (x / 3) * 3;	//현재 위치x가 포함된 네모칸의 첫 x값 위치 찾기
	int sY = (y / 3) * 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (sudo[sX + i][sY + j] == num)
				return false;
		}
	}
	return true;
}


bool checkThree(int x, int y, int num)
{
	if (checkRow(x, num) && checkCol(y, num) && checkBox(x, y, num))	//셋 다 만족
		return true;
	return false;
}

void solution()
{
	if (stop)
		return;

	bool checkFin = true;	//비어있는곳이 없나 있나 확인
	int curX, curY;
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (sudo[x][y] == 0)	//비어있는 곳이 있다
			{
				checkFin = false;
				curX = x;
				curY = y;
				break;
			}
		}
		if (!checkFin)
			break;
	}

	if (checkFin == true)	//비어있는 곳이 없다
	{
		stop = true;	//여러가지 케이스 중 처음 경우를 만족하면멈추도록 하는 장치

		for (int x = 0; x < 9; x++)
		{
			for (int y = 0; y < 9; y++)
			{
				cout << sudo[x][y] << " ";
			}
			cout << endl;
		}
		return;	//출력하고 끝내기
	}

	for (int num = 1; num <= 9; num++)	//비어있는 곳에 뭐 넣을까?
	{
		if (checkThree(curX, curY, num))	//1~9까지 하나하나 확인하며, 넣을 수 있는지 확인
		{
			sudo[curX][curY] = num;	//넣을 수 있으면 대입
			solution();	//나머지 비어있는 곳 확인을 위한 재귀
			sudo[curX][curY] = 0;	//방금 넣은거 외에 다른 것도 넣어보기 위함
		}
	}
}

int main()
{
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			cin >> sudo[x][y];
		} 
	}
	
	solution();
}
