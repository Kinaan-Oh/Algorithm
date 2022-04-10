// monotone queue, Time Complexity: O(n), Space Complexity: O(n)
// 논리: 1) P(n): index 0~n prefix sum 일때, P(y)-P(x)>=k (x<y)를 만족하는 x중 max(y-x) 즉, max(x)를 구하는 문제.
//      2) P(y)-P(x1)>=k를 만족해도 x1<x2인 P(x1)>=P(x2)인 x2가 존재한다면 x1는 non promising 하다.
//      3) P(y)-P(x)>=k 를 만족하는 모든 x는 다음 문제(P(y+1)-P(x')>=k) non promising 하다.
// * prefixSum 첫번째 원소를 0로 추가적으로 유지하고(일반적 prefix sum 문제에서 그렇듯이), monotone queue에 push해주어야 index 1 원소를 고려할 수 있다.

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int answer = INT_MAX;
        vector<long long> prefixSum(n+1, 0);
        deque<int>  que; // idx
        
        for(int i=0;i<n;i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
       
        for(int y=0;y<=n;y++) {
            while(!que.empty() && prefixSum[y]-prefixSum[que.front()]>=k) {
                answer = min(answer, y-que.front());
                que.pop_front();
            }
            
            while(!que.empty() && prefixSum[que.back()]>=prefixSum[y]) {
                que.pop_back();
            }
            que.push_back(y);
        }
        return answer==INT_MAX ? -1 : answer;
    }
};
