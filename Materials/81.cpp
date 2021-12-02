#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int city, road;
struct Data
{
    int cityF;
    int cityT;
    int cityC;
};
vector<Data> graph;
int dist[101];
int start, target;

void BellmanFord(int start)
{
    dist[start] = 0;

    // (정점 - 1)번 반복
    for (int i = 1; i < city; i++)
    {
        // 모든 간선 탐색
        for (int j = 0; j < road; j++)
        {
            int from = graph[j].cityF;
            int to = graph[j].cityT;
            int fromtoCost = graph[j].cityC;

            // 출발 정점이 한 번이라도 계산 된 정점만 확인
            if (dist[from] == INF)
                continue;
            
            if (dist[to] > dist[from] + fromtoCost)
                dist[to] = dist[from] + fromtoCost;
        }
    }

    // 계산 완료 후 한번 더 탐색 하였을 때
    for (int i = 0; i < road; i++)
    {
        int from = graph[i].cityF;
        int to = graph[i].cityT;
        int fromtoCost = graph[i].cityC;

        if (dist[from] == INF)
            continue;

        // 갱신이 존재하면 음의 사이클
        if (dist[to] > dist[from] + fromtoCost)
        {
            cout << -1;
            return;
        }
    }

    cout << dist[target];
    return;
}

int main(void)
{    
    cin >> city >> road;

    int c1, c2, c;
    for (int i = 0; i < road; i++)
    {
        cin >> c1 >> c2 >> c;
        graph.push_back({c1, c2, c});
    }

    fill(dist, dist + 101, INF);

    cin >> start >> target;
    BellmanFord(start);

    return 0;
}
