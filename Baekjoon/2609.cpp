#include <iostream>

using namespace std;

// 최대공약수 Greatest Common Divisor
int GCD(int a, int b)
{
	if (b == 0)
	{
		cout << a << endl;
		return a;
	}
	return GCD(b, a % b);
}

// 최소공배수 Least Common Multiple
void LCM(int a, int b, int c)
{
	cout << (a * b) / c;
}

int main()
{
	int a, b;
	cin >> a >> b;

	int c = GCD(a, b);	
	LCM(a, b, c);	

	return 0;
}
