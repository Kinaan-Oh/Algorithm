typedef pair<int,int>   Pos;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[6][6];

class Solution {
private:
    bool fnd=false;
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])    
                {
                    fill(&visited[0][0],&visited[0][0]+36,false);
                    visited[i][j]=true;
                    dfs(board,word,0,Pos(i,j));
                    if(fnd) return true;
                }
            }
        }
        return false;
    }
    
    void dfs(vector<vector<char>>& board, string &word, int cur, Pos pos)
    {
        if(cur==word.size()-1)  
        {
            fnd=true;
            return;
        }
        
        for(int i=0;i<4;i++)
        {
            Pos next = Pos(pos.first+dx[i], pos.second+dy[i]);
            if(isOutOfBound(board,next) || visited[next.first][next.second] || board[next.first][next.second]!=word[cur+1])  continue;
            
            visited[next.first][next.second]=true;
            dfs(board,word,cur+1,next);
            visited[next.first][next.second]=false;
        }
    }
    
    bool isOutOfBound(vector<vector<char>>& board, Pos pos)
    {
        if(pos.first<0 || pos.first>board.size()-1 || pos.second<0 || pos.second>board[0].size()-1)  return true;
        return false;
    }
};
