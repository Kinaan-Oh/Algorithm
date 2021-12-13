// 출제의도: Heap, Time Complexity: O(NlgK), Space Complexity: O(N+k). ( k<=N )
// 전형적인 custum compare heap 문제.

class Solution {
private:
    unordered_map<int,int> count;
    vector<int> answer;
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++) {
            count[nums[i]] += 1;
        }
        
        auto compare = [&](int e1,int e2) { return count[e1] > count[e2]; };
        priority_queue<int, vector<int>, decltype(compare)> pq(compare);
        
        for(pair<int,int> p: count) {
            pq.push(p.first);
            
            if(pq.size()>k) pq.pop();
        }
        
        while(!pq.empty()) {
            answer.push_back(pq.top());
            pq.pop();
        }
        
        return answer;
    }
};
