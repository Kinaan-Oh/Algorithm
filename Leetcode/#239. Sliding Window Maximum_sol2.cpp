// "Monotone Queue", Time Complexity: O(n), Space Complexity: O(n). (n: nums.size)
// 큐를 단조 감소 상태로 유지. 즉, 새로 삽입할 원소보다 영향력이 작거나 같은 윈도우 내 원소들을 제거 후 삽입을 반복.
// 1) 삽입할 원소보다 작거나 같은 원소들을 큐의 뒤에서부터 제거.
// 2) 원소 삽입
// 3) 윈도우에 포함되지 않게 된 원소를 큐의 앞에서부터 제거.
// 4) 큐의 가장 앞 원소가 윈도우의 최대값.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<pair<int,int>>  monotone_que; // (idx,value)
        
        for(int i=0;i<nums.size();i++) {
            while(!monotone_que.empty() && monotone_que.back().second<=nums[i]) {
                monotone_que.pop_back();
            }
            monotone_que.push_back({i,nums[i]});
            if(!monotone_que.empty() && i-monotone_que.front().first+1>k) {
                monotone_que.pop_front();
            }
            
            if(i>=k-1)  ans.push_back(monotone_que.front().second);
        }
        
        return ans;
    }
};
