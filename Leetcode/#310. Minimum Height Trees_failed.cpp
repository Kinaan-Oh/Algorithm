// 시도: Depth Of Tree, Time Complexity: O(V^2), Space Complexity: O(V+E) (V: n, E: edges.size)
// 66 / 71 test cases passed Time Limit Exceeded

class Solution {
private:
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, vector<int>> nodes_of_height;
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int min_height = INT_MAX;
        init(edges);
        
        for(int i=0;i<n;i++) {
            int height = max_height(i, -1);
            nodes_of_height[height].push_back(i);
            min_height = min(min_height, height);
        }
        
        
        return nodes_of_height[min_height];
    }
    
    void init(vector<vector<int>>& edges) {
        for(auto edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
    }
    
    int max_height(int root, int prev) {
        int height = 0;
        
        for(auto neighbor: adjList[root]) {
            if(neighbor == prev)    continue;
            
            height = max(height, max_height(neighbor, root));
        }
        
        return height + 1;
    }
};
