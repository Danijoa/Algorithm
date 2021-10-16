#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int hap = 0;
	vector<int> myV;
	for (int i = 1; i <= n / 2; i++)	//sqrt(n)
	{
		if (n % i == 0)
		{
			hap += i;
			myV.push_back(i);
		}
	}

	string ans = "";
	for (int i = 0; i < myV.size(); i++)
	{
		if(i != myV.size() - 1)
			ans += to_string(myV[i]) + " + ";
		else
			ans += to_string(myV[i]) + " = " + to_string(hap);
	}

	cout << ans;
}
