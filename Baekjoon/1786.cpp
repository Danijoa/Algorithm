#include <iostream>
#include <string>
#include <vector>
using namespace std;

void LPS(string s2, int p[])
{
    int s2Len = s2.length();

    int i = 0; // s2 인덱스 i < j
    for (int j = 1; j < s2Len; j++)
    {
        while (i > 0 && s2[i] != s2[j])
        {
            i = p[i - 1];
        }

        if (s2[i] == s2[j])
        {
            p[j] = i + 1;
            i++;
        }
    }
}

void KMP(string s1, string s2, int p[], vector<int>& pos)
{
    int s1Len = s1.length();
    int s2Len = s2.length();

    int j = 0; // s1 인덱스 i , s2 인덱스 j
    for (int i = 0; i < s1Len; i++)
    {
        // (일차하다가~) 불일치 한 경우 
        // i 위치는 고정한 채로
        // j 위치를 앞으로 jump 하면서 
        // 일치하는 문자열 잇는지 확인
        // 일치하는 곳이 없이 j==0이 되면 
        // 패턴 처음부터 다시 비교 시작
        while (j > 0 && s1[i] != s2[j])
        {
            j = p[j - 1];
        }

        // 일치하면 
        if (s1[i] == s2[j])
        {
            if (j == s2Len - 1) // 패턴 끝에 도달한 경우
            {
                pos.push_back(i - j);    // s1속 찾은 s2 한대의 시작 인덱스
                j = p[j];  // s2는 여러개 존재할 수 있기 때문
            }
            else
            {
                j++; // 다음 글자도 일치하는지 확인하자
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    getline(cin, s1);   // 문자열
    getline(cin, s2);   // 패턴

    int s2Len = s2.length();
    int* p = new int[s2Len];
    for (int i = 0; i < s2Len; i++)
        p[i] = 0;

    LPS(s2, p);

    //for (int i = 0; i < s2Len; i++)
    //    cout << p[i] << " ";
    //cout << "\n";

    vector<int> pos;    // 문자열에서 각 패턴 시작 인덱스 저장
    KMP(s1, s2, p, pos);

    cout << pos.size() << "\n";
    for (int i = 0; i < pos.size(); i++)
    {
        cout << pos[i] + 1 << "\n";
        //cout << pos[i] + 1 << " ";
    }
}

/*
 KMP : 문자열에서 원하는 패턴 찾기 (비교하는 구간의 공통 부분을 겹쳐서 찾지 않는다)

 LPS(Longet Prefix which is also Suffix) = 접두사와 접미사가 일치하는 최대의 길이

 패턴 [ a b a b c d a b ]의 lps 
 1. a b              : 0
 2. a b a            : 1 (a / a)
 3. a b a b          : 2 (ab / ab)
 4. a b a b c        : 0
 5. a b a b c d      : 0
 6. a b a b c d a    : 1 (a / a) 
 7. a b a b c d a b  : 2 (ab / ab)

 <1> i와 j 값이 일치하지 않으면
     i = p[i - 1] (i == 0 제외)
     일치여부 다시 확인 (일치하면 <2>, 일치 않하면 p[j] = 0) 
     j++
 <2> i와 j 값이 일치하면 
     p[j] = i + 1 / i++ / j++

 => a b a b c d a b
    i j
    0 0
 => a b a b c d a b
    i   j
    0 0 1
 => a b a b c d a b
      i   j
    0 0 1 2
 => a b a b c d a b
    i       j
    0 0 1 2 0
 => a b a b c d a b
    i         j
    0 0 1 2 0 0
 => a b a b c d a b
    i           j
    0 0 1 2 0 0 1
 => a b a b c d a b
      i           j
    0 0 1 2 0 0 1 2 <= p[i] : 개수

 S1텍스트와 S2패턴을 처음 위치에 두고 비교를 시작한다
 미스가 일어난 S1의 i 위치
 미스가 일어난 S2의 j 위치 앞 p[j-1] = n 일떄
 S1의 i 위치와 S2의 n 위치를 일치 시킨 후
 해당 위치부터 비교 시작

 => S1 [ a b a c a b a a b a b c d a b a b c ]
         - - - -                                : i = 3
    S2 [ a b a b c d a b ]                      : j = 3 / p[j - 1] = n = p[2] = 1
 => S1 [ a b a c a b a a b a b c d a b a b c ]
               -                                : i = 3
        S2 [ a b a b c d a b ]                  : j = 1 / p[0] = 0 
 => S1 [ a b a c a b a a b a b c d a b a b c ]
               -                                : i = 3
          S2 [ a b a b c d a b ]                : j = 0 / i++ S2++
 => S1 [ a b a c a b a a b a b c d a b a b c ]
                 - - - -                         : i = 7
            S2 [ a b a b c d a b ]               : j = 3 / p[2] = 1
 => S1 [ a b a c a b a a b a b c d a b a b c ]
                       -                         : i = 7
                S2 [ a b a b c d a b ]           : j = 1 / p[0] = 0
 => S1 [ a b a c a b a a b a b c d a b a b c ]
                       - - - - - - - -           : i = 14
                  S2 [ a b a b c d a b ] 찾았다!  : j = 8 / p[7] = 2

 O(n)의 시간 복잡도
*/
