#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = s.length();

    //크기 1 ~ length/2 단위로 자르면서 확인
    for (int unit = 1; unit <= s.length() / 2; unit++)
    {
        int cnt = 1;
        string ss = s.substr(0, unit);  // substr(start index, length)
        string temp = "";

        for (int index = unit; index <= s.length(); index += unit) //  index <s.length() ??
        {
            // 현재 ss와 같은 경우
            if (ss == s.substr(index, unit))
            {
                // 중복 개수 증가
                cnt++;
            }
            // 다른 경우
            else
            {
                // 붙이자
                if (cnt == 1)
                {
                    temp += ss;
                }
                else
                {
                    temp += (to_string(cnt) + ss);
                }

                // ss 갱신
                ss = s.substr(index, unit);

                // 개수 초기화
                cnt = 1;
            }
        }

        // 남은 문자열 붙이기
        if ((s.length() % unit) != 0)
        {
            int a = (s.length() / unit) * unit;
            temp += s.substr(a);
        }

        // 최소 길이 저장
        if (answer > temp.length())
            answer = temp.length();
    }
    
    return answer;
}
