#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.rbegin(), people.rend());
    int cnt = 0;
    int left = 0;
    int right = people.size() - 1;

    while(left <= right){
        if(people[left] == limit)
            left++;
        else if(people[left] + people[right] > limit){
            left++;
        }
        else if(people[left] + people[right] <= limit){
            left++;
            right--; 
        }
        cnt++;
    }
    
    return cnt;
}