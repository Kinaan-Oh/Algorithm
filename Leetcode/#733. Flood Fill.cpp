// DFS, Time Complexity: O(mn), Space Complexity: O(1) (m: image.size, n: image[0].size)
// image의 값을 newColor로 set 해줌으로서 visited 배열을 따로 유지할 필요 없음.

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor)   dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        image[r][c] = newColor;
        if(r-1>=0 && image[r-1][c]==oldColor)  dfs(image, r-1, c, oldColor, newColor);
        if(r+1<image.size() && image[r+1][c]==oldColor)    dfs(image, r+1, c, oldColor, newColor);
        if(c-1>=0 && image[r][c-1]==oldColor)  dfs(image, r, c-1, oldColor, newColor);
        if(c+1<image[0].size() && image[r][c+1]==oldColor)    dfs(image, r, c+1, oldColor, newColor);
    }
};
