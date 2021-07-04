/*
int* visited = new int[n];	// 방문 리스트
int** myList;	//인접행렬
myList = new int* [n];
for (int i = 0; i < n; i++)
{
	myList[i] = new int[n];
}
*/
	
#include <iostream>
#include <queue>
#define MAX 102
using namespace std;

int graph[MAX][MAX];    // 가중치 없는 방향그래프
int answer[MAX][MAX] = { 0, };
int vertex;

void BFS(int start)
{
    bool visited[MAX] = { false, };
    //answer[start][start] = 1;
    //visited[start] = true;

    queue<int> myQ;
    myQ.push(start);

    while (!myQ.empty())
    {
        int cur = myQ.front();
        myQ.pop();

        for (int i = 1; i <= vertex; i++)
        {
            if (visited[i] == false && graph[cur][i] == 1)
            {
                myQ.push(i);
                answer[start][i] = 1;
                visited[i] = true;
            }
        }
    }

}

int main()
{
    cin >> vertex;

    for (int i = 1; i <= vertex; i++)
    {
        for (int j = 1; j <= vertex; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i <= vertex; i++)
        BFS(i);

    for (int i = 1; i <= vertex; i++)
    {
        for (int j = 1; j <= vertex; j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}
