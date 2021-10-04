#include <iostream>
#include <vector>
using namespace std;

/*
 각 자리수 별로 나누었다가
 합칠때 자리수 별로 소수로 나누어 보기

 [ ex1 ]
 key = 143(13 * 11)
 p = 11
 0*10=0 0+1=1 1%11=1
 1*10=10 10+4=14 14%11=3
 3*10=30 30+3=33 33%11=0
 => 0이니까 나누어 진다는 의미

 [ ex2 ]
 key = 143(13 * 11)
 p = 5
 0*10=0 0+1=1 1%5=1
 1*10=10 10+4=14 14%5=4
 4*10=40 40+3=43 43%5=3
 => 0이 아니니까 나누어 지지 않다는 의미
*/

bool isDivided(int s, string key)
{
	int sum = 0;

	for (int i = 0; i < key.length(); i++)
	{
		sum *= 10;
		sum += (key[i] - '0');
		sum %= s;
	}

	if (sum == 0)
		return true;
	return false;
}

int main()
{
	// 4~10^100의 숫자 임으로 string으로 받는다
	string key;
	cin >> key;

	// 기준 소수
	int p;
	cin >> p;

	// key가 p 보다 큰 소수의 곱으로 이루어져 있으면 GOOD
	bool answer = true;
	int badSosu;

	// 2~p 숫자 중 소수 아닌 숫자 판별
	bool notSosu[1000001] = { false, };

	// key가 p이하의 소수로 나누어 떨어지면 BAD
	for (int i = 2; i < p; i++)	// 2도 소수임
	{
		if (notSosu[i] == true)
			continue;

		// key를 소수 i로 나누어 보고
		// 나누어 지면 탈출
		if (isDivided(i, key))
		{
			answer = false;
			badSosu = i;
			break;
		}

		// 에라토스테네스의 체로 소수 아닌 숫자 판별
		for (int j = 2 * i; j < p; j += i)
		{
			notSosu[j] = true;
		}
	}

	// 출력
	if (answer)
		cout << "GOOD";
	else
		cout << "BAD " << badSosu;
}
