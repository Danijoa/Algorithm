#include <iostream>
#include <vector>
using namespace std;
#define MAX 200000001

int calculate(int dist, int w)
{
	int num = dist / (2 * w + 1);
	if (dist % (2 * w + 1) == 0)
		return num;
	else
		return (num + 1);
}

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int leg = stations.size();	//기지국 개수
	int dist=0;

	if (stations[0] - w > 1)
	{
		dist = (stations[0] - w) - 1;
		answer += calculate(dist, w);
	}

	if (leg > 1)
	{
		for (int j = 0; j < leg - 1; j++)
		{
			if (stations[j + 1] - w > stations[j] + w)
			{
				dist = (stations[j + 1] - w) - (stations[j] + w) - 1;
				answer += calculate(dist, w);
			}
		}
	}

	if (stations[leg-1] + w < n)
	{
		dist = (n) - (stations[leg - 1] + w);
		answer += calculate(dist, w);
	}
    
    return answer;
}
