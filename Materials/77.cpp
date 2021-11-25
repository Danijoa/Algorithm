#include <iostream>

using namespace std;

int parent[1001];

int find(int f)
{
    if (f == parent[f])
        return f;

    return parent[f] = find(parent[f]);
}

void Union(int s1, int s2)
{
    s1 = find(s1);
    s2 = find(s2);

    if (s1 != s2)
        parent[s1] = s2;
}

int main(void)
{
    int student, relation;
    cin >> student >> relation;

    for (int i = 0; i <= 1000; i++)
        parent[i] = i;

    int s1, s2;
    for (int i = 0; i < relation; i++)
    {
        cin >> s1 >> s2;
        Union(s1, s2);
    }

    int f1, f2;
    cin >> f1 >> f2;

    if (find(f1) == find(f2))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
