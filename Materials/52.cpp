#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int count;
	cin >> count;
	
	// v[n] = n 번째 ugly number;
	vector<int> v;
	v.push_back(0);
	v.push_back(1);

	// 2, 3, 5씩 증가하는 값의 위치를 나타냄
	int p2 = 1, p3 = 1, p5 = 1;
	
	int min;
	for (int i = 2; i <= count; i++)
	{
		// p2와 p3 비교
		if (v[p2] * 2 < v[p3] * 3)
			min = v[p2] * 2;
		else
			min = v[p3] * 3;

		// (p2/p3)와 p5 비교
		if (min > v[p5] * 5)
			min = v[p5] * 5;

		// 가장 작은값 선택
		v.push_back(min);

		// 선택 된 포인터 위치 증가
		if (min == v[p2] * 2)
			p2++;
		if (min == v[p3] * 3)
			p3++;
		if (min == v[p5] * 5)
			p5++;
	}

	cout << v[count];

	return 0;
}
