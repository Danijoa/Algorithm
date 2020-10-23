#include <iostream>
#include <math.h>
using namespace std;

int n, myX, myY;
int cnt = 0;

void solution(int size, int x, int y)
{
	if (size == 2)
	{
		if ((x == myX) && (y == myY))
		{
			cout << cnt;
			return;
		}
		cnt++;

		if ((x == myX) && (y + 1 == myY))
		{
			cout << cnt;
			return;
		}
		cnt++;

		if ((x + 1 == myX) && (y == myY))
		{
			cout << cnt;
			return;
		}
		cnt++;

		if ((x + 1 == myX) && (y + 1 == myY))
		{
			cout << cnt;
			return;
		}
		cnt++;

		return;
	}

	//1
	solution(size / 2, x, y);
	//2				   
	solution(size / 2, x, y + size / 2);
	//3				   
	solution(size / 2, x + size / 2, y);
	//4				   
	solution(size / 2, x + size / 2, y + size / 2);
}

int main()
{
	cin >> n >> myX >> myY;

	int line = pow(2, n);
	solution(line, 0, 0);

	return 0;
}
