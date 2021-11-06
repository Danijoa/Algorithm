#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;

void doRe(int num)
{
	if (num / 2 < 1)
	{
		ans.push_back(num);
		return;
	}
	ans.push_back(num % 2);
	doRe(num / 2);
}

int main() 
{
	int num;
	cin >> num;
	doRe(num);

	for (vector<int>::reverse_iterator reit = ans.rbegin(); reit != ans.rend(); reit++)
		cout << *reit;

	return 0;
}
