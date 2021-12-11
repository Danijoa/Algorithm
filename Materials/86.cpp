#include <iostream>
#include <vector>

using namespace std;

int map, pick;
struct Coor
{
    int x, y;
    Coor(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
vector<Coor> house;
vector<Coor> pizza;
int result = 987654321;
int choosen[13];

// 현재 피자집 번호, 선택한 피자집 개수
void dfs(int num, int cnt)
{
    if (cnt == pick)
    {
        // 모든 집에서 피자집 최단 거리 합 구하기
        int totalMin = 0;
        for (int i = 0; i < house.size(); i++)
        {
            // 각 집에서 가장 가까운 피자집 거리 찾기
            int distMin = 987654321;
            for (int j = 0; j < pick; j++)
            {
                int pizzaIdx = choosen[j];
                int temp = abs(house[i].x - pizza[pizzaIdx].x) + abs(house[i].y - pizza[pizzaIdx].y);

                if (distMin > temp)
                    distMin = temp;
            }
            
            totalMin += distMin;
        }

        // 현재 선택한 피자집이 최단 거리인가 비교
        if (result > totalMin)
            result = totalMin;
        //return;
    }
    else
    {
        /*
        for (int i = num; i < pizza.size(); i++)
        {
            choosen[cnt] = i;
            dfs(i + 1, cnt + 1);
        }
        */

        // 선택안함
        if(pizza.size() - (num + 1) >= pick - cnt )
            dfs(num + 1, cnt);

        // 선택함
        choosen[cnt] = num;
        dfs(num + 1, cnt + 1);
    }
}

int main(void)
{    
    cin >> map >> pick;

    for (int i = 0; i < map; i++)
    {
        for (int j = 0; j < map; j++)
        {
            int c;
            cin >> c;
            if (c == 1)
                house.push_back(Coor(i, j));
            else if(c == 2)
                pizza.push_back(Coor(i, j));
        }
    }

    dfs(0, 0);
    cout << result;

    return 0;
}
