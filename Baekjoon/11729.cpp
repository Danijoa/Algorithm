#include <iostream>
#include <vector>
using namespace std;

int ring;
int move;
vector<pair<int, int>> answer;

// [1 2 3 4 5]  [      ]  [      ] 이렇게 세 기둥이 있다고 생각
// [(1 2 3 4)+(5)]  [      ]  [      ] 첫 기둥에 있는 링을 두 묶으로 생각하면
// [5]  [(1 2 3 4)]  [      ]
// [      ]  [(1 2 3 4)]  [5]
// [(1 2 3 4)]  [      ]  [5]
// [(1 2 3)+(4)] [      ]  [5] ... 이렇게 반복

void Hanoi(int ring, int from, int by, int to)
{
	if (ring == 1)
		answer.push_back(make_pair(from, to));
	else
	{
		//첫번째칸 위쪽 ring -1 개를 중간으로 이동 시킨다
		Hanoi(ring -1, from, to, by);
		//그 결과 가장 첫번째 칸의 가장 아래, 즉 가장 넓은 원판을 세번째로 이동시킨다
		answer.push_back(make_pair(from, to));
		//두번째 칸에 존재하는 ring-1개를 첫번째로 이동 시킨다
		Hanoi(ring - 1, by, from, to);
	}

}

int main()
{
	cin >> ring;

	Hanoi(ring, 1, 2, 3);

	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i].first << " " << answer[i].second << "\n";
	}
}
