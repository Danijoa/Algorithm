#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) 
{
    int cLen = citations.size();
    // 오름 차순 정렬
    sort(citations.begin(), citations.end());   

    int answer = 0;

    int h_index;
    // 하나씩 확인하면서
    for (int i = 0; i < cLen; i++)
    {
        h_index = cLen - i; // h값 : 1 ~ 논문 개수
        // h번 이용된 논문이 h번 이상 
        if (h_index <= citations[i])   
        {
            answer = h_index;
            break;
        }
    }

    return answer;
}
