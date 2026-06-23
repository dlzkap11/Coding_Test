#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    // 이름이 없으면 안그리움 0점
    // name[i]와 photo[0][j]를 비교
    // 같은 이름이면 miss에 yearning[i]를 더하기
    // 이 후 다음 name[i + 1]과 photo[0][j] 비교

    for(int t = 0; t < photo.size(); t++){
        int miss = 0;
        for(int i = 0; i < name.size(); i++){
            for(int j = 0; j < photo[t].size(); j++){
                if(name[i] == photo[t][j]){
                    miss += yearning[i];
                    break;
                }
            }
        }
        answer.push_back(miss);
    }
    
    
    
    
    return answer;
}