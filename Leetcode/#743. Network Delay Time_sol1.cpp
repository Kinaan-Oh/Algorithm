// 출제의도: "다익스트라", Time Complexity: O(ElgV), Space Complexity: O(V+E) (V: vertex 갯수, E: edge 갯수)
// 임의 한 정잠을 출발점으로 최단경로(weight of edge>=0) -> 다익스트라
// 우선순위 큐 자료구조를 이용하면 기존 Time Complexity O(V^2)를 O(ElgV)로 풀 수 있다. 0<=E<=V(V-1)/2 이므로 Dense Graph(edge 갯수가 V의 2차 다항식)가 아니라면 더 효율적이다.
// 또한, 문제 풀이에 있어 우선 순위 큐를 이용하는 방법이 구현이 쉽다는 장점이 있다.

// 우선 순위 큐를 사용하는 이유는 Greedy한 접근 때문이다. 즉, 이미 최단거리가 알려진 정점들의 집합 D이 있다고 할 때 집합 V-D(최단 거리가 알려져 있지 않은 정점의 집합)중 dist가 "최소"인 정점 A의 dist a는 
// 해당 정점까지의 최단거리가 된다. 그 이유는, dist a가 집합 D의 정점만을 경유하여 A까지 가는 경로길이인데, V-D의 정점을 경유하여 A까지 갈 경우 반드시 a보다 경로 길이가 같거나(정점 A까지 최단 경로가 여러개 인 
// 경우) 길어진다. 이는 V-D중 A를 제외한 정점의 dist는 a이상이기 때문이다. 따라서, 집합 V-D에서 dist가 최소인 정점을 Greedy하게 선택하고 이에 적합한 자료구조는 우선 순위 큐이다.

// 다익스트라는 edge의 weight가 0상인 경우에만 사용할 수 있는 데, weight가 음수라면 위의 논리가 성립할 수 없다.(Greedy한 접근 불가) 쉽게 생각하면 집합 V-D(최단 거리가 알려져 있지 않은 정점의 집합) 중 
// dist가 "최소"인 정점 A를 집합 V-D의 노드 B를 경유하여 도달한다고 가정하자. D를 경유한 B까지의 경로길이를 dist b라 힐때, B를 경유한 A까지의 경로 길이는 b + edge(B,A)이다. b>=a 이고 edge(B,A)>=0
// 이면 dist b >= dist a가 보장되지만, edge(B,A)<0 이면 dist b >= dist a가 보장되지 않는다. 오히려 더 짧아 질 수 있는 것이다.

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



// 2022/04/04 ReDo

class Solution {
private: 
    unordered_map<int, vector<pair<int,int>>>   adjList;        
    unordered_map<int, int>   distance;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int answer = INT_MIN;
        
        for(auto time: times) {
            adjList[time[0]].push_back({time[1], time[2]}); // node: (neighbor, weight)
        }
        for(int i=1;i<=n;i++) {
            distance[i] = INT_MAX;
        }
        
        dijkstra(n, k);
        
        for(int i=1;i<=n;i++) {
            if(distance[i] == INT_MAX)  return -1;
            answer = max(answer, distance[i]);
        }
        return answer;
    }
    
    void dijkstra(int n, int k) {
        auto compare = [](pair<int,int> &a, pair<int,int> &b) {
            return a.second>b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(compare)>   minHeap(compare); // (node, distance)
        
        distance[k] = 0;
        minHeap.push({k, 0});
        
        while(!minHeap.empty()) {
            pair<int,int>   cur = minHeap.top();
            minHeap.pop();
            if(distance[cur.first]<cur.second)  continue;
            
            for(auto edge: adjList[cur.first]) {
                if(distance[cur.first]+edge.second<distance[edge.first]) {
                    distance[edge.first] = distance[cur.first]+edge.second;
                    minHeap.push({edge.first, distance[edge.first]});
                }
            }
        }
    }
};
