#include <iostream>
using namespace std;

int queen[15]; //각 줄의 퀸을 저장
int N;
int cnt;

void backtrack(int x) //파라매터는 퀸을 놓을 좌표
{
	//다음 퀸i를 놓을 수 없는 경우
	for (int i = 0; i < x; i++)
	{
		if ((queen[i] == queen[x]) 
			|| (abs(queen[i] - queen[x]) == abs(i - x)))
		{
			return;
		}
	}

	//퀸을 다 놓은 경우
	if (x == N - 1)
	{
		cnt++; 
		return;
	}

	//x+1번째 줄에 하나씩 퀸을 놓아본다
	for (int i = 0; i < N; i++)
	{
		queen[x + 1] = i;
		backtrack(x + 1);
	}
}

int main()
{
	cin >> N;

	//1열 1행~N행에 퀸을 하나씩 놓아본다
	for (int i = 0; i < N; i++)
	{
		queen[0] = i;	//i행 0열에 퀸이 있다
		backtrack(0);
	}

	cout << cnt;
}
