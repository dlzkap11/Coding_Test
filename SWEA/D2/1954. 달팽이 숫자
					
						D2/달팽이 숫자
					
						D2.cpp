#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

    int n;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << endl;
        cin >> n;
        
        vector<vector<int>> snail(n, vector<int>(n, 0));
        int cnt = 1;
        int x = 0;
        int y = 0;
        int h = 0;
        
       while(true) {
    		bool found = false;
    		for (int i = 0; i < n; i++) {
    		    for (int j = 0; j < n; j++) {
    		        if (snail[i][j] == 0) {
    		            found = true;
    		            break;
    		       }
    		   }
           }
           if(!found) break;
           
        	y = y + h;
        	h++;
        	// 오른쪽으로
        	for(; x < n; x++){
        		if(snail[y][x] == 0){
        		    snail[y][x] = cnt;
        	        cnt++;
        		}
        	}
        	x = x - h;
        	// 아래로
        	for(; y < n; y++){
        		if(snail[y][x] == 0){
        		    snail[y][x] = cnt;
        	        cnt++;
        		}
        	}
        	y = y - h;
        	//왼쪽으로
        	for(; x >= 0; x--){
        		if(snail[y][x] == 0){
        		    snail[y][x] = cnt;
        		    cnt++;
        		}
        	}
        	x = x + h;
        	//위쪽으로
        	for(; y > 0; y--){
        		if(snail[y][x] == 0){
        		    snail[y][x] = cnt;
        		    cnt++;
        		}
        	}
       }
        
        for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        if(j != n - 1)
		            cout << snail[i][j] << " ";
		        else
		            cout << snail[i][j];
		    }
		    cout << endl;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}