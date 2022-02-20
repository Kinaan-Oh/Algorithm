// DFS, Time Complexity: O(mn), Space Complexity: O(mn) (m: grid.size, n: grid[0].size)
// 첫번째 시도인 Iteration을 이용한 Brute-Force 풀이가 DFS 풀이보다 간결하고 좋은 풀이지만, dfs 학습차원에서 시도.

class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool visited[100][100];
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        fill(&visited[0][0], &visited[99][99]+1, false);
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]) {
                    visited[i][j] = true;
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int perimeter = 4;
        
        for(int i=0;i<4;i++) {
            int nextX = r+dx[i];
            int nextY = c+dy[i];
            
            if(isInBound(grid, nextX, nextY) && grid[nextX][nextY]) {
                perimeter -= 1;

                if(!visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    perimeter += dfs(grid, nextX, nextY);
                }
            }       
        }
        return perimeter;
    }
    
    bool isInBound(vector<vector<int>>& grid, int r, int c) {
        return r>=0 && c>=0 && r<grid.size() && c<grid[0].size();
    }
};
