// Sort, MergeSort , Time Complexity: O(nlgn+mlgm), Space Complexity: O(n+m) (n: nums1.size, m: nums2.size)
// facebook 기술면접 문제. 정렬된 두 배열이 주어질 경우, Mergesort의 idea를 이용하여 Space Complexity O(1)로 intersection을 구할 수 있음.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i1 = 0;
        int i2 = 0;
        
        while(i1<nums1.size() && i2<nums2.size()) {
            if(nums1[i1]<nums2[i2])    i1++;
            else if(nums1[i1]>nums2[i2])    i2++; 
            else {
                if(answer.empty() || answer.back()<nums1[i1]) answer.push_back(nums1[i1]);
                i1++;
                i2++;
            }
        }
        return answer;
    }
};
