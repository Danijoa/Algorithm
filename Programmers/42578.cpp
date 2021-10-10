#include <map>
#include <vector>
using namespace std;

map<string, int> mClothes;
map<string, int> ::iterator iter;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
   
    for (int i = 0; i < clothes.size(); i++)
    {
        if(mClothes.find(clothes[i][1]) == mClothes.end())
            mClothes[clothes[i][1]] = 1;
        else
            mClothes[clothes[i][1]] += 1;
    }

    for (iter = mClothes.begin(); iter != mClothes.end(); iter++)
    {
        // 옷 개수 + 선택 안하는 경우
        answer *= (iter->second + 1);
    }

    // 다 선택 안하는 경우 제외
    return answer - 1;
}
