// Floyd's Tortoise/Hare, Time Complexity: O(n), Space Complexity: O(1) (n: nums.size)
// 이 문제의 특수상황을 고려하여 배열을 리스트로 볼 수 있는 idea가 필요.
// 중복값을 갖는 수는 1개라는 조건 때문에 nums 배열을 사이클을 갖는 리스트로 볼 수 있음. (중복값이 없다면 사이클이 없는 singly linked list)
// 따라서 사이클의 시작점을 찾는 문제로 변환. 이는 전형적인 Floyd 문제에 속함.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate;
        int walker = 0;
        int runner = 0;
        
        do {
            walker = nums[walker];
            runner = nums[nums[runner]];
        } while(walker != runner);
        
        walker = 0;
        do {
            walker = nums[walker];
            runner = nums[runner];
        } while(walker != runner);
        
        return walker;
    }
};
