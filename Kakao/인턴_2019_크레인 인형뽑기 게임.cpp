// 출제의도: "구현, 스택", Time Complexity: O(m*b), Space Complexity: O(m). (m: moves.size, b: board.size)

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    
    for(int i=0;i<moves.size();i++) {
        int select = moves[i]-1;
        for(int j=0;j<board.size();j++) {
            if(board[j][select]) {
                if(st.empty())  st.push(board[j][select]);
                else if(!st.empty() && st.top()==board[j][select]) {
                    st.pop();
                    answer += 2;
                }
                else {
                    st.push(board[j][select]);
                }
                
                board[j][select] = 0;
                break;
            }
        }
    }
    return answer;
}
