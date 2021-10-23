#include <iostream>
#include <list>

using namespace std;

int main()
{
	int size, work;
	cin >> size >> work;

	list<int> cache(0, size);
	list<int>::iterator it;

	int num;
	bool isMiss;
	for (int i = 0; i < work; i++)
	{
		cin >> num;

		if (cache.size() < size)
			cache.push_front(num);
		else
		{
			isMiss = true;
			for (it = cache.begin(); it != cache.end(); it++)
			{
				// hit
				if (*it == num)
				{
					isMiss = false;
					cache.erase(it);
					cache.push_front(num);
					break;
				}
			}

			// miss
			if (isMiss)
			{
				cache.pop_back();
				cache.push_front(num);
			}
		}
	}

	for (int ptr : cache)
	{
		cout << ptr << " ";
	}

	return 0;
}
