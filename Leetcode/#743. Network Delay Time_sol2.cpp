// "DFS", Time Complexity: O((V-1)!), Space Complexity: O(V+E) (V: vertex 갯수, E: edge 갯수)

typedef pair<int,int>   Edge;   // (weight,node)

class Solution {
private:
    int dist[101];  // 1~100
    bool visited[101];  // 1~100
    vector<Edge> adjList[101];   // 1~100
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dist_max = 0;
        fill(&dist[0],&dist[0]+101,INT_MAX);
        fill(&visited[0],&visited[0]+101,false);
        dist[k] = 0;
        
        for(int i=0;i<times.size();i++) {
            int u = times[i][0], v = times[i][1], weight = times[i][2];
            adjList[u].push_back({weight,v});
        }
        
        visited[k] = true;
        dfs(k, 0);
        
        for(int i=1;i<=n;i++) {
            if(dist[i]==INT_MAX)    return -1;
            dist_max = max(dist_max, dist[i]);
        }
        return dist_max;
    }
    
    void dfs(int node, int distance) {
        for(int i=0;i<adjList[node].size();i++) {
            int next_node = adjList[node][i].second, weight = adjList[node][i].first;
            
            if(!visited[next_node] && distance+weight<dist[next_node]) {
                dist[next_node] = distance+weight;
                visited[next_node] = true;
                dfs(next_node, dist[next_node]);
                visited[next_node] = false;
            }
        }
    }
};


// 2022/04/04 ReDo: if(distance[cur]<=sum)  return; 문을 통해 cycle 무한방문 방지.

class Solution {
private:
    unordered_map<int, vector<pair<int,int>>>   adjList; // node: (neighbor, val)
    unordered_map<int, int>   distance;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int answer = INT_MIN;
        
        for(auto time: times) {
            adjList[time[0]].push_back({time[1], time[2]});
        }
        
        auto compare = [](pair<int,int> &a, pair<int,int> &b) {
            return a.second<b.second;
        };
        for(int i=1;i<=n;i++) {
            distance[i] = INT_MAX;
            sort(adjList[i].begin(), adjList[i].end(), compare);
        }
        
        dfs(k, 0);
        
        for(int i=1;i<=n;i++) {
            if(distance[i]==INT_MAX)  return -1;
            answer = max(answer, distance[i]);
        }
        return answer;
    }
    
    void dfs(int cur, int sum) {
        if(distance[cur]<=sum)  return;
        distance[cur] = sum;
        
        for(auto edge: adjList[cur]) {
            dfs(edge.first, sum+edge.second);
        }
    }
};
