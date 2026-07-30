#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    // 내림차순 정렬 (가장 큰 돗자리부터 시도)
    sort(mats.rbegin(), mats.rend());
    
    int h = park.size();
    int w = park[0].size();
    
    for (int mat : mats) {
        // 돗자리가 공원보다 크면 스킵
        if (mat > h || mat > w) continue;
        
        for (int i = 0; i <= h - mat; i++) {
            for (int j = 0; j <= w - mat; j++) {
                bool canPlace = true;
                
                // mat x mat 영역 확인
                for (int di = 0; di < mat; di++) {
                    for (int dj = 0; dj < mat; dj++) {
                        // 빈 공간 ("-1") 이 아니면 배치 불가
                        if (park[i + di][j + dj] != "-1") {
                            canPlace = false;
                            break;
                        }
                    }
                    if (!canPlace) break;
                }
                
                // 배치 가능하면 바로 반환 (가장 큰 돗자리)
                if (canPlace) return mat;
            }
        }
    }
    
    // 아무 돗자리도 배치 불가
    return -1;
}