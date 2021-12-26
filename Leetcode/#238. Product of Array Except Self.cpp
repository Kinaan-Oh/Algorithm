// 출제의도: Prefix Sum, Time Complexity: O(n), Space Complexity: O(n). (n: nums.size)
// 처음에는 divide를 이용한 Time Complexity O(n) 풀이를 accept 받았지만, divide 사용금지 조건을 뒤늦게 확인.
// BruteForce한 O(n^2) 풀이를 떠올렸고, 곱셈 연산의 반복이 병목임을 파악. (1*2*3*4를 한 뒤 1*2*3*4*5를 할 경우 1*2*3*4를 반복하게 되는 비효율)
// a1*..*an, an*..*aL(L:마지막)을 memoize 하는 Prefix Sum 기법을 이용하면, 각 곱셈 반복을 1회로 줄일 수 있음.
// left, right를 따로 들고 있지않아도, answer 1개 만으로 풀수 있음. 이는 Space Complexity를 O(1)로 개선할 수 있음.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        vector<int> left;
        vector<int> right;
        int product = 1;
        
        for(auto num: nums) {
            product *= num;
            left.push_back(product);
        }
        
        product = 1;
        reverse(nums.begin(), nums.end());
        for(auto num: nums) {
            product *= num;
            right.push_back(product);
        }
        reverse(right.begin(), right.end());
        
        for(int i=0;i<nums.size();i++) {
            int product = 1;
            product *= i-1>=0 ? left[i-1] : 1;
            product *= i+1<nums.size() ? right[i+1] : 1;
            answer.push_back(product);
        }
        
        return answer;
    }
};
