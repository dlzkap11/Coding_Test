#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    unordered_map<string, int> mapping{{"code",0},{"date",1},{"maximum",2},{"remain",3}};

    for (vector<int>& datum:data){
        if (datum[mapping[ext]] < val_ext)
            answer.push_back(datum);
    }

    sort(answer.begin(), answer.end(), [&](vector<int>& a, vector<int>& b){return a[mapping[sort_by]] < b[mapping[sort_by]];});

    return answer;
}