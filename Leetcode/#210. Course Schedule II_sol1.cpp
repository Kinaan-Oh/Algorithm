// 출제의도: Topological Sort, Time Complexity: O(V+E), Space Complexity: O(V+E) (V: num of vertices, E: num of edges)
// queue를 이용한 topological sort 방법.

class Solution {
private:
    unordered_map<int, vector<int>>  adjList;
    unordered_map<int, int> inDegree;    
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> answer;
        queue<int>  que;
        
        init(prerequisites);
        
        for(int i=0;i<numCourses;i++) {
            if(inDegree[i]==0)  que.push(i);
        }
        
        while(!que.empty()) {
            int course = que.front();
            que.pop();
            answer.push_back(course);
            
            for(auto neighbor: adjList[course]) {
                if(--inDegree[neighbor]==0)    que.push(neighbor);
            }
        }
        
        if(answer.size()!=numCourses)   answer.clear();
        return answer;
    }
    
    void init(vector<vector<int>>& prerequisites) {
        for(auto edge: prerequisites) {
           adjList[edge[1]].push_back(edge[0]);
           inDegree[edge[0]] += 1;
        }
    }
};
