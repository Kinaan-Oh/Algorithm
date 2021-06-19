// N사 코테 2번 문제와 동일. 현장에서 이 방법으로 풀이함.
// "Brute Force", Time Complexity: O(n), Space Complexity: O(1). (n: height.size)
// idea: 직전 높이와 같거나 큰 높이를 만나게 될 때까지 빗물은 고인다.
// 왼쪽에서 오른쪽으로, 오른쪽에서 왼쪽으로 2번 탐색.
// 2 0 2 케이스를 처리하기 위해 높이가 같은 경우는 2번의 탐색 중 하나만 처리하도록 해야 함.

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int prev = 0;
        int sum=0;
        for(int i=0;i<height.size();i++) {
            if(height[prev]<=height[i]) {
                prev = i;
                ans += sum;
                sum = 0;
                continue;
            }
            
            sum += (height[prev]-height[i]);
        }
        
        prev = height.size()-1;
        sum = 0;
        for(int i=height.size()-1;i>=0;i--) {
            if(height[prev]<height[i]) {
                prev = i;
                ans += sum;
                sum = 0;
                continue;
            }
            
            sum += (height[prev]-height[i]);
        }
        
        return ans;
    }
};
