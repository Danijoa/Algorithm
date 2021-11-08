#include <iostream>

using namespace std;

int n;
int* num;
int rightHap = 0;
int leftHap = 0;
string ans = "NO";

void DFS(int index)
{
	// 가망 없음
	if (rightHap < leftHap)
		return;

	// 이미 YES로 판별된 친구들
	if (ans.compare("YES") == 0)
		return;

	// 값이 같는 경우
	if (rightHap == leftHap)
	{
		ans = "YES";
		return;
	}

	// 마지막 인덱스 까지 확인
	if (index >= n)
		return;

	rightHap -= num[index];
	leftHap += num[index];
	DFS(index + 1);

	rightHap += num[index];
	leftHap -= num[index];
	DFS(index + 1);
}

int main() 
{
	cin >> n;

	num = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		rightHap += num[i];
	}

	DFS(0);

	cout << ans;
	
	return 0;
}
