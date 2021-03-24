#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int leakNum, tapeLength;
	cin >> leakNum >> tapeLength;
	
	int myLeak[1001];
	for (int i = 0; i < leakNum; i++)
	{
		cin >> myLeak[i];
	}
	sort(myLeak, myLeak + leakNum);

	int tape = 0;
	bool taped[1001];
	for (int i = 0; i < leakNum; i++)
	{
		if (taped[myLeak[i]] == false)
		{
			for (int j = myLeak[i]; j < myLeak[i] + tapeLength; j++)
				taped[j] = true;
			tape++;
		}
	}
	cout << tape;


	return 0;
}
