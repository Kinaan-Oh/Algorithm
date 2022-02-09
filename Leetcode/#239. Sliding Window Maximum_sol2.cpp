// "Monotone Queue", Time Complexity: O(n), Space Complexity: O(n). (n: nums.size)
// 2019 카카오 인턴 징검다리 문제와 동일. (idx,value) pair로 관리했었으나, 단순히 idx로 관리하는 방법으로 개선.(더 간단)
// 큐를 단조 감소 상태로 유지. 즉, 새로 삽입할 원소보다 영향력이 작거나 같은 윈도우 내 원소들을 제거 후 삽입을 반복.
// 1) 삽입할 원소보다 작거나 같은 원소들을 큐의 뒤에서부터 제거.
// 2) 원소 삽입
// 3) 윈도우에 포함되지 않게 된 원소를 큐의 앞에서부터 제거.
// 4) 큐의 가장 앞 원소가 윈도우의 최대값.

// 2022/02/09 ReDo: 동일한 방법으로 풀이. monotone decrease 상태로 원소들을 유지하여, 1) 구간내의 Maximum을 O(1)에 접근하고 2) maximum을 O(1)로 pop하기 위해
// deque 자료구조 선택(front()에서 접근가능하고 pop_front()의 timecomplexity는 O(1)).

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int>  monotone_que; // idx
        
        for(int i=0;i<nums.size();i++) {
            while(!monotone_que.empty() && nums[monotone_que.back()]<=nums[i]) {
                monotone_que.pop_back();
            }
            monotone_que.push_back(i);
            if(i-monotone_que.front()+1>k) {
                monotone_que.pop_front();
            }
            
            if(i>=k-1)  ans.push_back(nums[monotone_que.front()]);
        }
        
        return ans;
    }
};
