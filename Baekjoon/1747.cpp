#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#define MAX 2000001	//대강 크기 잡아준자
using namespace std;

bool sosu[MAX];	//소수는 true
int main()
{
	int num;
	cin >> num;

	fill_n(sosu, MAX, true);
	sosu[0] = false;	//0 소수 아님
	sosu[1] = false;	//1 소수 아님

	//2~MAX-1 소수 구하기
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (sosu[i] == false) //이미 소수 아닌 수
		{
			continue;
		}

		int k = 2;
		while (i * k < MAX)	//어느 숫자의 배수는 소수가 아니다
		{
			sosu[i * k] = false;
			k++;
		}
	}

	//소수 저장
	vector<int> isSosu;
	for (int i = num; i < MAX; i++)
	{
		if (sosu[i] == true)
		{
			isSosu.push_back(i);
		}
	}

	//소수 중 팰린드롬 확인
	bool palindrome;	
	for (int i = 0; i < isSosu.size(); i++)
	{
		palindrome = true;
		string numS = to_string(isSosu[i]);
		int front = 0;
		int back = numS.length() - 1;

		while (front <= back)
		{
			if (numS[front] != numS[back])	//char 비교
			{
				palindrome = false;	//팰린드롬 아님
			}
			front++;
			back--;
		}

		if (palindrome == true)	//맞음
		{
			cout << isSosu[i];
			break;
		}
	}

	return 0;
}
