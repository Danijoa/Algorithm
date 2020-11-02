#include <iostream>
using namespace std;

int sudo[9][9];
bool stop = false;

//가로 확인
bool checkRow(int x, int target)
{
	for (int y = 0; y < 9; y++)
	{
		//존재한다
		if (sudo[x][y] == target)
			return false;
	}
	return true;
}

//세로 확인
bool checkCol(int y, int target)
{
	for (int x = 0; x < 9; x++)
	{
		//존재한다
		if (sudo[x][y] == target)
			return false;
	}
	return true;
}

//네모칸 확인
bool checkBox(int x, int y, int target)
{
	int sX = (x / 3) * 3;
	int sY = (y / 3) * 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//존재한다
			if (sudo[sX + i][sY + j] == target)
				return false;
		}
	}
	return true;
}

//위의 세 조건 모두 만족하는지 확인
bool checkThree(int x, int y, int target)
{
	if (checkRow(x, target) && checkCol(y, target) && checkBox(x, y, target))
		return true;
	return false;
}

//비어있는 칸 있으면 채워 넣고 재귀로 다시 돌아옴
void solution()
{ 
	if (stop)
		return;

	//비어있는 위치 찾기
	int curX, curY;
	bool checkOut = true;
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			//cout << "???";
			if (sudo[x][y] == 0)
			{
				//cout << "??";
				checkOut = false;
				curX = x;
				curY = y;
				break;
			}
		}
		if (!checkOut)
			break;
	}

	//더이상 비어있는 칸이 없는 경우
	if (checkOut)
	{
		stop = true;

		//결과 출력
		for (int x = 0; x < 9; x++)
		{
			for (int y = 0; y < 9; y++)
			{
				cout << sudo[x][y] << " ";
			}
			cout << endl;
		}

		return;
	}

	//1~9 들어갈 수 있는지 확인 하고 비어있는칸 채워 넣기
	for (int target = 1; target <= 9; target++)
	{
		if (checkThree(curX, curY, target))
		{
			sudo[curX][curY] = target;
			//재귀
			solution();
			//백트래킹을 위해 다시 0으로
			sudo[curX][curY] = 0;
		}
		//백트래킹을 위해 다시 0으로
		sudo[curX][curY] = 0;
	}
}

int main()
{
	//스도쿠 입력
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			cin >> sudo[x][y];
		}
	}

	//솔루션
	solution();
}
