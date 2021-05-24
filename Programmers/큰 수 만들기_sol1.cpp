//  출제의도: "greedy", Time Complexity: O(n*k), Space Complexity: O(1). (n: number.size)
//  number[i]<number[i+1] 인 가장 앞인 i를 제거. 만약, 내림차순 정렬되어있다면 가장 뒤의 원소를 제거.

#include <string>
#include <vector>

using namespace std;

void erase(string &number) {
    if(number.size()==1) {
        number = "";
        return;
    }
    
    for(int i=0;i<number.size()-1;i++) {
        if(number[i]<number[i+1]) {
            number.erase(number.begin()+i);
            break;
        }
        
        if(i==number.size()-2) {
            number.erase(--number.end());
        }
    }
}

string solution(string number, int k) {
    string answer = "";
    for(int i=0;i<k;i++) {
        erase(number);
    }
    answer = number;
    return answer;
}
