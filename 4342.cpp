#include <iostream>
#include <queue>
using namespace std;

/*
유클리드 호제법(gcd, 최대공약수)
A = B*q + R
gcd(A, B) = gcd(B, R)
(R=0, gcd(A, B) = B)
*/

string solution(int big, int small)
{
	int cnt = 0;
	while (1)
	{
		cnt++;
		int r = big % small;

		if (r == 0)
		{
			break;
		}
		else
		{
			int q = big / small;
			if (q != 1)
			{
				return (cnt % 2 == 0 ? "B wins" : "A wins");
			}
			
			big = small;
			small = r;
		}
	}
	return (cnt % 2 == 0 ? "B wins" : "A wins");
}

typedef pair<int, int> myPair;

int main()
{
    queue<myPair> myNode;

    while (1)
    {
        int i = 0, j = 0;
        cin >> i >> j;
        myNode.push({ i, j });

        if (i == 0 && j == 0)
            break;
    }

    while (1)
    {
        int first = myNode.front().first;
        int second = myNode.front().second;
        myNode.pop();

        if (first == 0 && second == 0)
            break;
        if (first < second)
        {
            int temp = first;
            first = second;
            second = temp;
        }
        cout << solution(first, second);
        cout << "\n";
    }
}
