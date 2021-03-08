#include <iostream>
#include <math.h>
using namespace std;
int startX, startY;
int targetX, targetY;
int planetNum;
int cntPlanet;
int planetX, planetY, radius;

int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		cntPlanet = 0;

		cin >> startX >> startY >> targetX >> targetY;

		cin >> planetNum;
		for (int j = 0; j < planetNum; j++)
		{
			cin >> planetX >> planetY >> radius;

			//시작 지점과 도착 지점 사이에 무조건 지나야하는 길이 있는 조건은
			//어느 행성을 기준으로 시작 지점 행성이 내부, 도착 지점 행성이 외부에 있는 경우이다(혹은 그 반대의 경우)
			double diffStart = sqrt(pow((planetX - startX), 2) + pow((planetY - startY), 2));
			double diffTarget = sqrt(pow((planetX - targetX), 2) + pow((planetY - targetY), 2));
			if ((radius - diffStart) * (radius - diffTarget) < 0)
				cntPlanet++;
		}

		cout << cntPlanet << "\n";
	}

	return 0;
}
