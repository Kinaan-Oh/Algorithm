// 출제의도: "그래프 탐색", Time Complexity: O(m*n), Space Complexity: O(m*n) (m: grid.size, n: grid[0].size)
// DFS 풀이.

typedef pair<int,int>   Pos;

class Solution {
private:
    bool visited[300][300];
    int m, n;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int numOfIslands = 0;    

public:
    int numIslands(vector<vector<char>>& grid) {
        fill(&visited[0][0], &visited[0][0]+300*300, false);
        m = grid.size(), n = grid[0].size();
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1' && !visited[i][j]) {
                    numOfIslands++;
                    dfs(grid,Pos(i,j));
                }
            }
        }
        return numOfIslands;
    }
    
    void dfs(vector<vector<char>>& grid, Pos cur) {
        visited[cur.first][cur.second] = true;
        
        for(int i=0;i<4;i++) {
            Pos next = Pos(cur.first+dx[i],cur.second+dy[i]);
            if(isOutOfBound(grid,next) || grid[next.first][next.second]!='1' || visited[next.first][next.second])   continue;
            
            dfs(grid, next);
        }
    }
    
    bool isOutOfBound(vector<vector<char>>& grid,Pos pos) {
        if(pos.first<0 || pos.first>=m || pos.second<0 || pos.second>=n)    return true;
        return false;
    }
};
