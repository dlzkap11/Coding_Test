using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.Length]; 
        Stack<int> stack = new Stack<int>();

        for(int i = numbers.Length-1 ; i>=0 ; i--)
        {
            if(stack.Count ==0)
            {
                answer[i]=-1;
                stack.Push(numbers[i]);
                continue;
            }

            while(stack.Count>0)
            {
                if(stack.Peek()>numbers[i])
                {
                    answer[i]=stack.Peek();
                    stack.Push(numbers[i]);                    
                    break;
                }
                stack.Pop();
            }

            if(answer[i]==0)
            {
                answer[i]=-1;
                stack.Push(numbers[i]);
            }

        }
        return answer;
    }
}