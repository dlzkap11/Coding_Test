#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i <n; i++){
        int bin = arr1[i]|arr2[i]; // 둘을 비교해서 둘 다 0이면 0반환 아니면 1반환
        string ans = "";
        for(int j = 0; j<n; j++){
            if(bin % 2 == 0) ans = " " + ans;
            else ans = "#" + ans;
            bin = bin >> 1; //>> 1 == / 2
        }
        answer.push_back(ans);
    }
    return answer;
}