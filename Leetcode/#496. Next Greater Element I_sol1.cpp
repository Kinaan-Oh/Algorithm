// Brute-Force, Time Complexity: O(n^2), Space Complexity: O(n) (n: nums2.size)
// 논리: 1) nums2 각 elem의 index를 Hash에 Memoize. 2) nums1 각 elem의 nums2상 index부터 탐색(pos 참고)하여 greater한 최초의 원소탐색.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>    answer;
        unordered_map<int, int>    pos;
        
        for(int i=0;i<nums2.size();i++) {
            pos[nums2[i]] = i;
        }
        for(auto num: nums1) {
            int greater = -1;
            
            for(int i=pos[num];i<nums2.size();i++) {
                if(num<nums2[i]) {
                    greater = nums2[i];
                    break;
                }
            }
            answer.push_back(greater);
        }
        return answer;
    }
};
