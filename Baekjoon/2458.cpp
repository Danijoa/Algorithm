#include <iostream>
#include <string>
#define INF 987654321

using namespace std;

int main()
{
	// 방향은 상관 없이
	// 자신을 제외한 모든 노드와 연결되어 있으면 순서를 알 수 있다
	bool height[501][501] = { false, };

	int student, compare;
	cin >> student >> compare;

	int a, b;
	for (int i = 0; i < compare; i++)
	{
		cin >> a >> b;
		// (i, j)가 직접 열결되어 있음
		height[a][b] = true;
	}

	//cout << endl;
	//for (int i = 1; i <= student; i++)
	//{
	//	for (int j = 1; j <= student; j++)
	//	{
	//		cout << height[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	// 플로이드 와샬
	for (int z = 1; z <= student; z++)
	{
		for (int i = 1; i <= student; i++)
		{
			for (int j = 1; j <= student; j++)
			{
				// (i, j)가 다른 노드를 거쳐서 열결되어 있는지 저장
				if (height[i][z] == true && height[z][j] == true)
					height[i][j] = true;
			}
		}
	}

	//cout << endl;
	//for (int i = 1; i <= student; i++)
	//{
	//	for (int j = 1; j <= student; j++)
	//	{
	//		cout << height[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	int answer = 0;
	for (int i = 1; i <= student; i++)
	{
		int connnect = 0;
		for (int j = 1; j <= student; j++)
		{
			// 자신의 앞 또는 뒤로 연결되어 있는 노드가 있다
			if (height[i][j] == true || height[j][i] == true)
				connnect++;
		}
		
		// i번째 노드는 자신을 제외한 모든 노드와 연결되어 있다
		if (connnect == student - 1)
			answer++;
	}

	cout << answer;

	return 0;
}
