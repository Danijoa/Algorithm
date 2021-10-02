#include <iostream>
#include <vector>
using namespace std;

int Init(vector<int> & segTree, int node, int start, int end)
{
	if (start == end)
		return segTree[node] = 1;	// 개수 count 임으로 1
	int mid = (start + end) / 2;
	return segTree[node] = Init(segTree, node * 2, start, mid) +
		Init(segTree, node * 2 + 1, mid + 1, end);
}

int query(vector<int>& segTree, int node, int start, int end, int cout_value)
{
	if (start == end)
		return start;
	int mid = (start + end) / 2;
	
	int cout_value_left= segTree[node * 2];

	// 작으면 왼쪽 노드로
	if (cout_value_left > cout_value)
		return query(segTree, node * 2, start, mid, cout_value);

	// 같거나 크면 왼쪽 노드로
	return query(segTree, node * 2 + 1, mid + 1, end, cout_value - cout_value_left);
}

void update(vector<int> & segTree, int node, int start, int end, int pos, int diff)
{
	if (pos < start || pos > end)
		return;

	segTree[node] += diff;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update(segTree, node * 2, start, mid, pos, diff);
		update(segTree, node * 2 + 1, mid + 1, end, pos, diff);
	}
}

int main()
{
	// 1부터 n까지의 수
	int n;
	cin >> n;

	// 1 n개를 최하위 노드로 두고
	// 두 노드의 합을 루트로 만들어 올라가는 이진트리
	vector<int> segTree(n * 4); // 크기는 대략 정해두자
	Init(segTree, 1, 1, n);

	// 1부터 n까지의 수들이 한번씩 쓰인 수열
	int answer[100001];

	for (int i = 1; i <= n; i++)
	{
		// 수열에서 숫자 i앞에 i보다 작은 숫자 개수
		int cout_value;
		cin >> cout_value;

		// 숫자 i 위치 찾기 ...
		int pos = query(segTree, 1, 1, n, cout_value);
		answer[pos] = i;

		// 다음 탐색을 위해 segTree 갱신 ...
		update(segTree, 1, 1, n, pos, -1);
	}

	for(int i=1; i<=n; i++)
		cout << answer[i] << "\n";

	/*
	 [input]
	 8
	 5 0 1 2 1 3 0 0
	 [output]
	 2 7 3 5 4 1 8 6

	 <segTree : cout value>
	 Init            	--- node
	        8			--- 1
	    4       4		--- 2 3
 	  2   2   2   2     --- 4 5 6 7
	 1 1 1 1 1 1 1 1    --- 8 9 10 11 12 13 14 15

	 query [ i = 1 ]
	 -> node = 1
	    start = 1 / end = 8 / mid = 4
	    count_value = 5
	    count_value_left = node 2 value = 4
		count_value_left <= count_value (right tree)

	 -> node = 1 * 2 + 1 = 3
	    start = 4 + 1 = 5 / end = 8 / mid = 6
		count_value = 5 - 4 = 1 (right tree 선택했기 때문에 ...)
		count_value_left = node 6 value = 2
		count_value_left > count_value (left tree)

	 -> node = 3 * 2 = 6
		start = 5 / end = 6 / mid = 5
		count_value = 1
		count_value_left = node 12 value = 1
		count_value_left <= count_value (right tree)

	 -> node = 6 * 2 + 1 = 12
		start = 6 / end = 6 / mid = 6

     => pos = 6 

	 update
	 -> node = 1
		start = 1 / end = 8 / pos = 6
		diff = -1
		sefTree[1] += -1
     segTree           	--- node
			7			--- 1
		4       4		--- 2 3
	  2   2   2   2     --- 4 5 6 7
	 1 1 1 1 1 1 1 1    --- 8 9 10 11 12 13 14 15
		mid = 4

	 -> node = 1 * 2 = 2 
		start = 1 / end = 4 / pos = 6
		pos > end
	   
	 -> node = 1 * 2 + 1 = 3
		start = 5 / end = 8 / pos = 6
		diff = -1
		sefTree[3] += -1
	 segTree           	--- node
			7			--- 1
		4       3		--- 2 3
	  2   2   2   2     --- 4 5 6 7
	 1 1 1 1 1 1 1 1    --- 8 9 10 11 12 13 14 15
		mid = 6

	 -> node = 3 * 2 = 6
		start = 5 / end = 6 / pos = 6
		diff = -1
		sefTree[6] += -1
	 segTree           	--- node
			7			--- 1
		4       3		--- 2 3
	  2   2   1   2     --- 4 5 6 7
	 1 1 1 1 1 1 1 1    --- 8 9 10 11 12 13 14 15
		mid = 5

	 -> node = 3 * 2 + 1 = 7
		start = 7 / end = 8 / pos = 6
		pos < start

	 -> node = 6 * 2 = 12
		start = 5 / end = 5 / pos = 6
		pos > end

	 -> node = 6 * 2 + 1 = 13
		start = 6 / end = 6 / pos = 6
		start = end

	 => segTree       	--- node
			7			--- 1
		4       3		--- 2 3
	  2   2   1   2     --- 4 5 6 7
	 1 1 1 1 1 1 1 1    --- 8 9 10 11 12 13 14 15
	*/

}
