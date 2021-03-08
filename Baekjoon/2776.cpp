#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int loop;
	cin >> loop;

	for (int i = 0; i < loop; i++)
	{
		//수첩1 입력
		int note = 0;
		cin >> note;
		vector<int> noteNum;

		for (int j = 0; j < note; j++)
		{
			int tempNote;
			cin >> tempNote;
			noteNum.push_back(tempNote);
		}

		//오름차순 정렬
		sort(noteNum.begin(), noteNum.end());

		//수첩2 입력
		int see = 0;
		cin >> see;
		vector<int> storeNum;
		for (int k = 0; k < see; k++)
		{
			int tempSee;
			cin >> tempSee;
			storeNum.push_back(tempSee);
		}

		//이진 탐색
		for (int a = 0; a < see; a++)
		{
			int check = 0;

			int first = 0;
			int last = noteNum.size() - 1;

			while (first <= last)
			{
				int mid = (first + last) / 2;

				//중간 값과 같은 경우
				if (storeNum[a] == noteNum[mid])
				{
					check = 1;
					break;
				}
				else
				{
					//중간 값 보다 작은 경우
					if (storeNum[a] < noteNum[mid])
					{
						last = mid - 1;
					}
					//중간 값 보다 큰 경우
					else
					{
						first = mid + 1;
					}
				}
			}
			cout << check << "\n";
		}
	}

	return 0;
}
