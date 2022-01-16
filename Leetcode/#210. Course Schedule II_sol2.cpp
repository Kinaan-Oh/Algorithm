// DFS/Cycle/DP, Time Complexity: O(V+E), Space Complexity: O(V+E) (V: num of vertices, E: num of edges)
// visited를 3가지 상태로 정의. 1:unexplored는 call stack에 있는 상태를 의미, 2:explored는 call stack에 있다가 pop된 상태를 의미.
// dfs는 root->child 순 탐색이기 때문에 explored 상태로 전환과 동시에 answer에 push 해주어야 함. 최종 answer는 reverse한 값이 됨.
// adjList를 root->child 방향으로 구성하지 않고 역방향으로 구성한다면, reverse 생략 가능.

class Solution {
private:
    unordered_map<int, vector<int>>  adjList;
    unordered_map<int, int> visited;    // 0:unvisited 1:unexplored 2:explored
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> answer;
        
        init(prerequisites);
        
        for(int i=0;i<numCourses;i++) {
            if(visited[i]!=2 && is_cyclic(answer, i))    return {};
        }
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
    
    void init(vector<vector<int>>& prerequisites) {
        for(auto edge: prerequisites) {
            adjList[edge[1]].push_back(edge[0]);
        }
    }
    
    bool is_cyclic(vector<int> &answer, int node) {
        if(visited[node]==1)   return true;
        if(visited[node]==2)   return false;
        
        visited[node] = 1;
        bool ret = false;
        
        for(auto neighbor: adjList[node]) {
            ret = is_cyclic(answer, neighbor);
            if(ret) break;
        }
        
        visited[node] = 2;
        answer.push_back(node);
        return ret;
    }
};
