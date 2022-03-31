// Ad-Hoc(Negative Flagging/Sliding Window/Two-Pointer/Recursion), Time Complexity: O((RC)^2), Space Complexity: O(1) (R: rows of board, C: cols of board)
// 논리: 1) we crush the vertical row of a early, we may not see there was also a horizontal row. So, we need to "flag candy negative" on the board.
//      2) In gravity step, we could use a "two pointer approach", maintaining a read(rr) and write(rw) pointer. 
//         As the rw iterates through the column in reverse order, the rw will write it down and move one place.
//         Then, the rw will write zeroes to the remainder of the column.
// Kakao 기출.

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int R = board.size();
        int C = board[0].size();
        bool promising = false;
        
        for(int r=0;r<R;r++) {
            for(int c=0;c+2<C;c++) {
                int v = abs(board[r][c]);
                
                if(v>0 && v==abs(board[r][c+1]) && v==abs(board[r][c+2])) {
                    board[r][c] = board[r][c+1] = board[r][c+2] = -v;
                    promising = true;
                }
            }
        }
        
        for(int c=0;c<C;c++) {
            for(int r=0;r+2<R;r++) {
                int v = abs(board[r][c]);
                
                if(v>0 && v==abs(board[r+1][c]) && v==abs(board[r+2][c])) {
                    board[r][c] = board[r+1][c] = board[r+2][c] = -v;
                    promising = true;
                }
            }
        }
        
        for(int c=0;c<C;c++) {
            int rw = R-1; // rw: row-write pointer
            
            for(int rr=R-1;rr>=0;rr--) {    // rr: row-read pointer
                if(board[rr][c]>0) {
                    board[rw--][c] = board[rr][c];
                }
            }
            
            while(rw>=0) {
                board[rw--][c] = 0;
            }
        }
        
        return promising ? candyCrush(board) : board;
    }
};
