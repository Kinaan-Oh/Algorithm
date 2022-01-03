// 출제의도: HashSet, Time Complexity: O(n+m), Space Complexity: O(n+m) (n: nums1.size, m: nums2.size)

class Solution {
private:
    unordered_set<int>  set;
    
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        unordered_set<int> nums2_set(nums2.begin(), nums2.end());
        
        for(auto elem: nums1)   set.insert(elem);
        for(auto elem: nums2_set) {
            if(set.find(elem) != set.end()) {
                answer.push_back(elem);
            }
        }
        return answer;
    }
};
