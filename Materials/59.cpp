#include <iostream>

using namespace std;

int num;
bool* visited;
string ans;

void DFS(int cur)
{
	if (cur > num)
	{
		ans = "";
		for (int i = 1; i <= num; i++)
		{
			if (visited[i] == true)
			{
				ans += (i + '0');
				ans += " ";
			}
		}
		
		if (ans.size() > 0)
			cout << ans << "\n";
	}
	else
	{
		visited[cur] = true;
		DFS(cur + 1);
		visited[cur] = false;
		DFS(cur + 1);
	}
}

int main() 
{
	cin >> num;

	visited = new bool[num + 1];
	memset(visited, false, sizeof(bool));

	DFS(1);
	
	return 0;
}
