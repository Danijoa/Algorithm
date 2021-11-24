#include <iostream>

using namespace std;

int dp[21][21] = { 0, };

int Cal(int n, int r)
{
	// 계산되어 있는 결과는 출력
	if (dp[n][r] > 0)
		return dp[n][r];

	if (n == r || r == 0)
		return 1;
	else
		return dp[n][r] = Cal(n - 1, r) + Cal(n - 1, r - 1);
}

int main() 
{
	int n, r;
	cin >> n >> r;

	// 이항계수 nCr : n개 중 r개를 순서를 고려하지 않고 선택하는 방법의 수
	// nCr = nPr/r! = n!/((n-r)!*r!)
	// nCr = n-1Cr + n-1Cr-1
	cout << Cal(n, r);

	return 0;
}
