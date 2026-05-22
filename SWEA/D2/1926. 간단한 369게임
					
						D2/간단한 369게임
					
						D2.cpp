#include<iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    
    string num;
    for(int i = 1; i <= N; i++){
        bool isSkip = false;
        /*
        num = to_string(i);
        int j = 0;
        while(j < num.length()){
             //num[0] 은 맨 앞자리 이 후 두번째 3번째
            if(num[j] == '3' || num[j] == '6' || num[j] == '9'){
                cout << "-";
                isSkip = true;
            }
            j++;
        }
        */

        int temp = i;
        while(temp != 0){
            if(temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9){
        		cout << "-";
                isSkip = true;
        	}
            temp = temp / 10;
        }
        
        if(!isSkip)
        	cout << i << " ";
        else 
            cout << " ";
    }

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}