#include <iostream>
#include <vector>
using namespace std;

int num;
bool selected[10] = { false, };
vector<int> myV;

void DoPrint()
{
	for (int i = 0; i < myV.size(); i++)
	{
		cout << myV[i] << " ";
	}
	cout << '\n';

}

void DFS(int cnt)
{
	if (cnt == num)
	{
		DoPrint();
		return;
	}

	for (int i = 1; i <= num; i++)
	{
		if (selected[i] == true)
			continue;
		selected[i] = true;

		myV.push_back(i);
		DFS(cnt + 1);
		myV.pop_back();

		selected[i] = false;
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> num;

	DFS(0);

	return 0;
}
