#include <string>
#include <vector>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) 
{
    string answer = "";

    vector<vector<string>> myTable(table.size());
    for (int i = 0; i < myTable.size(); i++)
    {
        string tempTable = table[i];
        string temp = "";
        
        for (int j = 0; j < tempTable.size(); j++)
        {
            if (tempTable[j] == ' ')
            {
                myTable[i].push_back(temp);
                temp = "";
            }
            else
                temp += tempTable[j];
        }
        myTable[i].push_back(temp);
    }

    for (int i = 0; i < myTable.size(); i++)
    {
        for (int j = 0; j < myTable[i].size(); j++)
        {
            //cout << myTable[i][j] << " ";
        }
        //cout << endl;
    }

    int max = 0;
    int num = preference.size();
    int index = 0;

    for (int i = 0; i < myTable.size(); i++)
    {
        int sum = 0;

        for (int j = 1; j < myTable[i].size(); j++)
        {
            string job = myTable[i][j];

            for (int k = 0; k < num; k++)
            {
                string langues = languages[k];
                if (job.compare(langues) == 0)
                {
                    sum += preference[k] * (myTable.size() + 1 - j);
                    break;
                }
            }
        }


        if (max == sum)
        {
            string a = myTable[i][0];           // 현재
            string b = myTable[index][0];       // 기존 

            if (a.compare(b) < 0)    // a가 b보다 사전순으로 앞인 경우
            {
                max = sum;
                index = i;
            }
        }
        else if(max < sum)
        {
            max = sum;
            index = i;
        }
    }

    answer = myTable[index][0];
    //cout << answer;
    return answer;
}

int main() 
{
    vector<string> table;
    table.push_back("SI JAVA JAVASCRIPT SQL PYTHON C#");
    table.push_back("CONTENTS JAVASCRIPT JAVA PYTHON SQL C++");
    table.push_back("HARDWARE C C++ PYTHON JAVA JAVASCRIPT");
    table.push_back("PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP");
    table.push_back("GAME C++ C# JAVASCRIPT C JAVA");

    vector<string> languages;
    languages.push_back("PYTHON");
    languages.push_back("C++");
    languages.push_back("SQL");

    vector<int> preference;
    preference.push_back(7);
    preference.push_back(5);
    preference.push_back(5);

    solution(table, languages, preference);

    /*
    vector<vector<int>> a(2);

    a[0].push_back(1);
    a[0].push_back(1);
    a[0].push_back(1);
    
    a[1].push_back(1);
    a[1].push_back(1);
    a[1].push_back(1);
    a[1].push_back(1);
    a[1].push_back(1);
    a[1].push_back(1);

    //a[2][0] = 1;
    //a[2][1] = 1;
    //a[2][2] = 1;

    cout << a.size() << endl;
    cout << a[0].size() << endl;
    cout << a[1].size() << endl;
    //cout << a[2].size() << endl;
    */

    return 0;
}
