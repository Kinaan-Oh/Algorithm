

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Check(int m, int n, vector<string> &board)
{
    int cnt=0;
    vector<vector<bool>> check(m,vector<bool>(n,false));
    
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(isalpha(board[i][j]) && board[i][j]==board[i+1][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i+1][j+1])
            {
                check[i][j] = check[i][j+1] = check[i+1][j] = check[i+1][j+1] = true;
            }
        }
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(check[i][j])  
            {
                board[i][j] = '!';
                cnt++;
            }
        }
    }
    return cnt;
}

void trickleDown(int m, int n, vector<string> &board, int col)
{
    for(int i=m-1;i>=0;i--)
    {
        if(board[i][col]=='!' && i>0)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(isalpha(board[j][col]))  
                {
                    swap(board[i][col],board[j][col]);
                    break;
                }
            }
        }
    }
}

int Pop(int m, int n, vector<string> &board)
{
    int cnt = Check(m,n,board);
    for(int j=0;j<n;j++)
    {
        trickleDown(m,n,board,j);
    }
    return cnt;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int cnt=0;
    
    while(cnt=Pop(m,n,board))
    {
        answer += cnt;
    }
    
    return answer;
}
