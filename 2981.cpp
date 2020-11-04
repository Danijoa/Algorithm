#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return GCD(b, a % b);
}

int main()
{
	//입력 받기
	int num;	
	cin >> num;

	int number[100]; 
	for (int i = 0; i < num; i++)
	{
		cin >> number[i];
	}
	sort(number, number + num);

	//약수가 무조건 있는 조건이니까,
	//각 수들의 차는 최대공약수 M의 배수가 된다.
	//따라서 GCD를 구하는 함수를 통하여 최대공약수를 구하고,
	//그 값의 약수를 나열하면 된다
	int gcd = number[1] - number[0];
	for (int i = 2; i < num; i++)
	{
		gcd = GCD(gcd, number[i] - number[i - 1]);
	}

	//최대공약수의 약수구하기
	vector<int> result;
	/*
	for (int i = 2; i * i <= gcd; i++)
	{
		if (gcd % i == 0)
		{
			result.push_back(i);
			result.push_back(gcd / i);
		}
	}
	result.push_back(gcd);

	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	*/
	for (int i = 2; i <= gcd/ 2; i++)
	{
		if (gcd % i == 0)
		{
			result.push_back(i);

		}
	}
    result.push_back(gcd);

	//결과 출력하기
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}
