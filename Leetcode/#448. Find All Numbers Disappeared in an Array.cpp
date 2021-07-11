// Time Complexity: O(n), Space Complexity: O(1) (n: nums.size)
// hash를 이용하면 Time Compleity: O(n), Space Complexity: O(n)으로 간단히 해결가능하지만, Space Complexity O(1) 풀이가 출제의도.
// hash를 사용하여 방문여부를 표시하는 대신, - 부호를 이용하여 nums에 표시할 수 있다.
// 주의사항: nums에 -로 표시된 원소를 읽을 때는 절대값 abs(nums[i])를 취해야만 한다.(음수 인덱스로 참조하면 에러)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++) {
            int pos = abs(nums[i])-1;
            nums[pos] = -abs(nums[pos]);
        }
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>0)   ans.push_back(i+1);
        }
        return ans;
    }
};
