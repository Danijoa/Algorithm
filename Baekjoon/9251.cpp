#include<iostream>
#include<string>
#define MAX 1001
using namespace std;
 
string A, B;
int DP[MAX][MAX];
 
int Bigger(int A, int B) 
{ 
  if (A > B) 
    return A; 
  return B; 
}

void Solution()
{
    int A_Size = A.length();
    int B_Size = B.length();
 
    // DP[i][j] = s1(0~i)과 s2(0~j)까지의 LCS 저장 
    for (int i = 1; i <= A_Size; i++)
    {
        for (int j = 1; j <= B_Size; j++)
        {
            // 동일한 경우
            if (A[i - 1] == B[j - 1])
            {
                // DP[i-1][j-1](왼쪽 대각 위 값)
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            // 다른 경우
            else
            {
                // DP[i][j-1](왼쪽값) DP[i-1][j](위쪽값) 중에서 큰 값
                DP[i][j] = Bigger(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }
 
    cout << DP[A_Size][B_Size] << endl;
}
 
int main(void)
{
    cin >> A >> B;
    Solution();
 
    return 0;
}
