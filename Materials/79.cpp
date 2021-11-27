#include <iostream>
#include <queue>

using namespace std;

// 노드&비용 정보
struct Data
{
    int c1, c2, cost;

    Data(int c1, int c2, int cost)
    {
        this->c1 = c1;
        this->c2 = c2;
        this->cost = cost;
    }
};

// 비용 오름차순 정렬
struct compare
{
    bool operator()(Data &a, Data &b)
    {
        return a.cost > b.cost;
    }
};

priority_queue<Data, vector<Data>, compare> myQ;

 int parent[30];

// Union Fnind : 사이클 여부 확인
int GetParent(int n)
{
    // 부모 반환
    if (n == parent[n])
        return n;

    return parent[n] = GetParent(parent[n]);
}

void Union(int a, int b)
{
    // 작은 노드를 부모, 큰 노드를 자식으로 만듬 
    if (a < b)
        parent[a] = b;
    else
        parent[b] = a;
}

bool Find(int a, int b)
{
    a = GetParent(a);
    b = GetParent(b);

    // 부모가 같은 경우
    if (a == b)
        return true;
    // 다른 경우
    else
    {
        Union(a, b);
        return false;
    }
}

// 크루스칼 : 사이클을 포함시키지 않고 최소 비용의 간선으로 구성
int main(void)
{    
    int cityNum, roadNum;
    cin >> cityNum >> roadNum;

    int c1, c2, cost;
    for (int i = 0; i < roadNum; i++)
    {
        cin >> c1 >> c2 >> cost;
        myQ.push(Data(c1, c2, cost));
    }

    // 노드 소속 초기화
    for (int i = 0; i < 30; i++)
        parent[i] = i;

    // 최단 비용 계산
    int result = 0;

    // 최단 거리 부터 하나씩 추가하면서
    while (!myQ.empty())
    {
        // 같은 부모가 아닌 경우 = 사이클이 없는 경우
        if (Find(myQ.top().c1, myQ.top().c2) == false)
            result += myQ.top().cost;

        myQ.pop();
    }

    cout << result;

    return 0;
}
