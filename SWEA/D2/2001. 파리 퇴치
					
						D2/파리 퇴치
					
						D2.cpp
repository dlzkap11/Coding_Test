#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        int m;
        
        cin >> n;
        cin >> m;
        vector<vector<int>> fly(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> fly[i][j];
            }
        }

        int dx = 0;
        int dy = 0;
        int sum = 0;
        int max = 0;

        for(int i = 0; i < n - m + 1; i++){
            for(int j = 0; j < n - m + 1; j++){
            	for(int x = 0 + dx; x < m + dx; x++){
            	    for(int y = 0 + dy; y < m + dy; y++){
            	        sum += fly[x][y];
            	    }
            	}
            	if(sum > max) max = sum;
                sum = 0;
            	dy++;
            }
            dy = 0;
            dx++;
         }
        
        cout << "#" << test_case << ' ' <<max << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}