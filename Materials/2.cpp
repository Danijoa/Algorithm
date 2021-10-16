#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	string ans = "";
	int total = 0;
	string temp;
	for (int i = a; i <= b; i++)
	{
		total += i;
		temp = to_string(i);
		if(i != b)
			ans += (temp + " + ");
		else
			ans += (temp + " = ");
	}
	temp = to_string(total);
	ans += temp;

	cout << ans;
}
