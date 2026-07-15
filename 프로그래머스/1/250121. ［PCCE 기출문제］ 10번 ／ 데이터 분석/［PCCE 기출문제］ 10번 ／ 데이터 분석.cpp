#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    //(data.size(), vector<int>(4, 0))
    //      code,   date, maximum, remain 오름차순
    //data[0][0], [0][1],  [0][2], [0][3]
    
    //ext - 기준, val_ext - 기준값(보다 작은 값만 추출), 나머지 정렬기준
    if(ext == "code"){
        for(int i = 0; i < data.size(); i++){
            if(data[i][0] < val_ext){
                answer.push_back(data[i]);
                //data.erase(data.begin() + i);
            }
        }
    }
    else if(ext == "date"){
        for(int i = 0; i < data.size(); i++){
            if(data[i][1] < val_ext){
                answer.push_back(data[i]);
            }
        }
    }
    else if(ext == "maximum"){     
        for(int i = 0; i < data.size(); i++){
            if(data[i][2] < val_ext){
                answer.push_back(data[i]);
            }
        }
    }
    else if(ext == "remain"){
        for(int i = 0; i < data.size(); i++){
            if(data[i][3] < val_ext){
                answer.push_back(data[i]);
            }
        }
    }
    
    //answer = data;

    if(sort_by == "code"){
        sort(answer.begin(), answer.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
    }
    else if(sort_by == "date"){
        sort(answer.begin(), answer.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
    }
    else if(sort_by == "maximum"){     
        sort(answer.begin(), answer.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
    }
    else if(sort_by == "remain"){
        sort(answer.begin(), answer.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[3] < b[3];
        });
    }
    
    return answer;
}