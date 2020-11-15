#include <iostream>
#include <math.h>
using namespace std;

int c;	//약수 개수 구할 숫자 개수 1<=c<=10
int n;	//숫자 1<=n<=10000
int a; 	//약수 개수

void solution(int n)
{
	a = 0;

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (i == sqrt(n))
			{
				a += 1;
			}
			else
			{
				a += 2;
			}
		}
	}

	cout << n << " " << a << "\n";
}

int main()
{
	int c;	//약수 개수 구할 숫자 개수 1<=c<=10
	int n;	//숫자 1<=n<=10000

	cin >> c;
	while (c != 0)
	{
		c--;
		cin >> n;
		solution(n);
	}

}
