#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int w_x = wallet[0];
    int w_y = wallet[1];
    int b_x = bill[0];
    int b_y = bill[1];
    // 지갑에 지폐가 들어갈 때 까지
    // 지갑 가로 세로를 비교해서 지폐가 더 작아질 때까지
    int w_max = w_x > w_y ? w_x : w_y;
    int w_min = w_max == w_x ? w_y : w_x;
    int b_max = b_x > b_y ? b_x : b_y;
    int b_min = b_max == b_x ? b_y : b_x;

    
    while(true){
        if(w_max >= b_max && w_min >= b_min)
            break;
        
        if(b_x >= b_y){
            b_x /= 2;
        }
        else{
            b_y /= 2;
        }
        b_max = b_x > b_y ? b_x : b_y;
        b_min = b_max == b_x ? b_y : b_x;
        answer++;
    }

    return answer;
}