#include <iostream>
using namespace std;

int main()
{
	int cycle;
	cin >> cycle;

	//cal[i][j] -> cur = i, 끝자리 = j (누적)
	long long int cal[65][10] = {0, };	//cal[jari][j] jari수 마지막 위치에 a가 들어가는 경우의 수
	while (cycle!= 0)
	{
		int cur;
		cin >> cur;

		for (int j = 0; j < 10; j++)	//한자리수 경우의 수를 초기화 해서 저장해 둔다
		{
			cal[1][j] = j + 1.0;
		}
		for (int i = 2; i <= cur; i++)	//2자이수~jari자리수 까지 완성 시켜야 한다
		{
			cal[i][0] = 1;	//마지막 자리가 0인 경우의 수 입력해 주기
			for(int j = 1; j<10; j++)
			{
				cal[i][j] = cal[i - 1][j] + cal[i][j - 1];
			}
		}

		cout << cal[cur][9] << "\n";

		cycle--;
	}
}
