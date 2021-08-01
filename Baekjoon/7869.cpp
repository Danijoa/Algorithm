
#include <iostream>
#include <math.h>
using namespace std;

//double PI = 3.141592;
double PI = 3.14159265358979f;
double aX, aY, aR;
double bX, bY, bR;

void swap(double&a, double&b)	// ...
{
	double temp = a;
	a = b;
	b = temp;
}

int main()
{
	// 소수점 고정 표현
	cout << fixed;
	// (이땐 소수점) 3자리 고정
	cout.precision(3);

	cin >> aX >> aY >> aR >> bX >> bY >> bR;

	double dist = sqrt((aX - bX) * (aX - bX) + (aY - bY) * (aY - bY));
	
	// a가 더 큰 원으로 만들어 주기
	if (aR < bR)
	{
		swap(aX, bX);
		swap(aY, bY);
		swap(aR, bR);
	}

	// 두 원이 겹치지 않는 경우
	if (dist >= (aR + bR))
	{
		cout << "0.000";
	}
	// 하나의 원이 다른 원 안에 있는 경우
    else if (dist + bR <= aR)
	{
		cout << bR * bR * PI;
		// cout << min(bR, aR) * min(bR, aR) * PI
	}
	// 부분적으로 겹치는 부분이 존재한 경우
	else
	{
		// 두 원 접점의 좌표
		// x = (r1 * r1) - (r2 * r2) + (dist * dist) / (2 * dist)
		// y = sqrt((dist * dist) - (x * x)) 

		double aTheta = acos(((aR * aR) - (bR * bR) + (dist * dist)) / (2 * aR * dist));
		aTheta *= 2;

		double bTheta = acos(((bR * bR) - (aR * aR) + (dist * dist)) / (2 * bR * dist));
		bTheta *= 2;

		// 부채꼴 넓이 - 삼각형 넓이
		// (1) 부채꼴 넒이 = 1/2 * r * 부채꼴 호의 길이
		// = 1/2 * r * (2 * PI * r) * (theta / 360)
		// = r * r * PI * (theta / 360)
		// = r * r * PI * (theta / (2 * PI))
		// = r * r * (theta / 2)
		// (2) 삼각형 넓이 = 밑변 * 높이 * 1/2
		// = ab길이 * (ac길이 * sin(a각도)) * 1/2;

		double aA = (aR * aR * aTheta * 1 / 2) - (aR * aR * sin(aTheta) * 1 / 2);
		double bA = (bR * bR * bTheta * 1 / 2) - (bR * bR * sin(bTheta) * 1 / 2);
		
		cout << aA + bA;		
	}
	
	return 0;	
}
