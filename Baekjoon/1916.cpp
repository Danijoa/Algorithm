#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000000

using namespace std;

int city;
int bus;
vector<vector<pair<int, int>>> myV;
int depart;
int arrive;
int* dist;

void dijkstra(int depart)
{
	dist[depart] = 0;

	priority_queue<pair<int, int>> myQ; //cost, city index
	myQ.push(make_pair(-1 * dist[depart], depart));

	while (myQ.empty() != true)
	{
		int currentIndex = myQ.top().second;
		int currentCost = -1 * myQ.top().first;
		myQ.pop();
		if (currentCost > dist[currentIndex])
		{
			continue;
		}

		for (int i = 0; i < myV[currentIndex].size(); i++)
		{
			int nextIndex = myV[currentIndex][i].first;
			int nextcost = myV[currentIndex][i].second;;
			if (dist[nextIndex] > dist[currentIndex] + nextcost)
			{
				dist[nextIndex] = dist[currentIndex] + nextcost;
				myQ.push(make_pair(-1 * dist[nextIndex], nextIndex));
			}
		}
	}
}


int main()
{
	cin >> city;
	cin >> bus;
	
	myV.resize(city + 1);

	int start, end, cost;
	for (int i = 0; i < bus; i++)
	{
		cin >> start >> end >> cost;
		myV[start].push_back(make_pair(end, cost));
	}

	dist = new int[city + 1];
	for (int i = 0; i < city + 1; i++)
	{
		dist[i] = MAX;
	}

	cin >> depart >> arrive;

	dijkstra(depart);

	cout << dist[arrive];
	
	return 0;
}
