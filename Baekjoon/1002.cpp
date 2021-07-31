#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	int aX, aY, aR;
	int bX, bY, bR;
	for (int i = 1; i <= testCase; i++)
	{
		cin >> aX >> aY >> aR >> bX >> bY >> bR;

		double dist = sqrt((aX - bX) * (aX - bX) + (aY - bY) * (aY - bY));
		double subDist = (aR > bR) ? (aR - bR) : (bR - aR);

		// 원 일치 - 무한
		if (dist == 0 && aR == bR)
		{
			cout << "-1\n";
			continue;
		}
		// 원 접점 - 둘 
		else if (dist < (aR + bR) && dist > subDist)
		{
			cout << "2\n";
			continue;
		}
		// 원 접점 - 하나 (1) 하나의 원이 다른 원 외부에 존재 (2) 하나의 원이 다른 원 내부에 존재
		else if (dist == (aR + bR) || dist == subDist)
		{
			cout << "1\n";
			continue;
		}
		// 원 접점 - 없음
		else if (dist > (aR + bR) || dist < subDist)
		{
			cout << "0\n";
			continue;
		}
	}
}
