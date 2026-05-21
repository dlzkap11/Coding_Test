#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	int length;
   
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> length;
        int *arr = new int[length];
		
        for(int i = 0; i < length; i++){
        	cin >> arr[i];
        }
        long long gain = 0; // 이익금
        int maxPrice = arr[length - 1];

        for (int i = length - 2; i >= 0; i--) {
            if (arr[i] < maxPrice) gain += maxPrice - arr[i];
            else maxPrice = arr[i];
        }
        
        cout << "#" << test_case << " " << gain << endl;
        delete[] arr;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}