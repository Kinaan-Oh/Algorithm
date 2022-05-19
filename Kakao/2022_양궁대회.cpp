// Implementation/BitMask or DFS, Time Complexity: O(2^11*n), Space Complexity: O(n) (n ~= 1...10)
// 논리: 1. 모든 경우 탐색시 Worst Case 11^10 연산 필요. 실행시간 약 260초로 시간제한 10초를 넘김. 보다 효율적 방법 필요.
//      2-1. Example을 Hint로 활용. 최대 점수 계산을 위해 굳이 모든 경우 탐색 필요 없음. 각 점수를 획득/포기 2가지 경우를 탐색할 수 있음
//      2-2. Worst Case 2^11*10 ~= 20000 연산 필요. 따라서 약 0.5초 내외의 실행시간 필요. 시간제한 10초를 여유롭게 통과 가능.
//      3. 각 경우를 탐색하기 위해 dfs, bitmask 등 여러 방법 선택 가능. bitmask 선택이 보다 적절.
//      4. 점수 획득 로직에 대한 디테일한 고려 필요. 강조된 제한사항 고려 못하여 약 10분 수준의 리소스 낭비.

#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

bool compareLow(vector<int> answer, vector<int> target) {
    for(int i=10;i>=0;i--) {
        if(target[i]>answer[i]) {
            return true;
        } else if(target[i]<answer[i]) {
            return false;
        }
    }  
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer = {-1};
    int maxScoreDiff = -1;
    int cur = (1<<11)-1;
    int end = 0;
    
    while(cur>=end) {
        vector<int> target;
        
        for(int i=0;i<11;i++) {
            if(cur&(1<<(10-i))) {
                if(info[i]==0) {
                    target.push_back(1);
                } else {
                    target.push_back(info[i]+1);
                }
            } else {
                target.push_back(0);
            }
        }
        
        int sum = accumulate(target.begin(), target.end(), 0);
        
        if(sum<=n) {
            if(sum<n)   target[10] += (n-sum);
            int curScoreDiff = 0;
            
            for(int i=0;i<11;i++) {
                if(target[i]>info[i]) {
                    curScoreDiff += (10-i);
                } else if(target[i]<info[i] || (info[i]>0 && target[i]==info[i])) {
                    curScoreDiff -= (10-i);
                }
            }

            if(curScoreDiff>0) {
                if((curScoreDiff>maxScoreDiff) ||
                   curScoreDiff==maxScoreDiff && compareLow(answer,target)
                  ) {
                    maxScoreDiff = curScoreDiff;
                    answer = target;
                }
            }
        }
        cur -= 1;
    }
    return answer;
}
