#include <iostream>
#include <string>

using namespace std;

int qNum;
int step;
unsigned long kIndex;
char alpha;
unsigned long X[101], Y[101], Z[101];
unsigned long L[101];

/*
[ 1. n번째 문자열의 길이 ]
L(n) = L(n-1) + X(n - 1)
	
[ 2. n번째 문자열의, k번째 문자 ]
C(n, k) = 
	if (k <= L(n - 3))
		C(n - 3, k)
	else if (k > L(n - 3))
		C(n - 2, k - L(n - 3))

[ 3. n번째 문자열에서, X/Y/Z의 개수]
X(n) = Z(n - 1)
Y(n) = X(n - 1)
Z(n) = X(n - 1) + Y(n - 1)
*/

void cal1(int n)
{
	for (int i = 2; i <= n; i++)
	{
		L[i] = L[i - 1] + X[i - 1];
	}
}

char cal2(int n, unsigned long k)
{
	if (n == 1)
	{
		return 'X';
	}
	else if (n == 2)
	{
		return k == 1 ? 'Y' : 'Z';
	}
	else if (n == 3)
	{
		return k == 1 ? 'Z' : 'X';
	}
	else
	{
		if (k <= L[n - 3])
			return cal2(n - 3, k);
		else if (k > L[n - 3])
			return cal2(n - 2, k - L[n - 3]);
	}
}

void cal3(int n)
{
	for (int i = 2; i <= n; i++)
	{
		X[i] = Z[i - 1];
		Y[i] = X[i - 1];
		Z[i] = X[i - 1] + Y[i - 1];
	}
}
 
void solution(int n)
{
	X[1] = 1, Y[1] = 0, Z[1] = 0;
	cal3(n);

	L[1] = 1;
	cal1(n);
}

int main()
{
	cin >> qNum >> step;

	if (qNum == 2)
		cin >> kIndex;
	else if (qNum == 3)
		cin >> alpha;

	solution(step);

	// 문자열 길이
	if (qNum == 1)
	{
		cout << L[step];
	}
	// kIndex 번째 문자
	else if (qNum == 2)
	{
		cout << cal2(step, kIndex);
	}
	// alpha 몇개
	else
	{
		if (alpha == 'X')
			cout << X[step];
		else if (alpha == 'Y')
			cout << Y[step];
		else
			cout << Z[step];
	}
}
