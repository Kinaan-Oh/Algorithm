// "Monotone Queue", Time Complexity: O(n), Space Complexity: O(k). (n: stones.size)
// i를 끝점으로 하는 길이 k인 윈도우 [i-k+1,i]에서 i+1 원소를 윈도우의 끝점으로 포함할 때, i+1번째 원소보다 크기가 작거나 같은 원소들을 제거(pop_back) 후 가장 뒤에 삽입.
// 이후, 윈도우에 포함되지 않게된 원소들을 제거(pop_front). 가장 앞의 원소가 현 윈도우의 최대값. 해당 과정을 반복하면 deque는 단조감소(stones 값) 상태를 유지하게 된다.
// 총 n번의 push_back(O(1)), n번 미만의 pop_back(O(1)) 연산이 발생. 따라서 전체 시간복잡도는 O(n).

#include <string>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = INT_MAX;
    deque<pair<int,int>>  monotone_que;   // pair(val,idx)
    for(int i=0;i<stones.size();i++) {
        while(!monotone_que.empty() && monotone_que.back().first<=stones[i]) {
            monotone_que.pop_back();
        }
        monotone_que.push_back({stones[i],i});
        while(monotone_que.front().second<i-k+1) {
            monotone_que.pop_front();
        }
        if(i>=k-1)    answer = min(answer, monotone_que.front().first);
    }
    
    return answer;
}
