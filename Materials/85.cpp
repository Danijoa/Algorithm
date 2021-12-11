#include <iostream>
#include <vector>

using namespace std;

int numLength;
vector<int> nums;
int hmgd[4] = { 0, };

int minN = 987654321;
int maxN = 0;

int cal(int cur, int next, int index)
{
    switch (index)
    {
    case 0:
        cur += next;
        break;
    case 1:
        cur -= next;
        break;
    case 2:
        cur *= next;
        break;
    case 3:
        cur /= next;
        break;
    default:
        break;
    }

    return  cur;
}

void dfs(int cur, int idx)
{
    if (idx == numLength - 1)
    {
        if (minN > cur)
            minN = cur;
        if (maxN < cur)
            maxN = cur;
    }

    for (int i = 0; i < 4; i++)
    {
        if (hmgd[i] > 0)
        {
            hmgd[i] -= 1;
            dfs(cal(cur, nums[idx + 1], i), idx + 1);
            hmgd[i] += 1;
        }
    }
}

int main(void)
{    
    cin >> numLength;

    for (int i = 0; i < numLength; i++)
    {
        int n;
        cin >> n;
        nums.push_back(n);
    }

    for (int i = 0; i < 4; i++)
        cin >> hmgd[i];

    dfs(nums[0], 0);

    cout << maxN << "\n" << minN;

    return 0;
}
