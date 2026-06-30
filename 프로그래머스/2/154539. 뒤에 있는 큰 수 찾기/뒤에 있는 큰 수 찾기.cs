using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] numbers) {
        int n = numbers.Length;
        int[] answer = new int[n];
        Array.Fill(answer, -1);

        Stack<int> stack = new Stack<int>(); // 인덱스 저장

        for (int i = 0; i < n; i++) {
            while (stack.Count > 0 && numbers[stack.Peek()] < numbers[i]) {
                answer[stack.Pop()] = numbers[i];
            }
            stack.Push(i);
        }

        return answer;
    }
}