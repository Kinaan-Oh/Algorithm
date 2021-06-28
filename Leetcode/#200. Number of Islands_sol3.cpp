// "Union-Find", Time Complexity: O(mnlg*(mn)), Space Complexity: O(mn). (m: grid.size, n: grid[0].size, log*: log star)
// Union-Find(Union By Height/Path Compression)을 이용. lg*는 상수시간에 가깝다. 따라서, 실제 성능을 비교한 결과 bfs/dfs(O(m*n))와 거의 차이가 없었다.

ttypedef pair<int,int>   Pos;

class Solution {
private:
    Pos parent[300][300];
    int height[300][300];
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        init(grid);
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    if(i-1>=0 && grid[i-1][j]=='1')    union_by_height(Pos(i-1,j),Pos(i,j));
                    if(j-1>=0 && grid[i][j-1]=='1')    union_by_height(Pos(i,j-1),Pos(i,j)); 
                }
            }
        }
        
        return numOfIslands();
    }
    
    void init(vector<vector<char>>& grid) {
        fill(&height[0][0],&height[0][0]+300*300,0);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1')    parent[i][j] = Pos(i,j);
                else    parent[i][j] = Pos(-1,-1);
            }
        }
    }
    
    void union_by_height(Pos prev, Pos cur) {
        Pos u = find(prev), v = find(cur);
        if(height[u.first][u.second]>height[v.first][v.second]) {
            parent[v.first][v.second] = u;
            
        }
        else if(height[u.first][u.second]<height[v.first][v.second])    {
            parent[u.first][u.second] = v;    
        }
        else {
            parent[u.first][u.second] = v; 
            height[v.first][v.second]++;
        }
    }
    
    Pos find(Pos cur) {
        if(parent[cur.first][cur.second]==cur)  return cur;
        return parent[cur.first][cur.second] = find(parent[cur.first][cur.second]);
    }
    
    int numOfIslands() {
        int num = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(parent[i][j] == Pos(i,j))    num++;
            }
        }
        return num;
    }
};
