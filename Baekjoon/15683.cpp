
#include <iostream>
#include <vector>
using namespace std;

// 사각지대 크기
int area = 987654321;

// 방 정보
int x, y;
int map[8][8];
// cctv 관찰되는 지역 정보 
// (0: 사각지대 / 1,2,3,4,5: cctv / 6: 벽 / -1: cctv 작동중인 영역)
int cctv[8][8];

// cctv 상세 정보
struct Data
{
	int mapX, mapY;
	int cctvType;
	int dir;
};
vector<Data> myV;

// 상하좌우
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

// 총 cctv 개수
int cctvTotal;

// cctv 작동 모습 저장(-1)
void Right(int curX, int curY)
{
	for (int i = curY + 1; i < y; i++)
	{
		// 벽 만나면 멈춤
		if (cctv[curX][i] == 6)
			break;
		// 다른 cctv 만나면 지나감
		if (cctv[curX][i] >= 1 && cctv[curX][i] <= 5)
			continue;
		// 작동 영역 표시
		cctv[curX][i] = -1;
	}
}

void Left(int curX, int curY)
{
	for (int i = curY - 1; i >= 0; i--)
	{
		if (cctv[curX][i] == 6)
			break;
		if (cctv[curX][i] >= 1 && cctv[curX][i] <= 5)
			continue;
		cctv[curX][i] = -1;
	}
}

void Down(int curX, int curY)
{
	for (int i = curX + 1; i < x; i++)
	{
		if (cctv[i][curY] == 6)
			break;
		if (cctv[i][curY] >= 1 && cctv[i][curY] <= 5)
			continue;
		cctv[i][curY] = -1;
	}
}

void Up(int curX, int curY)
{
	for (int i = curX - 1; i >= 0; i--)
	{
		if (cctv[i][curY] == 6)
			break;
		if (cctv[i][curY] >= 1 && cctv[i][curY] <= 5)
			continue;
		cctv[i][curY] = -1;
	}
}

// cctv 작동되는 넓이 계산
int CalcctvArea()
{
	// cctv 설치 방향이 다른 테스트 케이스들을 새롭게 확인 하기 위함
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cctv[i][j] = map[i][j];
		}
	}

	// cctv 타입과 방향 확인
	for (int i = 0; i < myV.size(); i++)
	{
		if (myV[i].cctvType == 1)
		{
			// → 
			if (myV[i].dir == 0) Right(myV[i].mapX, myV[i].mapY);
			// ←
			else if (myV[i].dir == 1) Left(myV[i].mapX, myV[i].mapY);
			// ↓
			else if (myV[i].dir == 2) Down(myV[i].mapX, myV[i].mapY);
			// ↑
			else if (myV[i].dir == 3) Up(myV[i].mapX, myV[i].mapY);
		}
		else if (myV[i].cctvType == 2)
		{
			// ←→
			if (myV[i].dir == 0 || myV[i].dir == 1)
			{
				Right(myV[i].mapX, myV[i].mapY);
				Left(myV[i].mapX, myV[i].mapY);
			}
			// ↕
			else if (myV[i].dir == 2 || myV[i].dir == 3)
			{
				Down(myV[i].mapX, myV[i].mapY);
				Up(myV[i].mapX, myV[i].mapY);
			}
		}
		else if (myV[i].cctvType == 3) // ↑ →
		{
			// ↑ → 
			if (myV[i].dir == 0)
			{
				Up(myV[i].mapX, myV[i].mapY);
				Right(myV[i].mapX, myV[i].mapY);
			}
			// → ↓
			else if (myV[i].dir == 1)
			{
				Right(myV[i].mapX, myV[i].mapY);
				Down(myV[i].mapX, myV[i].mapY);
			}
			// ↓ ←
			else if (myV[i].dir == 2)
			{
				Down(myV[i].mapX, myV[i].mapY);
				Left(myV[i].mapX, myV[i].mapY);
			}
			// ← ↑
			else if (myV[i].dir == 3)
			{
				Left(myV[i].mapX, myV[i].mapY);
				Up(myV[i].mapX, myV[i].mapY);
			}
		}
		else if (myV[i].cctvType == 4) 
		{
			// ← ↑ →
			if (myV[i].dir == 0)
			{
				Left(myV[i].mapX, myV[i].mapY);
				Up(myV[i].mapX, myV[i].mapY);
				Right(myV[i].mapX, myV[i].mapY);
			}
			// ↑ → ↓
			else if (myV[i].dir == 1)
			{
				Up(myV[i].mapX, myV[i].mapY);
				Right(myV[i].mapX, myV[i].mapY);
				Down(myV[i].mapX, myV[i].mapY);
			}
			// ← ↓ →
			else if (myV[i].dir == 2)
			{
				Left(myV[i].mapX, myV[i].mapY);
				Down(myV[i].mapX, myV[i].mapY);
				Right(myV[i].mapX, myV[i].mapY);
			}
			// ↓ ← ↑
			else if (myV[i].dir == 3)
			{
				Down(myV[i].mapX, myV[i].mapY);
				Left(myV[i].mapX, myV[i].mapY);
				Up(myV[i].mapX, myV[i].mapY);
			}
		}
		else if (myV[i].cctvType == 5)
		{
			// ← ↕ →
			// if(myV[i].dir == 0,1,2,3)
			Right(myV[i].mapX, myV[i].mapY);
			Left(myV[i].mapX, myV[i].mapY);
			Down(myV[i].mapX, myV[i].mapY);
			Up(myV[i].mapX, myV[i].mapY);
		}
	}

	return 0;
}

// 사각지대 넓이 계산
int CalNonecctvArea()
{
	int sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (cctv[i][j] == 0)
				sum += 1;
		}
	}
	return sum;
}

void SetDirection(int index)
{
	// 다 설치했으면 계산하자
	if (index == cctvTotal)
	{
		CalcctvArea();
		area = min(area, CalNonecctvArea());
		return;
	}

	// 방향 잡고 + 다음 cctv 설치
	myV[index].dir = 0;
	SetDirection(index + 1);
	myV[index].dir = 1;
	SetDirection(index + 1);
	myV[index].dir = 2;
	SetDirection(index + 1);
	myV[index].dir = 3;
	SetDirection(index + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 방 크기
	cin >> x >> y;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			// cctv + 벽 정보
			cin >> map[i][j];

			// cctv 정보 vector에 저장
			if (map[i][j] >= 1 && map[i][j] <= 5)
			{
				Data myData;
				myData.mapX = i;
				myData.mapY = j;
				myData.cctvType = map[i][j];
				myData.dir = -1;
				myV.push_back(myData);
			}
		}
	}
	// 방에 존재하는 cctv 총 개수
	cctvTotal = myV.size();

	// 첫번째 cctv부터
	SetDirection(0);

	// 최소 사각지대 넓이 출력
	cout << area << endl;

	return 0;	
}
