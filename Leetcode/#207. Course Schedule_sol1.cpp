// 출제의도: Topological Sort, Time Complexity: O(V+E), Space Complexity: O(V+E).
// 전형적인 Topological Sort 유형.
// 논리적 오류는 cycle로 귀결된다. Topological Sort는 DAG 인 경우만 가능하다.


class Solution {
private:
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, int> inDegree;
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        init(prerequisites);
        
        int n=0;
        queue<int> que;
        
        for(int i=0;i<numCourses;i++) {
            if(inDegree[i] == 0) {
                que.push(i);
            }
        }
        
        while(!que.empty()) {
            int course = que.front();
            que.pop();
            n += 1;
            
            for(auto neighbor: adjList[course]) {
                if(--inDegree[neighbor] == 0) {
                    que.push(neighbor);
                }
            }
        }
        
        return n == numCourses;
    }
    
    void init(vector<vector<int>>& prerequisites) {
        for(auto elem: prerequisites) {
            adjList[elem[1]].push_back(elem[0]);
            inDegree[elem[0]] += 1;
        }
    }
};
