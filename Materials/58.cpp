#include <iostream>

using namespace std;

void rootFirst(int n)
{
	if (n > 7)
		return;

	cout << n << " ";
	rootFirst(n * 2);
	rootFirst(n * 2 + 1);
}

void leftFirst(int n)
{
	if (n > 7)
		return;

	leftFirst(n * 2);
	cout << n << " ";
	leftFirst(n * 2 + 1);
}

void rootLast(int n)
{
	if (n > 7)
		return;

	rootLast(n * 2);
	rootLast(n * 2 + 1);
	cout << n << " ";
}

int main() 
{
	cout << "전위순회 : ";
	rootFirst(1);
	cout << endl;

	cout << "중위순회 : ";
	leftFirst(1);
	cout << endl;

	cout << "후위순회 : ";
	rootLast(1);
	cout << endl;

	/*
	전위순회 출력 : 1 2 4 5 3 6 7
	중위순회 출력 : 4 2 5 1 6 3 7
	후위순회 출력 : 4 5 2 6 7 3 1
	*/

	return 0;
}
