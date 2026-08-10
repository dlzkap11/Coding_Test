#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();  // 같은 문자면 제거
        } else {
            st.push(c);  // 다르면 스택에 추가
        }
    }
    
    return st.empty() ? 1 : 0;
    
    

}