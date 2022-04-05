// BFS, Time Complexity: O(VE), Space Complexity: O(VE) (V: num of vertices, E: num of edges)
// 문제 실질적 출제의도

class Solution {
private:
    unordered_map<int,vector<pair<int,int>>> adjList; // node: (neighbor, weight)
    unordered_map<int,int> distance;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int answer = INT_MIN;
        
        for(auto time: times) {
            adjList[time[0]].push_back({time[1], time[2]});
        }
        for(int i=1;i<=n;i++) {
            distance[i] = INT_MAX;
        }
    
        bfs(k);
        
        for(int i=1;i<=n;i++) {
            if(distance[i] == INT_MAX)  return -1;
            answer = max(answer, distance[i]);
        }
        return answer;
    }
    
    void bfs(int k) {
        queue<pair<int,int>>  que; // node: distance
        
        distance[k] = 0;
        que.push({k, 0});
        
        while(!que.empty()) {
            pair<int,int> cur = que.front();
            que.pop();
            
            for(auto edge: adjList[cur.first]) {
                if(distance[cur.first] + edge.second<distance[edge.first]) {
                    distance[edge.first] = distance[cur.first] + edge.second;
                    que.push({edge.first, distance[edge.first]});
                }
            }
        }
    }
};
