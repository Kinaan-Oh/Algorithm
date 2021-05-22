// 출제의도: "합성수", Time Complexity: O(yellow^(1/2)), Space Complexity: O(1).
// 합성수의 성질을 이용하면 h를 sqrt(yellow)까지만 확인하면 됨.
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int h=1;h<=sqrt(yellow);h++) {
        int w = yellow%h==0 ? yellow/h : 0;
        if(w && 2*(w+h+2)==brown) {
            answer = {w+2,h+2};
            break;
        }
    }
    return answer;
}
