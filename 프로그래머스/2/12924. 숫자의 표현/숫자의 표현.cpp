#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 연속된 자연수로 n을 만들기
    // 1 ~ n까지 반복하면서 n을 만드는 경우 세기 -- 가장 원초적 방법 - 효율 개구데기
    // 1 ~ n/2까지 반복하기 + n = n -- 반으로 줄임 -- 여전히 좀 별로인듯;;
    int num = n/2;
    int result = 0;
    int count = 0;
    
    for(int j = 0; j <= num; j++){
        result = 0;
        for(int i = 1 + j; i < n; i++){
            result += i;
            if(result == n){
                count++;
                break;
            }
            if(result > n){
                break;
            }
        }
    }
    
    return count + 1;
}