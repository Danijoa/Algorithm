#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

typedef struct
{
	int coor[3];	//좌표 {높이, 세로, 가로}
	int dayCnt;	//며칠 흘렀는가
}Coordinate;
queue<Coordinate> myTomato;	//익은 토마토 정보 저장하기

int tomato[MAX][MAX][MAX];	//[높이][세로][가로]
int M, N, H;	//가로, 세로, 높이

int dX[6] = { -1, 1, 0, 0, 0, 0 };	//좌 우 (가로)
int dY[6] = { 0, 0, -1, 1, 0, 0 };	//상 하	(세로)
int dZ[6] = { 0, 0, 0, 0, -1, 1 };	//위 아래	(높이)

int day = 0;	//며칠 지났는가

void bfs()
{
	while (!myTomato.empty())
	{
		int curZ = myTomato.front().coor[0];	//높이
		int curY = myTomato.front().coor[1];	//세로
		int curX = myTomato.front().coor[2];	//가로
		int curDay = myTomato.front().dayCnt;	//날짜
		myTomato.pop();

		for (int i = 0; i < 6; i++)	//좌, 우 , 상, 하, 위, 아래 확인
		{
			int nextX = curX + dX[i];
			int nextY = curY + dY[i];
			int nextZ = curZ + dZ[i];

			if ((nextX >= 1 && nextX <= M) && (nextY >= 1 && nextY <= N) && (nextZ >= 1 && nextZ <= H))	//범위안에 있고
			{
				if (tomato[nextZ][nextY][nextX] == 0)	//안익었으면
				{
					tomato[nextZ][nextY][nextX] = 1;	//익음으로 바꾸고
					myTomato.push({ {nextZ,nextY,nextX}, curDay + 1 });	//큐에 넣기
				}
			}
		}

		day = curDay;
	}
}

int main()
{
	//입력
	cin >> M >> N >> H;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				cin >> tomato[i][j][k];	//-1:토없 0:안익토 1:익토
				if (tomato[i][j][k] == 1)	//익은 토마토 정보 큐에 넣기
				{
					myTomato.push({ {i,j,k}, 0 });	//{높이, 세로, 가로}, {날짜}
				}
			}
		}
	}

	//탐색
	bfs();

	//결과
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (tomato[i][j][k] == 0)	//시간이 지나도 못익는 토마토가 있다
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << day;
	return 0;
}
