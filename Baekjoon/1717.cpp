#include <iostream>
using namespace std;

int parent[1000001];

int Find(int c)
{
	if (c == parent[c])
		return c;
	 
  // 경로에 있는 모든 노드의 부모 노드가 루트가 됨 
	return parent[c] = Find(parent[c]);
}

void Sol(int a, int b)
{
	a = Find(a);
	b = Find(b);

	// a랑 b랑 같은 그룹에 존재한다
	if (a == b)
	{
		cout << "YES\n";
		return;
	}

	// a랑 b랑 다른 그룹에 존재한다
	cout << "NO\n";
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	// a랑 b랑 같은 그룹에 존재한다
	if(a == b)
		return;

	// a랑 b랑 다른 그룹에 존재한다
	// a와 b 그룹 합치기
	parent[a] = b;
}

int main()
{ 
    cin.tie(0);
    cout.tie(0);
	cin.sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
    
	int num, cal;
	cin >> num >> cal;

	// 초기 각 노드는 자기 자신을 루트 노드로 가지고 있다
	for (int i = 0; i <= num; i++)
	{
		parent[i] = i;
	}

	int type, a, b;
	for (int i = 0; i < cal; i++)
	{
		cin >> type >> a >> b;
		
		if (type == 1)
			Sol(a, b);
		else
			Union(a, b);
	}

	return 0;	
}
