#include <iostream>
#include <queue>
using namespace std;

int n;	//정점개수
int** myList;	//인접행렬
int** answerList;	//정답행렬

void BFS(int start)
{
	int* visited = new int[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
	}

	queue<int> myQ;
	myQ.push(start);

	int v;
	while (myQ.empty() != true)
	{
		v = myQ.front();
		myQ.pop();

		for (int i = 0; i < n; i++)
		{
			if (myList[v][i] == 1 && visited[i] != 1)
			{
				myQ.push(i);
				answerList[start][i] = 1;
				visited[i] = 1;
			}
		}
	}
}

int main()
{
	//정점 개수 입력
	cin >> n;

	//myList 생성 및 초기화
	myList = new int* [n];
	for (int i = 0; i < n; i++)
	{
		myList[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> myList[i][j];
		}
	}

	//answerList 생성 및 초기화
	answerList = new int* [n];
	for (int i = 0; i < n; i++)
	{
		answerList[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			answerList[i][j] = 0;
		}
	}

	//BFS수행
	for (int i = 0; i < n; i++)
	{
		BFS(i);
	}


	//결과 출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << answerList[i][j] << ' ';
		}
		cout << '\n';
	}
}
