#include <string>
#include <vector>

using namespace std;
char c[29];
string solution(vector<string> a, vector<string> b) {
    for(int j=0;j<21;j++){
        c[j] = 0;
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            c[j]^=a[i][j];
        }
    }
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].size();j++){
            c[j]^=b[i][j];
        }
    }
    return string(c);
}