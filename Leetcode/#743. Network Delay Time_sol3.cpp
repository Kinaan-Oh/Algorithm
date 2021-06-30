// "벨만-포드", Time Complexity: O(VE), Space Complexity: O(V). (V: vertex 갯수, E: edge 갯수).
// 음의 사이클이 없는 그래프(다익스트라와 다르게 edge의 부호는 음수 일 수 있다.)에서 임의 한 정점에서 다른 정점으로의 최단거리를 구할 수 있다.
// 임의 한 정점으로부터 다른 정점으로의 최단 경로가 존재하기 위해서는 음의 사이클이 없어야 한다.(동일한 정점을 2번이상 방문해서는 안된다.) 따라서, 최단 경로는 최대 n개 정점을 경유할 수 있고 n-1개의 간선을 통과한다.
// 때문에 음의 사이클이 없다면 n-1번의 relaxation으로 최단 경로를 구할 수 있다. 만일 n번째의 relaxation시도에 relaxation이 성공한다면 이는 반드시 음의 사이클이 있음을 의미하고(동일한 정점을 2번 방문), 이
// 경우 음의 사이클에 포함된 정점들에 대한 최단 경로는 존재하지 않는다.

class Solution {
private:
    int dist[101];  // 1~100
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dist_max = 0;
        
        fill(&dist[0],&dist[0]+101,INT_MAX);
        dist[k] = 0;
        
        for(int i=0;i<n-1;i++) {
            for(int i=0;i<times.size();i++) {
                int u = times[i][0], v = times[i][1], weight = times[i][2];
                
                if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]) {
                    dist[v] = dist[u]+weight;
                }
            }
        }
      
       // check negative cycle
       for(int i=0;i<times.size();i++) {
                int u = times[i][0], v = times[i][1], weight = times[i][2];
                
                if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]) {
                    return -1;
                }
        }
        
        for(int i=1;i<=n;i++) {
            if(dist[i]==INT_MAX)    return -1;
            dist_max = max(dist_max, dist[i]);
        }
        return dist_max;
    }
};
