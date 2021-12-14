// DFS with Prunning, Time Complexity: O(V+E), Space Complexity: O(V+E).
// DFS를 이용한 풀이. 오히려 Topological Sort보다 훨씬 어렵게 체감.

// DFS 과정에서 현 call stack에 포함된 node를 재방문하게 되면 cycle 형성으로 판단.
// 위 논리만으로도 accept를 받을 수 있지만, 각 노드에 대해 isCyclic를 중복 호출하게 되는 비효율로 Time Complexity : O(V^2+E)로 좋지 않은 성능을 보임.
// visited 를 유지하여 Time Complexty: O(V+E)로 개선. 이는 Topological Sort와 동등한 성능.
// 결론 : DFS 풀이 방법은 생각하기 어렵고 예외(cycle 판단)를 고려하기 어려울 수 있다는 점에서 Topological Sort에 비해 난이도가 높고 시간 리소스를 많이 사용하는 방법.

class Solution {
private:
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> path;
    unordered_map<int, bool> visited;
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        init(prerequisites);
        
        for(int i=0;i<numCourses;i++) {
            if(isCyclic(i)) {
                return false;
            }
        }
        return true;
    }
    
    bool isCyclic(int node) {
        if(path.find(node) != path.end())   return true;
        if(visited[node])   return false;
        
        path.insert(node);
        bool ret = false;
        
        for(auto neighbor: adjList[node]) {
            ret = isCyclic(neighbor);
            
            if(ret) break;    
        }
        
        path.erase(node);
        visited[node] = true;
        return ret;
    }
    
    void init(vector<vector<int>>& prerequisites) {
        for(auto elem: prerequisites) {
            adjList[elem[1]].push_back(elem[0]);
        }
    }
};
