#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() 
{
	int testCase;
	cin >> testCase;
	while (testCase != 0) 
    {
         testCase--;
        
        int note;
		cin >> note;
        vector<int> noteNode;
		while (note !=0) 
        {
            note--;
            int num;
			cin >> num;
			noteNode.push_back(num);
		}//node의 값은 0
        sort(noteNode.begin(), noteNode.end()); 
        
        int answer;
		cin >> answer;
        vector<int> answerNode;
		while (answer !=0) 
        {
            answer--;
            int num;
			cin >> num;
			answerNode.push_back(num);
        }
 
        int j=0;
        while(j != answerNode.size())
        {
			int check = 0;
			int first = 0;
			int last = noteNode.size() - 1;
			while (first <= last) 
            {
				int mid = (first + last) / 2;
				if (answerNode[j] == noteNode[mid]) 
                {
					check = 1;
					break;
				}
                else
                {
                    if(noteNode[mid] > answerNode[j])
                    {
                        last = mid - 1;
                    }
                    else
                    {
                        first = mid + 1;
                    }
                }
			}
			cout << check << "\n";
            j++;
		}
	}
}
