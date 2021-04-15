#include <iostream>
#include <cmath>
using namespace std;

bool checkCurTurn(int ttt[3][3], int curTurn)
{
    int opp = 3 - curTurn; //상대방

    for (int i = 0; i < 3; i++) //가로 3줄 빙고 확인
    {
        if (ttt[i][0] == opp && ((ttt[i][0] == ttt[i][1]) &&(ttt[i][1] == ttt[i][2])))
        {
            return false;  //curTurn 패배
        }
    }

    for (int j = 0; j < 3; j++) //세로 3줄 빙고 확인
    {
        if (ttt[0][j] == opp && ((ttt[0][j] == ttt[1][j]) &&(ttt[1][j] == ttt[2][j])))
        {
            return false;
        }
    }

    if (ttt[0][0] == opp && ((ttt[0][0] == ttt[1][1]) && (ttt[1][1] == ttt[2][2]))) //오위-왼아래 대각선 빙고 확인
    {
        return false;
    }

    if (ttt[0][2] == opp && ((ttt[0][2] == ttt[1][1]) && (ttt[1][1] == ttt[2][0]))) //오아래-왼위 대각선 빙고 확인
    {
        return false;
    }

    return true; //빙고 없음
}

int solution(int ttt[3][3], int curTurn)
{
    if (checkCurTurn(ttt, curTurn) == false) //curTurn가 수를 둔 상태에서 curTurn의 승패 확인
    {
        return -1; //curTurn 패배
    }
    
    int check = 2; //-1(op 패배) 0(동점) 1(opp 승리) 2(의미 없는 수)
    for (int i = 0; i < 3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (ttt[i][j] == 0) //curTurn가 수를 둘수 있는 위치
            {
                ttt[i][j] = curTurn;
                check = min(check, solution(ttt, 3-curTurn)); //solution(ttt, 3-curTurn)이 -1을 반환 한다는 뜻은 상대방이 패했다는 것
                ttt[i][j] = 0; //백트래킹
            }
        }
    }

    if (check == 2 || check == 0)
    {
        return 0;
    }
    else if (check == -1)
    {
        return 1;
    }
    else if (check == 1)
    {
        return -1;
    }

}

int main()
{
    int ttt[3][3];
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> ttt[i][j];
            if (ttt[i][j] != 0)
            {
                cnt++;
            }
        }
    }

    int result;
    if (cnt % 2 == 0) //1 차례(1이 이기면 W)
    {
        result = solution(ttt, 1);
    }
    else //2 차례(2가 이기면 W)
    {
        result = solution(ttt, 2);
    }

    if (result == 0)
    {
        cout << "D";
    }
    else if (result == 1)
    {
        cout << "W";
    }
    else if (result == -1)
    {
        cout << "L";
    }
}
