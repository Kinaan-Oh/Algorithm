// "Brute Force", Time Complexity: O(n^5), Space Complexity: O(1). (n: max(row,col))

#include <iostream>
#include <vector>

using namespace std;

bool check(vector<vector<int>> &board,int x,int y,int sz) {
    for(int i=x;i<x+sz;i++) {
        for(int j=y;j<y+sz;j++) {
            if(!board[i][j])    return false;
        }
    }
    return true;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int row=board.size(), col=board[0].size();
    for(int sz=min(row,col);sz>=1;sz--) {
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(i+sz-1>=row || j+sz-1>=col)    continue;
                if(check(board,i,j,sz)) {
                    return sz*sz;
                }
            }
        }
    }
    return answer;
}
