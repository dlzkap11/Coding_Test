#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    //N / 2
    //최대한 여러 종류의 폰켓몬을 가져가기
    //<1,1> <2,1> <3,2>
    //4 / 2 = 2
    //종류가 몇개인지 세기
    //만약 가져갈수있는 포켓몬 수가 포켓몬 종류보다 많으면 종류수를 반환
    //만약 가져갈 수 있는 포켓몬 수가 포켓몬 종류보다 적으면 가져갈 수 있는 포켓몬 수 반환
    //6 6 6 6 6 6| 1 // 3 => 1
    // 같으면 그냥 그 수 반환
    //결론 종류별로 박스에 넣고 박스 수를 세면 된다.
    int get = nums.size()/2; // 가져갈 수 있는 포켓몬
    unordered_map<int, int> box;
    for(int i = 0; i < nums.size(); i++){
        box[nums[i]]++;
    }

    return box.size() > get ? get : box.size();
}