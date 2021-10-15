#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int answer = 0;
	for (int i = m; i <= n; i += m)
		answer += i;

	cout << answer;
}
