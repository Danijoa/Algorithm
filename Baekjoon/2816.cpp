#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    int k1 = -1, k2 = -1;
    for (int i = 1; i <= num; i++)
    {
        string board;
        cin >> board;

        if (board=="KBS1")	//if (board.compare("KBS1"))
            k1 = i;

        if (board=="KBS2")
            k2 = i;
    }

    for (int i = 1; i < k1; i++)
        cout << "1";
    for (int i = 1; i < k1; i++) //k1 > k2 인 경우 여기서 k2의 번호가 하나 증가한다
        cout << "4";

    if (k1 > k2)
        k2++;

    for (int i = 1; i < k2; i++)
        cout << "1";
    for (int i = 1; i < k2 - 1; i++)
        cout << "4";
}
