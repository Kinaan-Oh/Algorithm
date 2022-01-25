// 출제의도: Binary Search, Time Complexity: O(lgmn), Space Complexity: O(1) (m: matrix.size, n:matrix[0].size)
// sol1과 성능은 사실상 동일. 하지만, 각 행의 마지막 원소의 크기는 다음 행의 첫번째 원소크기 보다 작다 는 조건을 활용하여 보다 깔끔한 코드를 작성할 수 있음.
// idea: 언급한 문제조건을 고려하면 2차원배원을 정렬된 1차원배열로 간주할 수 있음. 따라서, 각 sol1처럼 행, 열에 대하여 binary search를 독립적으로 시행할 필요가 없기 때문에 깔끔해짐.
// 아주 아름답고 깔끔한 문제 ...

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int begin = 0;
        int end = m*n;
        
        while(begin<end) {
            int cur = (begin+end)/2;
            int row = cur/n;
            int col = cur%n;
            
            if(matrix[row][col]<target)    begin = cur+1;
            else if(matrix[row][col]>target)    end = cur;
            else    return true;
        }
        return false;
    }
};
