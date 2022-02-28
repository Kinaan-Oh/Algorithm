// Sort/Two-Pointer, Time Complexty: O(mlgm+nlgn), Space Complexity: O(m+n)
// unordered_set을 이용하는 방법이 효율성 측면에서 우월하지만, 학습차원에서 two pointer로 해결.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        int p1 = 0;
        int p2 = 0;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while(p1<nums1.size() && p2<nums2.size()) {
            if(nums1[p1]==nums2[p2]) {
                answer.push_back(nums1[p1]);
                p1 += 1;
                p2 += 1;
            } else if(nums1[p1]<nums2[p2]) {
                p1 += 1;
            } else {
                p2 += 1;
            }
        }
        return answer;
    }
};
