// "Two-Pointer", Time Complexity: O(n^2), Space Complexity: O(n^2) (n: nums.size)
// 3Sum 문제를 2Sum 문제로 분할하여 접근. 2Sum 문제는 Hash를 사용하는 방법, 정렬 후 Two-Pointer를 사용하는 방법있는데 후자를 택함.(정렬은 nlgn이 걸리지만 best cast time complexity는 n^2이므로
// 영향을 주지 않음.)
// 주의할 사항은, 중복 원소들이 포함되어 있고 해가 유일하지 않다는 점이다. 따라서, 2Sum을 풀때 반드시 중복 해를 제거하고, 서로 다른 여러 해를 구해야만 한다. 이에 대한 처리는 해를 발견 했을 때, left와 right
// 를 동시에 이동시켜주고 left를 직전 값과 다른 값이 될 때까지 이동시켜준다.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size() && nums[i]<=0;i++) {
            if(i==0 || nums[i-1]<nums[i]) {
                twoSum(nums, i, ans);
            }
        }
        return ans;
    }
    
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& ans) {
        int left = i+1, right = nums.size()-1;
        while(left<right) {
            if(nums[left] + nums[right] + nums[i] < 0)  left++;
            else if(nums[left] + nums[right] + nums[i] > 0)    right--;
            else {
                ans.push_back({nums[i], nums[left++], nums[right--]});
                while(left<right && nums[left]==nums[left-1]) {
                    left++;
                }
            }
        }    
    }
};

// 2022/04/03 ReDo

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size() && nums[i]<=0;i++) {
            if(i==0 || nums[i]!=nums[i-1]) {
                twoSum(nums, answer, i+1, -nums[i]);
            }
        }
        return answer;
    }
    
    void twoSum(vector<int>& nums, vector<vector<int>> &answer, int s, int target) {
        int p1 = s;
        int p2 = nums.size()-1;
        
        while(p1<p2) {
            int sum = nums[p1] + nums[p2];
            
            if(sum<target) {
                p1 += 1;
            } else if(sum>target) {
                p2 -= 1;
            } else {
                answer.push_back({-target, nums[p1], nums[p2]});
                p1 += 1;
                while(p1<p2 && nums[p1]==nums[p1-1]) {
                    p1 += 1;
                }
            }
        }
    }
};
