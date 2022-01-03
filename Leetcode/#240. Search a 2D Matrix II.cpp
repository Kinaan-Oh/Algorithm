// 출제의도: Binary Search, Time Complexity: O(mlgn), Space Complexity: O(lgn) (m: matrix.size, n:matrix[0].size)
// Sorted Array는 Binary Search에 대한 핵심 hint.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++) {
            if(b_search(matrix[i], 0, matrix[i].size(), target))    return true;
        }
        return false;
    }
    
    bool b_search(vector<int> &row, int begin, int end, int target) {
        if(begin>=end)  return false;
        
        int mid = (begin+end)/2;
        
        if(row[mid] == target) {
            return true;
        } else if(row[mid] < target) {
            return  b_search(row, mid+1, end, target);
        } else {
            return  b_search(row, begin, mid, target); 
        }
    }
};
