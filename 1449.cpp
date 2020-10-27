#include <iostream>
#include <algorithm>


int main()
{
	int list[1000];
	int N, L;
    std::cin >> N >> L; 
	for (int i = 0; i < N; i++)
		std::cin >> list[i];
	//sort(배열의 포인터, 배열의 포인터+크기)
	std::sort(list, list + N);

	int tape = 0;
	int max_covered = 0;
	for (int i = 0; i < N; i++)
	{
		if (list[i] <= max_covered)
			continue;
		tape++;
		max_covered = list[i] + L - 1;
	}

	std::cout << tape;
}
