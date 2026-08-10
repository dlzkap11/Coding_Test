#include <string>
using namespace std;

int solution(string s) {
    int i = 0;
    for (const char ch : s) {
        if (i > 0 && s[i - 1] == ch)
            i--;  
        else {
            s[i] = ch;
            i++;
        }
    }
    return !i;
}