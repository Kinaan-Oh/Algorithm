// 출제의도: Centroid/Topological Sort Concept, Time Complexity: O(V+E), Space Complexity: O(E). (V: num of verticies, E: num of edged)
// Tree는 acyclic graph로 1~2개의 Centroid를 갖는다. 
// Centroid는 minimum height를 갖고, 이외 노드는 보다 큰 height를 갖게 된다.
// 따라서, 문제는 Centroid의 갯수를 구하는 문제로 변환된다.
// Centroid는 leaf 노드들을 반복적으로 제거하여 구할 수 있다. Topological Sort의 큐를 이용해 leafnode(indegree==1)를 반복적으로 찾는 개념을 적용할 수 있다.
// edge 제거 time complexity를 향상시키기위해 unordered_set으로 adjList를 정의했고, indegree를 따로 유지할 필요없다.(단순히 size를 이용하면 된다.)
// n==1인 경우를 예외처리해주어야 한다. 이 부분을 놓쳐 마지막 테스트케이스를 놓쳤던 것이 아쉽다.

class Solution {
private:
    unordered_map<int, unordered_set<int>> adjList;
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)    return {0};
        init(edges);
        
        vector<int> answer;
        queue<pair<int,int>>  que;  // (layer, node)
        int prev_layer = 0;
        
        for(int i=0;i<n;i++) {
            if(adjList[i].size() == 1)  que.push({1,i});
        }
        
        while(!que.empty()) {
            int layer = que.front().first;
            int node = que.front().second;
            que.pop();
            if(layer != prev_layer) {
                prev_layer = layer;
                answer.clear();
            }
            answer.push_back(node);
            
            if(adjList[node].begin() != adjList[node].end()) {
                int neighbor = *adjList[node].begin();
                adjList[node].erase(neighbor);
                adjList[neighbor].erase(node);

                if(adjList[neighbor].size() == 1)   que.push({layer+1,neighbor});
            }
        }
        
        return answer;
    }
    
    void init(vector<vector<int>>& edges) {
        for(auto edge: edges) {
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }
    }
};
