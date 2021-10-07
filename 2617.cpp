#include <iostream>
#include <vector>

using namespace std;

// 현재 구슬보다 m+1개 이상의 구슬이 무겁거나 가벼운게 확실하면 중간 구슬 아님
// (방향) 그래프로 나보다 작은 구슬 개수 확인, 무거운 구슬 개수 확인

int n; // 홀수개의 구슬
int m; // n = m + 1 + m 
int c; // 비교 횟수
int h, l; // h < l 무게

vector<int> hGu[100], lGu[100];
bool hVisit[100] = { false, }, lVisit[100] = { false, };

int main()
{                 
	cin >> n >> c;
	m = (n - 1) / 2;
	for (int i = 0; i < c; i++)
	{
		cin >> h >> l;
		hGu[h].push_back(l);
		lGu[l].push_back(h);
	}

	for (int i = 1; i <= n; i++)
	{

	}



}
