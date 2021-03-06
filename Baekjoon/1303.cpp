#include <iostream>
using namespace std;

int width, height;
char map[101][101];
int tempN;
int ansN_w = 0, ansN_b = 0;
int dir[4][2] = { {0,-1}, {0,1},{1,0},{-1,0} };

int DFS(int curX, int curY, char cur)
{
	int calN = 1;
	map[curX][curY] = '1';	//확인한 곳 1로 변경해서 지워주기

	for (int i = 0; i < 4; i++)
	{
		int nextX = curX + dir[i][0];
		int nextY = curY + dir[i][1];

		if (nextX < 0 || nextX >= height || nextY < 0 || nextY >= width)	//범위 밖
			continue;

		if (map[nextX][nextY] == cur)	//아군이면
		{
			calN += DFS(nextX, nextY, cur);	//1씩 반환
		}
	}

	return calN;	//누적값 반환
}

int main()
{
	cin >> width >> height;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//%c앞에 공백을 사용하여 스페이스를 넣으면 \n을 white space로 인식하여 넘김
			scanf_s(" %1c", &map[i][j]);	
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == 'W')
			{
				tempN = DFS(i, j, 'W');	//인접 개수 찾고
				ansN_w += tempN * tempN;	//제곱을 더해준다
			}
			else if (map[i][j] == 'B')
			{
				tempN = DFS(i, j, 'B');
				ansN_b += tempN * tempN;
			}
		}
	}

	cout << ansN_w << " " << ansN_b;

	return 0;
}
/*
#include <iostream>
#include <queue>
using namespace std;

int x, y;
char color[101][101];
queue<pair<int, int>> myQ;
int dirX[4] = {-1, 1, 0, 0};
int dirY[4] = { 0, 0, -1, 1 };
int ansW = 0, ansB = 0;
int tempAns;

int BFS(int i, int j, char curC)
{
	int tempCnt = 0;
	myQ.push(make_pair(i, j));
	color[i][j] = '0';

	while (!myQ.empty())
	{
		int curX = myQ.front().first;
		int curY = myQ.front().second;
		myQ.pop();
		tempCnt++;

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dirX[i];
			int nextY = curY + dirY[i];

			if (nextX < 0 || nextX >= x || nextY < 0 || nextY >= y)
				continue;

			if (color[nextX][nextY] == curC)
			{
				color[nextX][nextY] = '0';
				myQ.push(make_pair(nextX, nextY));
			}
		}
	}

	return tempCnt;
}

int main()
{
	cin >> y >> x;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			//%c앞에 공백을 사용하여 스페이스를 넣으면 \n을 white space로 인식하여 넘김
			scanf_s(" %1c", &color[i][j]);
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (color[i][j] == 'W')
			{
				tempAns = BFS(i, j, 'W');
				ansW += tempAns * tempAns;
			}
			if (color[i][j] == 'B')
			{
				tempAns = BFS(i, j, 'B');
				ansB += tempAns * tempAns;
			}
		}
	}

	cout << ansW << " " << ansB;


	return 0;
}
*/
