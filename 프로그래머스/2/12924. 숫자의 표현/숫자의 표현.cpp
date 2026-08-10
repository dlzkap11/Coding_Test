#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int digit = 0;

    for (int i = 0; i < n; i++)
    {
        digit += i;
        int share = n - digit;
        int div = i + 1;

        if (share >= div && share % div == 0) answer++;
    }

    return answer;
}