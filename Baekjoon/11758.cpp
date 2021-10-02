#include <iostream>
#include <vector>
using namespace std;

// CCW : 점 3개의 방향성을 나타냄
// 세 점으로 이루어진 삼각형의 면적 S
// S > 0 : 반시계 방향
// S = 0 : 일직선
// S < 0 : 시계 방향
// 2 * S = (x2 - x1)(y3 - y1) - (y2 - y1)(x3 - x1)
//       = (x1 * y2) + (x2 * y3) + (x3 * y1) - (y1 * x2) + (y2 * x3) + (y3 * x1) 
// 두 벡터의 외적 값으로 수직 벡터가 그려지는 방향을 보고 알 수 있다

int main()
{
	int p[3][2];
	for (int i = 0; i < 3; i++)
		cin >> p[i][0] >> p[i][1];

	int temp = (p[0][0] * p[1][1]) + (p[1][0] * p[2][1]) + (p[2][0] * p[0][1]);
	temp -= (p[0][1] * p[1][0]) + (p[1][1] * p[2][0]) + (p[2][1] * p[0][0]);

	int answer = 0;
	if (temp > 0)
		answer = 1;
	else if (temp < 0)
		answer = -1;

	cout << answer;
}
