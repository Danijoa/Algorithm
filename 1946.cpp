#include <iostream>
using namespace std;

int myAnswer[20];	//myAnswer 생성
int myArray[100000];	//myArray 생성

int solution(int people)
{
	int answer = 1;

	int a, b;
	for (int i = 0; i < people; i++)	//성적 입력
	{
		cin >> a >> b;
		myArray[a - 1] = b;
	}

	int min = myArray[0];
	for (int i = 1; i < people; i++)	//비교
	{
		if (min > myArray[i])
		{
			answer++;
			min = myArray[i];
		}
	}

	return answer;
}

int main()
{
	int testCase;	//테스트 케이스
	cin >> testCase;

	int check = 0;
	while(true)
	{
		int people;	//지원자 수
		cin >> people;

		myAnswer[check] = solution(people);

		check++;
		if (check == testCase)
			break;
	}

	for (int i = 0; i < testCase; i++)
	{
		cout << myAnswer[i];
		if (i != testCase - 1)
			cout << '\n';
	}
}
