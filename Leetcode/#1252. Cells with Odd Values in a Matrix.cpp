// Math/Bitwise Operation, Time Complexity: O(m+n+l), Space Complexity: O(1) (l: indices.size)
// 논리: 홀수 항 = 홀수 행*열의 갯수 + 짝수 행*행의 갯수 - 2*홀수 행*짝수 행
// 각 홀수/짝수 행은 xor 연산자를 이용해 memoize.

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        long long row = 0;
        long long col = 0;
        int rowOdd = 0;
        int colOdd = 0;
        
        for(auto index: indices) {
            row^=((long long)1<<index[0]);
            col^=((long long)1<<index[1]);
        }
        for(int i=0;i<max(m,n);i++) {
            if(row&((long long)1<<i))    rowOdd+=1;
            if(col&((long long)1<<i))   colOdd+=1;    
        }
        return rowOdd*n + colOdd*m - 2*rowOdd*colOdd;
    }
};
