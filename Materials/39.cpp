#include <iostream>

using namespace std;

int main()
{
	int n1;
	cin >> n1;

	int a1[100];
	for (int i = 0; i < n1; i++)
		cin >> a1[i];

	int n2;
	cin >> n2;

	int a2[100];
	for (int i = 0; i < n2; i++)
		cin >> a2[i];

	int idx1 = 0, idx2 = 0, idxT = 0;
	int temp[200];

	while (true)
	{
		if (idx1 == n1 || idx2 == n2)
			break;

		if (a1[idx1] <= a2[idx2])
		{
			temp[idxT] = a1[idx1];
			idx1++;
		}
		else
		{
			temp[idxT] = a2[idx2];
			idx2++;
		}
		idxT++;
	}

	while (idx1 < n1)
	{
		temp[idxT] = a1[idx1];
		idx1++;
		idxT++;
	}

	while (idx2 < n2)
	{
		temp[idxT] = a2[idx2];
		idx2++;
		idxT++;
	}

	for (int i = 0; i < n1 + n2; i++)
		cout << temp[i] << " ";

	return 0;
}
