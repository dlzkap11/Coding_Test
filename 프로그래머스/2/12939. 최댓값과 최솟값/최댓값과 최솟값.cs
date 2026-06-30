using System;
public class Solution {
    public string solution(string s) {
        string answer = "";
        string[] arr = s.Split(' ');
        int max = int.Parse(arr[0]);
        int min = int.Parse(arr[0]);
        
        for(int i = 1; i < arr.Length; i++){
            max = Math.Max(max, int.Parse(arr[i].ToString()));
            min = Math.Min(min, int.Parse(arr[i].ToString()));
        }
        answer = min + " " + max;
        return answer;
    }
}