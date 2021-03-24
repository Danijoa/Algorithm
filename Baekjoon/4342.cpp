#include <iostream>
using namespace std;

/*
유클리드 호제법(gcd, 최대공약수)
A = B*q + R
gcd(A, B) = gcd(B, R)
(R=0, gcd(A, B) = B)
*/

void solution(int count, int num1, int num2)
{
	int maxNum = num1 > num2 ? num1 : num2;
	int minNum = num1 <= num2 ? num1 : num2;

	int temp;
	while (true)
	{
		count++;
		temp = maxNum % minNum;

		if (temp == 0)	//경우의 수 1 (a%b=0)
		{
			if (count % 2 != 0)	//홀수면 동혁 승리
				cout << "A wins \n";
			else
				cout << "B wins \n";
			break;
		}
		else
		{
			if ((maxNum / minNum) >= 2)	//경우의 수 2 (a/b>=2)
			{
				if (count % 2 != 0)
					cout << "A wins \n";
				else
					cout << "B wins \n";
				break;
			}
			else	//경우의 수 3 (a/b=1)
			{
				maxNum = minNum;
				minNum = temp;
			}
		}

	}

}

int main()
{
	//큰수 = 큰수 - (작은수의 배수) <- 큰수는 음이 아니여야함
	//큰수를 0으로 만든 사람이 게임 승리
	int firstPlayer, secondPlayer;

	int num1, num2;
	int count;
	while (true)
	{
		cin >> num1 >> num2;
		if (num1 == 0 && num2 == 0)
			break;

		count = 0;
		solution(count, num1, num2);
	}

	return 0;
}
