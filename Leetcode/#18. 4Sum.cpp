// Two-Pointer/BackTrack, Time Complexity: O(n^3), Space Complexity: O(n) (n: nums.size)
// 논리: 1) kSum으로 일반화. 2) 3Sum과 동일한 논리로 kSum 문제는 k-1Sum 문제로 분할됨. 4) 각 부분문제를 해결하기 전에 유망성 판단 후 prunning.((avg>=nums[start]) && (avg<=nums.back()) -> promising)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, 4, 0, target);
    }
    
    vector<vector<int>> kSum(vector<int>& nums, int k, int start, int target) {
        vector<vector<int>> ret;
        
        if (start == nums.size()) {
            return ret;
        }
        
        int avg = target/k;
        bool promising = (avg>=nums[start]) && (avg<=nums.back());
        
        if(!promising) {
            return ret;
        }
        
        if(k==2) {
            return twoSum(nums, start, target);
        }
        
        for(int i=start;i<nums.size();i++) {
            if(i==start || nums[i]!=nums[i-1]) {
                for(auto subset: kSum(nums, k-1, i+1, target-nums[i])) {
                    ret.push_back({nums[i]});
                    ret.back().insert(end(ret.back()), begin(subset), end(subset));
                }
            }
        }
        return ret;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> ret;
        int p1 = start;
        int p2 = nums.size()-1;
        
        while(p1<p2) {
            int sum = nums[p1] + nums[p2];
            
            if(sum<target) {
                p1 += 1;
            } else if(sum>target) {
                p2 -= 1;
            } else {
                ret.push_back({nums[p1], nums[p2]});
                p1 += 1;
                while(p1<p2 && nums[p1]==nums[p1-1]) {
                    p1 += 1;
                }
            }
        }
        return ret;
    }
};
