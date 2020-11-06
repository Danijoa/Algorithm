#include <iostream>
using namespace std;

int vill;
int vil_l;
int busNum;
int** bus;

void floyd()
{
	//2->1->3,4,5
	//3->1->2,4,5
	//4->1->2,3,5
	//5->1->2,3,4
	//-----------
	//1->2->3,4,5
	//3->2->1,4,5
	//...
	for (int via = 1; via <= vill; via++)
	{
		//출발지점과 통과지점 사이 아직 길이 없는 경우
		for (int from = 1; from <= vill; from++)
		{
			if (bus[from][via] == 0)
				continue;

			for (int to = 1; to <= vill; to++)
			{
				//출발지와 도착지가 같은 경우 or 통과지점과 도착지점 사이 아직 길이 없는 경우
				if (from == to || bus[via][to] == 0)
					continue;

				//출발지점에서 도착지점까지 직행은 없지만 통과해서 가는 길이 있는 경우
				//or 출발지점에서 도착지점까지 직행 보다 통과해서 가는 길이 더 빠른 경우
				if (bus[from][to] == 0 ||
					bus[from][to] > bus[from][via] + bus[via][to])
					bus[from][to] = bus[from][via] + bus[via][to];
			}
		}
	}
}

int main()
{
	//마을 개수 입력
	cin >> vill;

	//버스 노선 개수 입력
	cin >> busNum;

	//버느 노선 생성
	vil_l = vill + 1;
	bus = new int* [vil_l];
	for (int x = 0; x < vil_l; x++)
	{
		bus[x] = new int[vil_l];
	}

	//버스 노선 초기화
	for (int x= 0; x < vil_l; x++)
	{
		for (int y = 0; y <vil_l; y++)
		{
			bus[x][y] = 0;
		}
	}

	//버스 노선 값 입력
	for (int i = 0; i < busNum; i++)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (bus[a][b] != 0)	//최단경로 저장
		{
			if(bus[a][b] > c)
				bus[a][b] = c;
		}
		else
			bus[a][b] = c;
	}

	//플로이드
	floyd();

	//결과
	for (int x= 1; x < vil_l; x++)
	{
		for (int y = 1; y < vil_l; y++)
		{
			cout << bus[x][y] << " ";
		}
		cout << "\n";
	}
}
