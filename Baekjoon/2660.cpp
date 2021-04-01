#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int num; //회원수
int relation[51][51]; //회원 친분관계
int score[51]; //회원 점수
int president = MAX; //회장 후보 점수
int number = 0; //회장 후보 수

int main()
{
	for (int i = 1; i < 51; i++) //초기화
	{
		for (int j = 1; j < 51; j++)
		{
			if (i == j)
			{
				relation[i][j] = 0;
			}
			else
			{
				relation[i][j] = MAX;
			}
		}
	}

	for (int i = 1; i < 51; i++) //초기화
	{
		score[i] = MAX;
	}

	cin >> num;

	while (1)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;
		relation[a][b] = relation[b][a] = 1; // 양방향
	}

	for (int k = 1; k <= num; k++) //k를 거쳐
	{
		for (int i = 1; i <= num; i++) //i에서 출발하여
		{
			for (int j = 1; j <= num; j++) //j에 도달하는
			{
				if (relation[i][j] > relation[i][k] + relation[k][j])
				{
					relation[i][j] = relation[i][k] + relation[k][j]; //최소 거리 선택
				}
			}
		}
	}

	for (int i = 1; i <= num; i++)
	{
		int temp = 0;
		for (int j = 1; j <= num; j++)
		{
			if (i == j)
				continue;
			temp = max(temp, relation[i][j]); //i가 친구들j와 가지는 가장 높은 점수를(높을수록 친분이 적음)
		}
		score[i] = temp; //i의 최종 점수로 저장
		president = min(temp, president); //후보i중 가장 낮은 점수를 추출
	}

	for (int i = 1; i <= num; i++)
	{
		if (president == score[i])
			number++;
	}
	cout << president << " "<< number << "\n";

	for (int i = 1; i <= num; i++)
	{
		if (president == score[i])
			cout << i << " ";
	}
}
