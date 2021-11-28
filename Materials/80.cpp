#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int graph[21][21] = { 0, };
int result[21];

struct Data
{
    int city;
    int dist;

    Data(int city, int dist)
    {
        this->city = city;
        this->dist = dist;
    }
};

struct cmp
{
    bool operator()(Data& a, Data& b)
    {
        return a.dist > b.dist;
    }
};

priority_queue<Data, vector<Data>, cmp> myQ;

void dijkstra(int start)
{
    myQ.push(Data( start, 0 ));
    result[start] = 0;

    while (!myQ.empty())
    {
        int cCity = myQ.top().city;
        myQ.pop();

        for (int i = 1; i < 21; i++)
        {
            int nCity = i;
            if (graph[cCity][nCity] == 0)
                continue;

            if (result[nCity] > result[cCity] + graph[cCity][nCity])
            {
                result[nCity] = result[cCity] + graph[cCity][nCity];
                myQ.push(Data( nCity, result[nCity] ));
            }
        }
    }

}

int main(void)
{    
    int cityNum, roadNum;
    cin >> cityNum >> roadNum;

    int c1, c2, d;
    for (int i = 0; i < roadNum; i++)
    {
        cin >> c1 >> c2 >> d;
        graph[c1][c2] = d;
    }

    fill(result, result + 21, INF);

    dijkstra(1);

    for (int i = 2; i <= cityNum; i++)
    {
        if (result[i] != INF)
            cout << i << " : " << result[i] << "\n";
        else
            cout << i << " : impossible\n";
    }

    return 0;
}
