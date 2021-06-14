#include <iostream>
#include <algorithm>
using namespace std;

int map[3][3];
int cntTurn = 0;

bool checkWin(int turn)
{
	// 가로 3줄 빙고 확인
	for (int i = 0; i < 3; i++)
	{
		if (map[i][0] == turn && map[i][0] == map[i][1] && map[i][1] == map[i][2])
			return true;
	}

	// 세로 3줄 빙고 확인
	for (int j = 0; j < 3; j++)
	{
		if (map[0][j] == turn && map[0][j] == map[1][j] && map[1][j] == map[2][j])
			return true;
	}

	// ↘
	if (map[0][0] == turn && map[0][0] == map[1][1] && map[1][1] == map[2][2])
		return true;

	// ↙
	if (map[0][2] == turn && map[0][2] == map[1][1] && map[1][1] == map[2][0])
		return true;

	// 그 외
	return false;
}

int backTrack(int myTurn)
{
	// 상대방이 이긴 경우
	int oppTurn = 3 - myTurn;
	if (checkWin(oppTurn) == true)
		return -1;

	// 브루트 포스 : 가능한 모든 경우의 수를 완전(전체) 탐색
	int result = 2;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = myTurn;	// 비어있는 곳에 놓기

				/* 모든 경우의 수에서 한번이라도 -1이 있다면  내가 이기는 경우가 존재한다는 뜻 */
				// 현재 상태에서 상대방이 놓은 수의 최종 결과 반환하는 
				// backTrack(oppTurn)가 -1 이면 
				// myTurn 즉, 내가 이긴 것이다
				result = min(result, backTrack(oppTurn));

				map[i][j] = 0;	// 다시 되돌리기
			}
		}
	}

	// 짐
	if (result == 1)
		return -1;

	// 이김
	if (result == -1)
		return 1;

	// 무승부: result == 2, 0
	return 0;
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0)
				cntTurn++;
		}
	}

	int ans;
	if (cntTurn % 2 == 0)	// 1 차례
		ans = backTrack(1);
	else	// 2 차례
		ans = backTrack(2);

	if (ans == 0)
		cout << "D";
	else if (ans == 1)
		cout << "W";
	else
		cout << "L";

	return 0;
}
 
