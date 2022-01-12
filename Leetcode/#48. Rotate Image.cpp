// 출제의도: Implementation or Math(Matrix Operation), Time Complexity: O(n^2), Space Complexity: O(1). (n: matrix.size)
// naver, kakao에서 풀어본 유형. 다만 In-place를 요구했다는 점에서 보다 까다롭다.
// 처음 idea는 Rotation Matrix를 이용한 풀이인데, 구현가능하나 깔끔하지 않고 복잡한 측면으로 인해 다른 풀이를 고민.
// 다음 idea는 행렬 연산(transpose)을 이용한 90도 회전 구현.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
    
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void reverse(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n/2;j++) {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};
