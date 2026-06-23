#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    // 십진수 -> 이진수로 변환
    // 0 = "", 1 = "#"
    // 9 -> 01001 (n = 5) 1001이지만 빈자리는 0으로 채우기
    // 9 % 2 = 1 9 / 2 = 4
    // 4 % 2 = 0 4 / 2 = 2
    // 2 % 2 = 0 2 / 2 = 1
    // 1 % 2 = 1 1 / 2 = 0
    // 0 % 2 = 0 ---------
    for(int i = 0; i < n; i++){
        string map;
        int aBin;
        int bBin;
        int a = arr1[i];
        int b = arr2[i];
        
        for(int j = 0; j < n; j++){
            aBin = (a % 2);
            a = a / 2;
            
            bBin = (b % 2);
            b = b / 2;
            
            if(aBin != bBin)
                map = '#' + map;
            else if(aBin == bBin && aBin == 0)
                map = ' ' + map;
            else //if(aBin == bBin && aBin == 1)
                map = '#' + map;
        }
        answer.push_back(map);
    }
    
    
    return answer;
}