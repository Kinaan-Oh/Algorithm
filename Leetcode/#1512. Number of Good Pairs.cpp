// Math(Combination)/Hash Table, Time Complexity: O(n), Space Complexity: O(n) (n: nums.size)
// nC2 = (n)*(n-1)/2

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int answer = 0;
        unordered_map<int, int> ht;
        
        for(auto num: nums) {
            ht[num] += 1;
        }
        for(auto elem: ht) {
            if(elem.second>1) {
                answer += (elem.second)*(elem.second-1)/2;
            }
        }
        return answer;
    }
};
