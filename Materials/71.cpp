#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int boy, cow;
int dir[3] = { {1},{-1},{5} };
bool visited[10001] = { false, };

void BFS(int start)
{
	queue<pair<int, int>> myQ;
	myQ.push(make_pair(start, 0));
	visited[start] = true;

	while (true)
	{
		int cPos = myQ.front().first;
		int cCnt = myQ.front().second;
		myQ.pop();
		if (cPos == cow)
		{
			cout << cCnt;
			break;
		}

		for (int i = 0; i < 3; i++)
		{
			int nPos = cPos + dir[i];

			if (nPos < 0 || nPos > 10000)
				continue;

			if (visited[nPos] == false)
			{
				visited[nPos] = true;
				myQ.push(make_pair(nPos, cCnt + 1));
			}
		}
	}
}

int main() 
{
	cin >> boy >> cow;
	BFS(boy);

	return 0;
}
