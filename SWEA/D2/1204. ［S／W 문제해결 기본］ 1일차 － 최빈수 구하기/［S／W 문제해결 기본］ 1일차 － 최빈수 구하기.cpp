#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int test;
        cin >> test;

        // 0~100 점수 분포도
        int* count = new int[101];
        for (int i = 0; i < 1000; i++)
        {
            int score;
            cin >> score;
            count[score]++;

        }
        int max = 0;
        int result;
        
        for (int i = 1; i < 101; i++)
        {
            if (max <= count[i]){
                max = count[i];
                result = i;
            }
        }

        cout << "#" << test << " " << result << endl;

    }
}