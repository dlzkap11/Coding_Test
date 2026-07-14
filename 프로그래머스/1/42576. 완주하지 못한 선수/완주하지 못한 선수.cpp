#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // 맵에다가 선수들을 추가
    unordered_map<string,int> um;
    for(int i = 0; i < participant.size(); i++){
        if(um.find(participant[i]) != um.end())
            um[participant[i]]++;
        else
            um.insert({participant[i], 1});
    }
    
    // 완주한 선수들을 한명씩 제거(죽이는거 아님)
    for(int i = 0; i < completion.size(); i++){
        if(um.find(completion[i]) != um.end())
            um[completion[i]]--;
    }
    
    for(pair<string,int> elem : um){
        if(elem.second == 1){
            answer = elem.first;
            break;
        }
            
    }
    
    return answer;
}