#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int num, total, mid;
int a[40];
int sum = 0;
long long int result = 0;
map<int, int> cnt;

void dfsL(int idx)
{
	if (idx == mid)
	{
		// sum 이라는 합을 가진 부분 집합이 존재하는 경우
		if (cnt.find(sum) != cnt.end())
			cnt[sum]++;
		// 처음인 경우
		else
			cnt[sum] = 1;
		return;
	}

	// a[idx] 포함시키지는 경우
	sum += a[idx];
	dfsL(idx + 1);

	// a[idx] 포함시키지 않는 경우
	sum -= a[idx];
	dfsL(idx + 1);
}

void dfsR(int idx)
{
	if (idx == num)
	{
		// total - sum 이라는 합을 가진 부분 집합이 존재하는 경우
		// 개수 확인
		if (cnt.find(total - sum) != cnt.end())
			result += cnt[total - sum];
		return;
	}

	sum += a[idx];
	dfsR(idx + 1);

	sum -= a[idx];
	dfsR(idx + 1);
}

int main()
{
	// 입력
	cin >> num >> total;
	for (int i = 0; i < num; i++)
		cin >> a[i];
	mid = num / 2;

	// 왼쪽 절반 탐색 (0 ~ mid-1)
	dfsL(0);
	// 오른쪽 절반 탐색
	sum = 0;
	dfsR(mid);

	// 아무것도 담지 않은 공집합은 개수로 포함시키지 않음 (mid ~ num-1)
	if (total == 0)
		result--;

	// 출력
	cout << result;

	return 0;
}
 
