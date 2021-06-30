// 출제의도: "다익스트라", Time Complexity: O(ElgV), Space Complexity: O(V+E) (V: vertex 갯수, E: edge 갯수)
// 임의 한 정잠을 출발점으로 최단경로(weight of edge>=0) -> 다익스트라
// 우선순위 큐 자료구조를 이용하면 기존 Time Complexity O(V^2)를 O(ElgV)로 풀 수 있다. 0<=E<=V(V-1)/2 이므로 Dense Graph(edge 갯수가 V의 2차 다항식)가 아니라면 더 효율적이다.
// 또한, 문제 풀이에 있어 우선 순위 큐를 이용하는 방법이 구현이 쉽다는 장점이 있다.
// 우선 순위 큐를 사용하는 이유는 Greedy한 접근 때문이다. 즉, 이미 최단거리가 알려진 정점들의 집합 D이 있다고 할 때 집합 V-D(최단 거리가 알려져 있지 않은 정점의 집합)중 dist가 "최소"인 정점 A의 dist a는 
// 해당 정점까지의 최단거리가 된다. 그 이유는, dist a가 집합 D의 정점만을 경유하여 A까지 가는 경로길이인데, V-D의 정점을 경유하여 A까지 갈 경우 반드시 a보다 경로 길이가 같거나(정점 A까지 최단 경로가 여러개 인 
// 경우) 길어진다. 이는 V-D중 A를 제외한 정점의 dist는 a이상이기 때문이다. 따라서, 집합 V-D에서 dist가 최소인 정점을 Greedy하게 선택하고 이에 적합한 자료구조는 우선 순위 큐이다.

typedef pair<int,int>   Edge; // (neighbor, weight)

class Solution {
private:
    vector<Edge> adjList[101];  // 1~100
    int dist[101];    // 1~100
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) { 
        int dist_max = 0;
        for(int i=0;i<times.size();i++) {
            int u = times[i][0], v = times[i][1], weight = times[i][2];
            adjList[u].push_back({v,weight});
        }
        
        fill(&dist[0],&dist[0]+101,INT_MAX);
        dist[k] = 0;
        
        priority_queue<pair<int,int>>   pq; // (dist,node)
        pq.push({0,k});
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int distance = -pq.top().first;
            pq.pop();
            if(dist[node]<distance)    continue;
            
            for(int i=0;i<adjList[node].size();i++) {
                int neighbor = adjList[node][i].first, weight = adjList[node][i].second;
                
                if(dist[node]+weight<dist[neighbor]) {
                    dist[neighbor] = dist[node]+weight;
                    pq.push({-dist[neighbor],neighbor});
                }
            }
        }
        
        for(int i=1;i<=n;i++)   {
            if(dist[i]==INT_MAX)    return -1;
            dist_max = max(dist_max,dist[i]);
        }
        return dist_max;
    }
};
