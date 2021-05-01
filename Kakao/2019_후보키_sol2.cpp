// 최소성 검사를 비트연산 &으로 간결하게 해결.(comb비트열의 특수한 증가패턴 덕분에 가능.) 
// "super가 candidate[i] 비트열을 포함한다"는 다음 2가지 방법으로 표현 가능.  1. (candidate[i]|super)==super  2. (candidate[i]&super)==candidate[i] 

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
