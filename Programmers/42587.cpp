using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] priorities, int location) {
        List<Tuple<int, int>> order = new List<Tuple<int, int>>();
            for (int i = 0; i < priorities.Length; i++)
            {
                order.Add(Tuple.Create(i, priorities[i]));    
            }
            // item2: 2 1 3 2
            // item1: 0 1 2 3
            // 3 2 2 1
            // 2 3 0 1

            int answer = 0;
            while (true)
            {
                int curPriority = order[0].Item2;
                int curLocation = order[0].Item1;

                for (int i = 1; i < order.Count; i++)   //뒤에 우선순위 높은 것이 있는 경우
                {
                    if (curPriority < order[i].Item2)
                    {
                        order.RemoveAt(0);
                        order.Add(Tuple.Create(curLocation, curPriority));
                        break;
                    }
                }

                if (curLocation == order[0].Item1) //맨 앞이 가장 우선순위가 높은 경우
                {
                    order.RemoveAt(0);
                    answer++;
                    if (curLocation == location)
                    {
                        break;
                    }
                }
            }

            return answer;
    }
}
