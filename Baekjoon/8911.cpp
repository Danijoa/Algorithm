#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> myPair;
myPair dirArray[4] = { make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0) };	//(북 동 남 서)
struct myData 
{
	myPair coor;
	int dir;
};

void solve(string str, myData turtle)
{
	int mX = 0, mY = 0, nX = 0, nY = 0;
	for (int i = 0; i < str.length(); i++)
	{
		int curDir = turtle.dir;	//현재 바라보는 방향

		switch (str[i]){
		case'F':	//앞으로
			turtle.coor.first += dirArray[curDir].first;
			turtle.coor.second += dirArray[curDir].second;
			break;
		case'B':	//뒤로
			turtle.coor.first -= dirArray[curDir].first;
			turtle.coor.second -= dirArray[curDir].second;
			break;
		case'L':	//바라보는 방향 왼쪽90
			curDir--;
			if (curDir == -1)
			{
				curDir = 3;
			}
			turtle.dir = curDir;
			break;
		case'R':	//바라보는 방향 오른90
			turtle.dir = (curDir + 1) % 4;
			break;
		default:
			break;
		}

		mX = max(mX, turtle.coor.first);
		mY = max(mY, turtle.coor.second);
		nX = min(nX, turtle.coor.first);
		nY = min(nY, turtle.coor.second);
	}

	cout << (mX - nX) * (mY - nY) << endl;
	//cout << "cur coordinate: " << turtle.coor.first << ", " << turtle.coor.second << endl;
}

int main()
{
	int num;
	cin >> num;
	
	string str;
	while (num--)
	{
		myData turtle;
		turtle.coor = make_pair(0, 0);
		turtle.dir = 0;

		cin >> str;
		solve(str, turtle);
	}

	return 0;
}
