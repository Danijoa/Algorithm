#include <iostream>
#include <queue>
using namespace std;

long long number[10];

void storeNum(long long p, long long index)
{
	for (long long i = p; i > 0; i /= 10)	//(345) -> 34 -> 3
		number[i % 10] += index;	//(5 -> 4 -> 3)
}

int main()
{
	long long page;
	cin >> page;

	long long start = 1;
	long long end = page;

	long long index = 1;
	while (start <= end)
	{
		while (start % 10 != 0 && start <= end)	//시작 페이지의 일의 자리가 0이 되기 전까지 1씩 증가시키며 확인
			storeNum(start++, index);	//345~349

		if (start > end)
			break;

		while (end % 10 != 9 && start <= end)	//끝 페이지의 일의 자리가 9가 되기 전까지 1씩 감소시키며 확인
			storeNum(end--, index);	//1234~1230

		long long zari = (end / 10) - (start / 10) + 1;	//10의 자리 수 차이	(123)-(34)+1=90
		for (int i = 0; i < 10; i++)
			number[i] += zari * index;

		start /= 10;	//349 -> (34) -> 3 
		end /= 10;
		index *= 10;	//1 -> 10 -> 100	:1의 자리 개수 -> 10의 자리 개수 -> 100의 자리 개수
	}

	for (int i = 0; i < 10; i++)
		cout << number[i] << " ";

	return 0;
}
