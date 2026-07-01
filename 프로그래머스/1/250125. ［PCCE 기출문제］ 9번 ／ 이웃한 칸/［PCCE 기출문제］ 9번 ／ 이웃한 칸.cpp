#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    //주어진 보드좌표에서 위로 한칸 아래로 한칸 양옆 한칸의 좌표들을 구한다.
    //주어진 좌표에 있는 값과 같은 값이면 answer++
    vector<int> dh = vector<int>{0, 1, -1, 0};
    vector<int> dw = vector<int>{1, 0, 0, -1};
    
    for(int i = 0; i < dh.size(); i++){
        if(h + dh[i] < 0 || h + dh[i] >= board.size() || w + dw[i] < 0 || w + dw[i] >= board.size())
            continue;
        
        if(board[h][w] == board[h + dh[i]][w + dw[i]])
            answer++;
    }

    return answer;
}