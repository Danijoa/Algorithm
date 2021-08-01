
#include <iostream>
#include <vector>
using namespace std;

int cowNum;
int cowX[5000], cowY[5000];
bool result = false;

void dfs(int curCowNum, vector<pair<int, int> > myV)
{
	// 이미 앞에서 감시 가능으로 판단 되는 경우가 있다면 
	// 뒤에 남아있는 dfs는 수행할 필요 없음
	if (result == true)
	{
		return;
	}

	// 3개로 감시 불가
	if (myV.size() > 3)
	{
		result = false;
		return;
	}

	// 3개 이하로 모든 소감시 가능
	if (curCowNum == cowNum)
	{
		result = true;
		return;
	}

	int curCowX = cowX[curCowNum];
	int curCowY = cowY[curCowNum];

	// 1번 카메라 설치하는 경우
	if (curCowNum == 0)
	{
		// 첫번째 소의 x 라인에 설치
		myV.push_back({ curCowX, -1});
		// 그 다음 카메라 설치할 라인 확인
		dfs(curCowNum + 1, myV);

		// 다시 복구 시킨 후
		myV.pop_back();

		// 첫번째 소의 y 라인에 설치
		myV.push_back({ -1, curCowY });
		// 그 다음 카메라 설치할 라인 확인
		dfs(curCowNum + 1, myV);
	}
	// 2, 3번 카메라 설치하는 경우
	else
	{
		bool isChecking = false;

		for (int i = 0; i < myV.size(); i++)
		{
			// 현재 소는 이미 x 라인에서 관찰 당하는 중이다
			// 그럼 다음 소 확인
			if (curCowX == myV[i].first)
			{
				isChecking = true;
				dfs(curCowNum + 1, myV);
				break;
			}

			// 현재 소는 이미 y 라인에서 관찰 당하는 중이다
			// 그럼 다음 소 확인
			if (curCowY == myV[i].second)
			{
				isChecking = true;
				dfs(curCowNum + 1, myV);
				break;
			}
		}

		// 현재 소가 관찰 당하고 있지 않는 경우
		if (isChecking == false)
		{
			// 현재 소의 x 라인에 설치
			myV.push_back({ curCowX, -1 });
			// 그 다음 카메라 설치할 라인 확인
			dfs(curCowNum + 1, myV);

			// 다시 복구 시킨 후
			myV.pop_back();

			// 현재 소의 y 라인에 설치
			myV.push_back({ -1, curCowY });
			// 그 다음 카메라 설치할 라인 확인
			dfs(curCowNum + 1, myV);
		}
	}
}

int main()
{
	cin >> cowNum;

	for (int i = 0; i < cowNum; i++)
	{
		cin >> cowX[i] >> cowY[i];
	}

	if (cowNum <= 3)
	{
		cout << "1";
		return 0;
	}

	vector<pair<int, int> > myV;
	dfs(0, myV);

	cout << result;

	return 0;	
}
