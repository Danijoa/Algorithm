#include <iostream>

using namespace std;

int main() 
{
	int s, w;
	cin >> s >> w;

	int** g = new int* [s];
	for (int i = 0; i < s; i++)
		g[i] = new int[s];
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			g[i][j] = 0;

	for (int i = 0; i < w; i++)
	{
		int st, ed, wt;
		cin >> st >> ed >> wt;
		g[st - 1][ed - 1] = wt;
	}

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
			cout << g[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
