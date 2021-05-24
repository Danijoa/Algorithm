using System;
using System.Collections.Generic;

public class Solution {
    public List<int> solution(int[] progresses, int[] speeds) 
    {
         int len = progresses.Length;
            int[] remainProgresses = new int[len];
            for (int i = 0; i < len; i++)
            {
                remainProgresses[i] = 100 - progresses[i];
            }

            int[] remainDays = new int[len];
            for (int i = 0; i < len; i++)
            {
                int tempDay = remainProgresses[i] / speeds[i];
                if (remainProgresses[i] % speeds[i] == 0)
                {
                    remainDays[i] = tempDay;
                }
                else if (remainProgresses[i] % speeds[i] != 0)
                {
                    remainDays[i] = tempDay + 1;
                }
            }

            //int[] answer = new int[100];
            List<int> answer = new List<int>();
            //int h = 0;
            int k = 0;
            while (k != len)
            {
                int startingK = k;
                int tempCheck = remainDays[k];
                while ((k + 1) != len && remainDays[k + 1] <= tempCheck)
                {
                    k++;
                }

                //answer[h] = k - startingK + 1;
                answer.Add(k - startingK + 1);
                //h++;
                k++;
            }

            /*for (int i = 0; i < answer.Count; i++)
            {
                Console.Write(answer[i] + " ");
            }*/
        return answer;
    }
}
