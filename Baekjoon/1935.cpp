#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string sik;
	cin >> sik;

	int alpha[26];
	for (int i = 0; i < N; i++)
	{
		cin >> alpha[i];
	}

	stack<double> cal;
	for(int i = 0; i < sik.size(); i++)
	{
		if (sik[i]=='+' || sik[i] == '-' || sik[i] == '*' || sik[i] == '/')
		{
			double second = cal.top();
			cal.pop();
			double first = cal.top();
			cal.pop();

			double temp;
			if (sik[i] == '+')
			{
				temp = first + second;
				cal.push(temp);
			}
			if (sik[i] == '-')
			{
				temp = first - second;
				cal.push(temp);
			}
			if (sik[i] == '*')
			{
			 temp = first * second;
				cal.push(temp);
			}
			if (sik[i] == '/')
			{
				temp = first / second;
				cal.push(temp);
			}
		}
		else
			cal.push(alpha[sik[i] - 'A']);
	}

	printf("%.2f", cal.top());
}
