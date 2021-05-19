#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
  
	vector<int> temp;
	char s, ss;
	int check = 0, order = 0;
	for (int i = 0; i < skill_trees.size(); i++)	//유저 스킬 갯수
	{
		for (int j = 0; j < skill.length(); j++)
		{
			s = skill.at(j);
			for (int k = 0; k < skill_trees[i].length(); k++)	//유저 스킬 상세
			{
				ss = skill_trees[i].at(k);

				if (s == ss)
				{
					temp.push_back(k);
					if (temp .size() != j+1)
					{
						order = 1;
					}
				}
			}
		}

		for (int m = 0; m < temp.size(); m++)
		{
			printf("%d ", temp[m]);
		}
		printf("\n");

		for (int l = 1; l < temp.size(); l++)
		{
			if (temp[l - 1] > temp[l])
			{
				check = 1;
			}
		}

		if (check == 0 && order == 0)
		{
			answer++;
		}
		temp.clear();
		check = 0;
		order = 0;
	}

	printf("answer: %d", answer);
	return answer;
}
