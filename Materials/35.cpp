#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a, p[100], pCnt = 0, m[100], mCnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a > 0)
		{
			p[pCnt] = a;
			pCnt += 1;
		}
		else
		{
			m[mCnt] = a;
			mCnt += 1;
		}
	}

	for (int i = 0; i < pCnt + mCnt; i++)
	{
		if (i < mCnt)
			cout << m[i] << " ";
		else
			cout << p[i - mCnt] << " ";
	}

	return 0;
}
