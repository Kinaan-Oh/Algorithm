// Binary Search, Time Complexity: O(lgm+lgn), Space Complexity: O(1). (m: matrix.size, n:matrix[0].size)
// 주어진 matrix는 정렬된 상태라는 조건에 의해 Binary Search를 고려할 수 있음. Brute-Force 풀이 time complexity O(mn)를 O(lgm+lgn)로 개선.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int begin = 0;
        int end = matrix.size();
        
        while(begin<end) {
            int cur = (begin+end)/2;
            
            if(matrix[cur][0]<=target)   begin = cur+1;
            else    end = cur;
        }
        int row = end-1;
        if(row<0)   return false;
        begin = 0;
        end = matrix[0].size();
        
        while(begin<end) {
            int cur = (begin+end)/2;
            
            if(matrix[row][cur]<=target)   begin = cur+1;
            else    end = cur;
        }
        int col = end-1;
        if(col<0)   return false;
        
        return matrix[row][col] == target;
    }
};
