// Math, Time Complexity: O(n), Space Complexity: O(n)
// 논리: 1) n이 짝수이면, -n/2 -n/2+1 ... n/2-1 n/2 로 구축 가능. 2) n이 홀수이면, 짝수와 동일한 방법으로 0을 형성하는 짝수 원소(양/음수)에 0을 포함하여 생성가능.

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> answer;
        
        if(n%2) answer.push_back(0);
        n/=2;
        for(int i=1;i<=n;i++) {
            answer.push_back(i);
            answer.push_back(-i);
        }
        return answer;
    }
};
