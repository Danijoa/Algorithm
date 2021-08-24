#include <string>
#include <vector>
#include <algorithm>

using namespace std;

float CalDis(pair<int, int> a, pair<int, int> b)
{
    int temp 
        = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    
    cout << sqrt((float)temp) << endl;
    return sqrt((float)temp);
}

pair<int, int> CalPos(int num)
{
    pair<int, int> temp;

    if (num == 0)
    {
        temp.first = 3;
        temp.second = 1;
    }
    else
    {
        temp.first = (num - 1) / 3;
        temp.second = num - (num - 1) / 3 - 1;
    }

    return temp;
}

struct Coor
{
    pair<int, int> coor;
};

string solution(vector<int> numbers, string hand) 
{
    string answer = "";

    Coor curLeftPos, curRightPos, curNumPos;
    float leftDis, rightDis;

    for (int i = 0; i < numbers.size(); i++)
    {
        int curNum = numbers[i];

        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            curLeftPos.coor = CalPos(curNum);
            answer += "L";
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            curRightPos.coor = CalPos(curNum);
            answer += "R";
        }
        else
        {
            curNumPos.coor = CalPos(curNum);

            leftDis = CalDis(curNumPos.coor, curLeftPos.coor);
            rightDis = CalDis(curNumPos.coor, curRightPos.coor);

            if (leftDis == rightDis)
            {
                if (hand == "right")
                {
                    curRightPos.coor = curNumPos.coor;
                    answer += "R";
                }
                else
                {
                    curLeftPos.coor = curNumPos.coor;
                    answer += "L";
                }
            }
            else
            {
                if (leftDis > rightDis)
                {
                    curRightPos.coor = curNumPos.coor;
                    answer += "R";
                }
                else
                {
                    curLeftPos.coor = curNumPos.coor;
                    answer += "L";
                }
                //string temp = leftDis > rightDis ? "R" : "L";
                //if(temp == "R")
                //    curRightPos.coor = curNumPos.coor;
                //else
                //    curLeftPos.coor = curNumPos.coor;
                //answer += temp;
            }
        }
    }

    return answer;
}
