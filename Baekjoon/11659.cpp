#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0); //c와 c++ 동기화 해제..

int n, m;
vector<int> num;
vector<int> sum;
int s, e;

int main() 
{
	fastio();

	cin >> n >> m;

	num.resize(n + 1);
	sum.resize(n + 1);
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		sum[i] = sum[i - 1] + num[i];
	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		cout << sum[e] - sum[s - 1] << "\n";  //endl은 출력 버퍼를 비우기 때문에 느리니까..
	}

	return 0;
}
