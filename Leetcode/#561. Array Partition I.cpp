// 출제의도: Greedy, Time Complexity: O(nlgn), Space Complexity: O(1). (n: nums.size)
// idea: 임의 배열 최솟값은 2번째로 작은 수와 매칭되어야 한다. 이는 작은 수(이 경우 2번째로 작은 수)의 영향력을 최대한 줄이는 greedy한 선택.

// sort 대신 hashmap을 사용하여 2-pass time complexiy O(n)로도 풀 수 있다. 다만, Space Complexity는 O(n)으로 기존 풀이보다 좋지 못할 것.

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int answer = 0;
        
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i+=2) {
            answer += nums[i];
        }
        return answer;
    }
};
