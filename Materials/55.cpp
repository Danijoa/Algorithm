#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int num;
	cin >> num;

	stack<int> myS;
	vector<char> myV;
	int order = 1;

	for (int i = 0; i < num; i++)
	{
		// 일단 넣기
		int temp;
		cin >> temp;
		myS.push(temp);
		myV.push_back('P');

		while (!myS.empty())
		{
			// stack의 top값이 order값과 같으면 pop
			if (myS.top() == order)
			{
				order += 1;
				//cout << myS.top() << " ";
				myS.pop();
				myV.push_back('O');
			}
			else
				break;
		}
	}

	if (!myS.empty())
		cout << "impossible";
	else
	{
		for (int i = 0; i < myV.size(); i++)
			cout << myV[i];
	}

	return 0;
}

/*
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int num;
	cin >> num;

	stack<int> myS;
	vector<char> myV;
	
	// 첫번째 번호
	int temp;
	cin >> temp;
	myS.push(temp);
	myV.push_back('P');
	
	bool impossible = false;
	int index = 1;
	for (int i = 2; i <= num; i++)
	{
		cin >> temp;

		if (myS.top() >= temp)
		{
			myS.push(temp);
			myV.push_back('P');
		}
		else
		{
			while (myS.top() < temp)
			{
				if (myS.top() != index++)
				{
					impossible = true;
					break;
				}
				myS.pop();
				myV.push_back('O');

				if (myS.empty())
					break;
			}
			myS.push(temp);
			myV.push_back('P');
		}
	}

	// 남아있는 번호
	while (!myS.empty())
	{
		if (myS.top() != index++)
		{
			impossible = true;
			break;
		}
		myS.pop();
		myV.push_back('O');
	}

	if (impossible == true)
		cout << "impossible";
	else
	{
		for (int i = 0; i < myV.size(); i++)
			cout << myV[i];
	}

	return 0;
}
*/
