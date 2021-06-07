// 출제의도: "Back Track"
// promising 검사(pruning)로 효율성 향상.(안하면 Time Complexity는 O(n^n))

#include <string>
#include <vector>

using namespace std;

bool board[12][12];

bool promising(int n,int row,int col) {
    for(int i=1;i<=row;i++) {
        if(board[i-1][col])   return false;
        if(row-i>=0 && col-i>=0 && board[row-i][col-i]) return false;
        if(row-i>=0 && col+i<n && board[row-i][col+i]) return false;
    }
    return true;
}

void backtrack(int &answer,int n,int no_of_queen) {    // no_of_queen: 0 ~ n-1
    if(no_of_queen==n)    answer++;
    
    for(int i=0;i<n;i++) {
        if(!promising(n,no_of_queen,i))    continue;
        
        board[no_of_queen][i]=true;
        backtrack(answer,n,no_of_queen+1);
        board[no_of_queen][i]=false;
    }
}

int solution(int n) {
    int answer = 0;
    backtrack(answer,n,0);
    return answer;
}
