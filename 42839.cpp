#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 11
using namespace std;

vector<int> sosuCan;    //소수 후보자들
int numInt[MAX];    //숫자 배열 저장
int numArr[MAX];    //숫자 조합 저장
int tempArr[MAX];    //숫자 임시

//순열
void swap(int numArr[], int s, int i)
{
    int temp = numArr[s];
    numArr[s] = numArr[i];
    numArr[i] = temp;
}

void doPermutation(int numArr[], int startIndex, int length)
{
    if (startIndex == length - 1)
    {
        if (numArr[0] != 0)
        {
            int temp = 0;
            for (int i = 0; i < length; i++)
            {
                temp += numArr[i] * pow(10, (length - 1) - i);
            }
            sosuCan.push_back(temp);
            //cout << temp << endl;
        }
    }

    for (int i = startIndex; i < length; i++)
    {
        swap(numArr, startIndex,i);
        doPermutation(numArr, startIndex+1, length);
        swap(numArr, startIndex, i);
    }
}

//조합
void doCombination(int tempArr[], int numInt[], int size, int count, int index, int target, int length)
{
    if (count == 0) //count 개수 만큼 다 뽑은 경우
    {
        for (int i = 0; i < length; i++)
        {
            //cout << numInt[tempArr[i]] << " ";
            numArr[i] = numInt[tempArr[i]];
        }
        //cout << endl;
        doPermutation(numArr, 0, length);
    }
    else if (target == size)
    {
        return;
    }
    else 
    {
        tempArr[index] = target;
        doCombination(tempArr, numInt, size, count-1, index+1, target+1, length);
        doCombination(tempArr, numInt, size, count, index, target + 1, length);
    }
}

//소수 판별(에라토스테네스의 체)
bool* primeArr;
void Eratos(int num)
{
    primeArr = new bool[num + 1];
    
    for (int i = 2; i <= num; i++)
        primeArr[i] = true;

    for (int i = 2; i * i <= num; i++)
    {
        if (primeArr[i] == true)   //첫 수가 소수이면
        {
            for (int j = i * i; j <= num; j += i)
            {
                primeArr[j] = false;    //그 배수는 모두 false
            }
        }
    }
}

bool isIncluded(int num)
{
    for(int i=0; i< sosuCan.size(); i++)
    {
        if (num == sosuCan[i])
        {
            return true;
            break;
        }
    }
    return false;
}

int solution(string numbers) 
{
    //string to int
    int length = numbers.length();  
    int num = stoi(numbers);    
    for (int i = 1; i <= length; i++)
    {
        numInt[i - 1] = num % 10;
        num = num / 10;
    }
    
    //소수 후보자 저장(조합+순열)
    for (int i=1; i<=length; i++)
    {
        int count = i;
        doCombination(tempArr, numInt, length, count, 0, 0, i);
    }

    //오름차순 ->중복 제거 필요
    sort(sosuCan.begin(), sosuCan.end());

    //소수 찾기
    int answer = 0;
    Eratos(sosuCan[sosuCan.size() - 1]);
    for (int i = 2; i <= sosuCan[sosuCan.size() - 1]; i++)
    {
        if (primeArr[i] && isIncluded(i))
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    string numbers;
    cin >> numbers;

    cout << solution(numbers) << endl;
	return 0;
}
