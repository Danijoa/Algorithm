#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 숫자 배열 중 어떠한 위치의 (string) a와 b를 선택해도 a+b > b+a를 만족하도록 만든다
bool cmp(string &a, string &b)
{
    if(a + b > b + a)
        return true;
    else                
        return false;   // a + b = b + a 인 경우를 true로 놓으면 무한으로 정렬하려고 한다
}

string solution(vector<int> numbers) 
{
    string answer = "";
    
    // 숫자 원소 합 비교를 쉽게 하기 위해 string으로 저장
    vector<string> temp;
    for(int i = 0; i < numbers.size(); i++)
    {
        temp.push_back(to_string(numbers[i]));
    }
    
    // 비교 정렬 수행
    sort(temp.begin(), temp.end(), cmp);
    
    // string으로 큰 수 저장
    for(int i = 0; i < temp.size(); i++)
    {
        answer += temp[i];
    }
    
    // 가장 큰수가 0인 경우는 반환 (0으로만 이루어진 숫자배열)
    if(answer[0] == '0')
        return "0";
    
    // 출력
    return answer;
}
