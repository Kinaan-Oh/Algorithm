// 중복성 검사는 Set 자료구조를 활용.
// 최소성 검사를 비트연산 &으로 간결하게 해결.(comb비트열의 특수한 증가패턴 덕분에 따로 순서를 고려하지 않고 진행할 수 있음.) 
// "비트열B가 비트열A를 포함한다"는 다음 2가지 방법으로 표현 가능.  1. (A|B)==B  2. (A&B)==A 
// 출제의도는 "비트 연산"으로 생각됨. (1) 모든 조합 구현 2) 최소성 검사)

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

bool checkMinimality(vector<int> &candidate, int super) {
    for(int i=0;i<candidate.size();i++) {
        if((candidate[i]|super)==super)    return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size(), col = relation[0].size();
    vector<int> candidate;
    for(int comb=1;comb<(1<<col);comb++) {
        set<string>  tuples;  
        for(int i=0;i<row;i++) {
            string tuple;
            for(int j=0;j<col;j++) {
                if(comb&(1<<j)) {
                    tuple = relation[i][col-1-j]+" "+tuple;
                }
            }
            tuples.insert(tuple);
        }
        if(tuples.size()==row && checkMinimality(candidate,comb))  candidate.push_back(comb);
    }
    answer = candidate.size();
    return answer;
}
