// "Boyer Moore Voting 알고리즘", Time Complexity: O(n), Space Complexity: O(1).
// Space Complexity가 O(1)로 sol1 보다 우수.
// 배열에 포함된 과반수에 해당하는 원소를 효율적으로 탐색하기 위해 설계된 알고리즘. 과반수에 해당하는 원소가 없을 경우, 무의미한 랜덤한 값을 리턴한다.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            if(sum==0) {
                candidate = nums[i];
            }
            
            sum += (nums[i]==candidate ? 1 : -1);
        }
        
        return candidate;
    }
};
