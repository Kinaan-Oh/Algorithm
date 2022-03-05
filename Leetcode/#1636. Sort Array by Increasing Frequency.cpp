// Sort, Time Complexity: O(nlgn), Space Complexity: O(n) (n: nums.size)

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>    freq;
        
        for(auto num: nums) {
            freq[num] += 1;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return freq[a] == freq[b] ? a > b : freq[a] < freq[b];
        });
        return nums;
    }
};
