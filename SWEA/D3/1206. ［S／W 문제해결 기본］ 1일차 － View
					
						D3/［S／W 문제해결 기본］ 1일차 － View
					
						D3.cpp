#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	
    int length;
	for(test_case = 0; test_case < T; ++test_case)
	{
        cin >> length;
		int* apt = new int[length];
        for(int i = 0; i < length; i++){
        	cin >> apt[i];
        }
        
        int view = 0;					  // 조망권
        
        for(int i = length - 3; i >= 0; i--){
			if(apt[i] > apt[i-1] && apt[i] > apt[i-2] && apt[i] > apt[i+1] && apt[i] > apt[i+2]){
                //cout << "apt[i] "<< apt[i] << " " ;
                
            	if(apt[i - 1] >= apt[i -2] && apt[i - 1] >= apt[i +2] && apt[i - 1] >= apt[i + 1]) {
                    //cout << apt[i-1] << " " ;
                    view += apt[i] - apt[i -1];
                }
                else if(apt[i - 2] >= apt[i -1] && apt[i - 2] >= apt[i +2] && apt[i - 2] >= apt[i + 1]) {
                    //cout << apt[i-2] << " " ;
                	view += apt[i] - apt[i -2];
                }
                else if(apt[i + 1] >= apt[i -1] && apt[i + 1] >= apt[i +2] && apt[i +1] >= apt[i - 2]) {
                    //cout << apt[i+1]<< " " ;
                	view += apt[i] - apt[i + 1];
                }
                else if(apt[i + 2] >= apt[i -1] && apt[i + 2] >= apt[i +1] && apt[i +2] >= apt[i - 2]) {
                    //cout << apt[i+2] << " " ;
                	view += apt[i] - apt[i + 2];
                }
                //cout << endl;
                //cout << view << " " ;
            }
        }

        cout << "#" << test_case + 1 << " " << view << endl;
        delete[] apt;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}