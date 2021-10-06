#include <iostream>

using namespace std;

int gate;           // 게이트 수
int plane;          // 비행기 수 (순서대로 도착)
int gi[100001];     // 1 ~ gi 번 게이트 도킹 시도
int parent[100001]; // i번 비행기의 도킹 번호 저장
int answer = 0;
int dock;

int find(int u)
{
    //if (u == parent[u])
    if (parent[u] < 0)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int pre, int cur)
{
    pre = find(pre);
    cur = find(cur);

    parent[cur] = pre;
}

int main()
{
    // 입력
    cin >> gate >> plane;

    // 루트 노드 초기화, 입력
    for (int i = 1; i <= plane; i++)
    {
        parent[i] = -1;
        cin >> gi[i];
    }
    
    //
    for (int i = 1; i <= plane; i++)
    {
        dock = find(gi[i]);

        // 루트가 1 이상이면 게이트가 하나 이상 비어 있다
        if (dock > 0)
        {
            merge(dock - 1, dock);
            answer++;
        }
        // 게이트에 도달못한 비행기 발생
        //추가적 도킹 불가
        else
            break;  
    }

    // 도킹시킬 수 잇는 최대 비행기 수
    cout << answer;

    // ex)
    // gate   1 2 3 4 5 6 7
    // plane  1번 1~2 (o)
    //        2번 1~4 (o)
    //        3번 1~2 (o)
    //        4번 1~1 (x)
    //        5번 1~5 (o)
    // dock   3 1 x 2 x 5 x x
}
