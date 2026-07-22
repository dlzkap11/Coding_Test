#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    // bandage - 시전시간, 초당 회복량, 추가 회복량
    // attacks - [공격시간, 피해량] ...
    // health - attacks[0][1];
    int max = health;
    // 때리는 횟수만큼 반복
    // 맞을 때 회복X
    
    int last = attacks[attacks.size() - 1][0];

    //마지막 공격까지 반복 i = 시간
    int cnt = 0;
    int plus = 0;
    for(int i = 0; i <= last; i++){
        if(i == attacks[cnt][0]){
            health -= attacks[cnt][1];
            cnt++;
            plus = 0;
            if(health <= 0){
                health = -1;
                return health;
            }
            continue;
        }
        
        health += bandage[1];
        plus++;
        if(plus == bandage[0]){
            health += bandage[2];
            plus = 0;
        }
        if(health > max)
            health = max;
    }
    
    answer = health;
    return answer;
}