#include <iostream>
#include <map>
using namespace std;

int const MAX = 200001;
int parent[MAX];
int group[MAX];
map<string, int> myM;	// (key, value) (사람이름, 인덱스)

int Find(int c)
{
	if (c == parent[c])
		return c;

	return parent[c] = Find(parent[c]);
}

void Union(int a, int b)
{
	// 루트 노드 찾기
	a = Find(a);
	b = Find(b);

	// 이미 같은 그룹 인 경우
	if (a == b)
	{
		cout << group[a] << "\n";	// group[a] = group[b]
		return;
	}

	// 다른 그룹 인 경우
	if (a != b)
	{
		// b그룹을 a그룹으로 합치기
		parent[b] = a;
		group[a] += group[b];
		group[b] = group[a];

		cout << group[a] << "\n";
	}
}

int main()
{ 
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int testCase;
	cin >> testCase;
	 
	for (int i = 0; i < testCase; i++)
	{
		// 관계 개수
		int relation;
		cin >> relation;

		// 초기화
		int index = 1;
		myM.clear();
		for (int k = 0; k < MAX; k++)
		{
			parent[k] = k;	// k 인덱스의 루트 노드
			group[k] = 1;	// k 인덱스의 집합 개수
		}

		for (int j = 0; j < relation; j++)
		{
			string name1, name2;
			cin >> name1 >> name2;

			// 새로운 이름이라면, 인덱스 부여하여 맵에 저장
			if (myM.find(name1) == myM.end())
				myM[name1] = index++;
			if (myM.find(name2) == myM.end())
				myM[name2] = index++;

			int name1Index = myM[name1];
			int name2Index = myM[name2];

			Union(name1Index, name2Index);
		}
	}

	return 0;	
}
