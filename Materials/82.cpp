#include <iostream>
#include <vector>

using namespace std;

// n개의 자연수 중 p개 뽑아 일렬로 나열
int n, p;
int nums[15];
vector<int> myV;
bool visit[15] = { false, };
int result = 0;

void dfs(int cnt)
{
    if (cnt == p)
    {
        result++;
        for (int i = 0; i < p; i++)
            cout << myV[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visit[i] == true)
            continue;

        visit[i] = true;
        myV.push_back(nums[i]);
        dfs(cnt + 1);
        visit[i] = false;
        myV.pop_back();
    }
}


int main(void)
{    
    cin >> n >> p;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    dfs(0);
    cout << result;

    return 0;
}
