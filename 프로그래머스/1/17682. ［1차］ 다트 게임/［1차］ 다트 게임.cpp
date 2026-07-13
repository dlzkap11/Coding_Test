#include <string>

using namespace std;
bool IsStar = false;
int StarOrAcha(string dartResult, int index){
    if(index >= dartResult.size())
        return 1;
    
    //*이 나오는 경우
    //1번째 2~3
    //2번째 4~7
    //3번째 6~11
    //1S2T3D
    //10S*10D*10T*
    //10S0D4D*
    
    // index가 4이고 *이면 첫번째 결과값 * 2;
    if(dartResult[index] == '*'){
        if(index >= 4)
            IsStar = true;
            return 2;
        }
    else if(dartResult[index] == '#'){
            return -1;
        }
    else 
        return 1;
}

int Pow(string dartResult, int index, int result){
    if(dartResult[index] == 'S'){ 
        result = result * StarOrAcha(dartResult, index + 1);
    }
    else if(dartResult[index] == 'D'){
        result = result * result * StarOrAcha(dartResult, index + 1);
    }
    else if(dartResult[index] == 'T'){
        result = result * result * result * StarOrAcha(dartResult, index + 1);
    }
    return result;
}

int Num(string dartResult, int index){
    int num = 0;
    if(dartResult[index] == '0' && dartResult[index - 1] == '1'){
        //10
        num = 10;
        num = Pow(dartResult, index + 1, num);
        return num;
    }
    else if(dartResult[index] == '0' && dartResult[index - 1] != '1'){
        num = 0;
        num = Pow(dartResult, index + 1, num);
        return num;
    }
    
    for(int i = index; i < dartResult.size(); i++){
        //1~9사이 
        if(48 <= dartResult[i] && dartResult[i] <= 57){
            //1 이후 0이 온다면
            if(dartResult[i] == '1' && dartResult[i + 1] == '0'){
                //10
                num = 10;
                num = Pow(dartResult, i + 2, num);
                break;
                
            }
            num = dartResult[i] - 48;
            num = Pow(dartResult, i + 1, num);
            break;
        }
    }
    // 3번째 점수 누락시
    if(num == 0 && index == 6){
        for(int i = index; i > 0; i--){
        //0~9사이 
        if(48 <= dartResult[i] && dartResult[i] <= 57){
            //0이고 앞자리가 1이면 10 아니면 0
            if(dartResult[i] == '0' && dartResult[i - 1] == '1'){
                //10
                num = 10;
                num = Pow(dartResult, i + 1, num);
                break;
            }
            else if(dartResult[i] == '0' && dartResult[i - 1] != '1'){
                num = 0;
                num = Pow(dartResult, i + 1, num);
                break;
            }
            
            num = dartResult[i] - 48;
            num = Pow(dartResult, i + 1, num);
            break;
            }
        }   
    }
    
    return num;
}

int solution(string dartResult) {
    int answer = 0;
    // 숫자 / 문자/ 문자/
    // 10인 경우를 대비 dartResult[i]가 숫자인가? -> dartResult[i]가 1이면 dartResult[i + 1]도 확인 후 숫자면
    // 10 아니면 1 나머지는 그냥 ㄱㄱ
    // 다음 SDT 확인 값에 따라서 제곱
    // 다음 # * 확인 후 2배 혹은 마이너스인데 여기서 #이 2번째에서 나왔다면 1번째 결과값도 2배 해주기
    int fst;
    int snd;
    int trd;
    fst = Num(dartResult, 0);
    snd = Num(dartResult, 2);
    if(IsStar){
        fst = fst * 2;
        IsStar = false;
    } 
    trd = Num(dartResult, 6);
    if(IsStar){
        snd = snd * 2;
        IsStar = false;
    }
    answer = fst + snd + trd;
    //0 48 9 57
    //48 ~ 57
    return answer;

}
