using System;
using System.Collections.Generic;

public class Solution
{
    public int solution(string skill, string[] skill_trees)
    {
        int answer = 0;
        // 스킬 서순
        // skill => 스킬순서 skill_trees => 유저들이 만든 스킬트리
        // 유저들이 만든 스킬트리에서 가능한게 몇개인지 알아내시오
        // 스킬은 알파벳 대문자
        // CBD => C -> B -> D 순서
        LinkedList<char> list = new LinkedList<char>();
        LinkedListNode<char> node;

        // CBD는 일단 서로 연결되어야함
        for (int i = 0; i < skill.Length; i++)
        {
            list.AddLast(skill[i]); // C -> B -> D
        }

        for (int j = 0; j < skill_trees.Length; j++)
        {
            node = list.First;
            for (int i = 0; i < skill_trees[j].Length; i++)
            {
                if (node == null){
                    answer++;
                    break;
                }
                
                if(!list.Contains(skill_trees[j][i])){
                    if(i == skill_trees[j].Length - 1)
                        answer++;
                    continue;
                }
                    
                
                
                if (skill_trees[j][i] == node.Value){
                    node = node.Next;
                }
                else{           
                    break;
                }
                
                if(i == skill_trees[j].Length - 1)
                    answer++;
            }
        }

        return answer;
    }
}