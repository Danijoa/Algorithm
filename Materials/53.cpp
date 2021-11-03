#include <iostream>
#include <stack>
#include <string>
using namespace std;

// (char) B = 'A + 1;
// (char) 2 = '0' + 2;

int main()
{
	int num, k;
	cin >> num >> k;

	stack<char> myS;
	char temp;
	while (num / k > 0)
	{
		if (num % k >= 10)
			temp = 'A' + (num % k - 10);
		else
			temp = (num % k) + '0';

		myS.push(temp);
		num /= k;
	}
	myS.push(num + '0');

	while (!myS.empty())
	{
		cout << myS.top();
		myS.pop();
	}

	return 0;
}
