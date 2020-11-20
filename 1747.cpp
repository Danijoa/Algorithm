#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#define MAX 2000001	//대강 크기를 잡아줌
using namespace std;

bool a[MAX];	//소수는 true
int main()
{
	fill_n(a, MAX, true);
	a[0] = false;	//소수 아님
	a[1] = false;	//소수 아님

	//2~MAX 까지 소수 구하기
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (a[i] == false) //이미 소수가 아님이 판명됨
		{
			continue;
		}
		
		for (int j = i + i; j < MAX; j += i)
		{
			a[j] = false;
		}
	}

	int n;	//1<=n<=1000000 n보다 크거나 같은 소수이면서 팰린드롬인 수 중 가장 작은 수
	cin >> n;

	vector<int> prime;	//n~MAX 사이 소수 저장
	for (int i = n; i < MAX; i++)
	{
		if (a[i] == true)
		{
			prime.push_back(i);
		}
	}

	int palindrome;	//팰린드롬 확인
	for (int i = 0; i < prime.size(); i++)
	{
		palindrome = 1;
		string s = to_string(prime[i]);
		int front = 0;
		int back = s.length() - 1;

		while (front <= back)
		{
			if (s[front] != s[back])	//팰린드롬 아님
			{
				palindrome = 0;
			}
			front++;
			back--;
		}

		if(palindrome == 1)
		{
			cout << prime[i];
			break;
		}
	}
}
