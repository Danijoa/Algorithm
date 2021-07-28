#include <iostream>
using namespace std;

/*
num [1] [2] [3] [4] 중 3개

solution(1,1) solution(2,2) solution(3,3)
lotto [1] [2] [3]
solution(1,1) solution(2,2) solution(4,3)
lotto [1] [2] [4]
solution(1,1) solution(3,2) solution(4,3)
lotto [1] [3] [4]
solution(2,1) solution(3,2) solution(4,3)
lotto [2] [3] [4]
*/

int pick;
int num[50];
int lotto[7];

void solution(int numIndex, int lottoIndex)
{
	if (lottoIndex == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			cout << lotto[i] << " ";
		}
		cout << "\n";
        return;
	}

	for (int i = numIndex; i <= pick; i++)
	{
		lotto[lottoIndex] = num[i];
		solution(i + 1, lottoIndex + 1);
	}
}

int main()
{
	// 숫자 1~49중 7~12개 골라서 6개 조합

	while (true)
	{
		cin >> pick;

		if (pick == 0)
			break;
		
		for (int i = 1; i <= pick; i++)
		{
			cin >> num[i];
		}

		solution(1, 1);

		cout << "\n";		
	}
}
