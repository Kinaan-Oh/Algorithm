// 출제의도: DP/ Kadane's Algorithm, Time Complexity: O(n), Space Complexity: O(1) (n: nums.size)
// Kadane의 곱셈 버전
// 나의 풀이는 모범풀이와는 다른 풀이지만 효율성은 동일. 모범풀이는 생각해내기 매우 어렵다.
// 핵심 idea: 1) 0인 경우 유망하지 않아 새로운 contiguous subarray를 탐색 2) product<0 이고 다음 num>0 일때 새로운 contiguous subarray를 탐색하는 것이 최적일 수도 있다는 것.
// 2)의 경우, 역방향 탐색을 한번 더 해줌으로서 고려해줄 수 있다.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int answer = INT_MIN;
        int product = 1;
        
        for(int i=0;i<nums.size();i++) {
            if(product==0)  product=1;
            
            product *= nums[i];
            answer = max(answer, product);
        }
        
        product = 1;
        for(int i=nums.size()-1;i>=0;i--) {
            if(product==0)  product=1;
            
            product *= nums[i];
            answer = max(answer, product);
        }
        return answer;
    }
};
