// Stack, Time Complexity: O(n), Space Complexity: O(n) (n: nums2.size, nums1 is subset of nums2)
// 논리: 1) num2 각 elem에 대하여 next greater elem을 탐색 및 memoize.
//      1-1) typical한 monotone decreasing stack 기법 적용. -> stack의 elem은 next greater elem을 만나면 pop.
//      2) nums1에 대해 memoize된 next greater을 순서대로 answer에 추가.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>    answer;
        unordered_map<int, int>  nextGreater;  
        stack<int>  stack;
        
        for(auto num: nums2) {
            while(!stack.empty() && stack.top()<num) {
                nextGreater[stack.top()] = num;
                stack.pop();
            }
            stack.push(num);
        }
        while(!stack.empty()) {
            nextGreater[stack.top()] = -1;
            stack.pop();
        }
        
        for(auto num: nums1) {
            answer.push_back(nextGreater[num]);
        }
        return answer;
    }
};
