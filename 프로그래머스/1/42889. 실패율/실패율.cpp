#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,float>& a, const pair<int,float>& b) {
	    if (a.second == b.second) return a.first < b.first;
	    return a.second > b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    long players = stages.size(); // 전체 이용자 수
    //<스테이지, 도전자 수>
    unordered_map<long, long> currentMap;
    
    //현재 도전중인 스테이지의 사람들을 모은다
    for(long i = 0; i < players; i++){
        currentMap[stages[i]]++;
    }
    
    //<스테이지, 실패율>
    unordered_map<int, float> failMap;
    
    //스테이지 수만큼 반복
    for(int i = 1; i <= N; i++){
        float fail = 0;
        //해당 스테이지의 실패율을 구하고, 전체 플레이어에서 해당 스테이지를 도전 중인 플레이어를 뺀다.
        // 만약 players가 0이면 fail = 0을 반환
        if(players == 0){
            failMap[i] = fail;
            continue;
        }
            
        fail = (float)currentMap[i] / players; //실패율
        players -= currentMap[i];
        //실패율은 따로 모아두기
        failMap[i] = fail;

    }
    //스테이지, 실패율 정렬을 위해 vector형태로 가져옴(배열)
    vector<pair<int,float>> vec( failMap.begin(), failMap.end() );
    
    sort(vec.begin(), vec.end(), cmp);
        //faliMap -> 1, 1/8 : 2, 3/7 : 3, 2/4 ...
        //value(실패율)값에 크기에 따라 정렬 후 key(스테이지)를 answer에 넣기

    for (auto num : vec) {
		answer.push_back(num.first);
	}
    
    return answer;
}