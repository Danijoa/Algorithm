#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int curGcd, int tempGcd)
{
	if (curGcd % tempGcd == 0)
		return tempGcd;
	else
		return GCD(tempGcd, curGcd % tempGcd);
}

int main()
{
	//여러 개수의 공약수 모두 구하기 -> 최대공약수의 약수 구하기
	int num;
	cin >> num;
	vector<int> numbers;
	int temp;
	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		numbers.push_back(temp);
	}
	sort(numbers.begin(), numbers.end());	//오름 차순 정렬

	//gcd 구하기 (1보다 큰 공약수가 무조건 있다는 조건임)
	int gcd = numbers[1] - numbers[0];	//각 수의 차는 gcd의 배수이다
	for (int i = 2; i < num; i++)
	{
		gcd = GCD(gcd, numbers[i] - numbers[i - 1]);	//ex) 12 24 27
	}

	//gcd의 약수 구하기
	vector<int> result;
	for (int i = 2; i <= gcd / 2; i++)
	{
		if (gcd % i == 0)
			result.push_back(i);
	}
	result.push_back(gcd);

	//출력
	for (int i = 0; i < result.size(); i++)
	{
		cout << result.at(i) << " ";
	}

}
