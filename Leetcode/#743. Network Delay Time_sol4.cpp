// "벨만-포드 SPFA", Time Complexity: O(VE), A(E), Space Complexity: O(V+E).
// 기존 벨만 포드 알고리즘의 경우 모든 edge의 relaxation을 고정적으로 n-1번 반복.(최대 n-1개 edge를 경로에 포함)
// SPFA는 relaxation된 정점을 기준으로 다음에 relaxation 할 정점들을 결정.
// 음의 사이클은 임의 한 정점이 n번이상 큐에 삽입되면 형성된 것으로 판단. 이는 근본적으로 기존 벨만포드 알고리즘이 n번째 반복 때 relaxation이 되면 음의 사이클이 형성된 것으로 판단하는 것과 동일한 논리.
// SPFA의 평균 시간 복잡도는 O(E). 따라서, 최단 경로 문제에 있어 다익스트라(O(ElgV))보다 좋은 경우가 더러 있음. 실제 제출한 실행시간은 다익스트라와 비슷한 수준으로 더 우월하지는 않았음.

class Solution {
private:
    int dist[101];  // 1~100
    unordered_map<int, vector<pair<int,int>>>  adjList;  // (weight, neighbor)
    bool isInQueue[101];
    int numOfRelaxation[101];
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dist_max = 0;
        
        fill(&dist[0],&dist[0]+101,INT_MAX);
        fill(&isInQueue[0],&isInQueue[0]+101,false);
        fill(&numOfRelaxation[0],&numOfRelaxation[0]+101,0);
        
        for(int i=0;i<times.size();i++) {
            int u = times[i][0], v = times[i][1], weight = times[i][2];
            
            adjList[u].push_back({weight,v});
        }
        
        queue<int> que;
        dist[k] = 0;
        isInQueue[k] = true;
        que.push(k);
        
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            isInQueue[node] = false;
            
            for(int i=0;i<adjList[node].size();i++) {
                int neighbor = adjList[node][i].second, weight = adjList[node][i].first;
                
                if(dist[node]+weight<dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;

                    if(!isInQueue[neighbor]) {
                        if(++numOfRelaxation[neighbor]>=n)     return -1;
                        isInQueue[neighbor] = true;
                        que.push(neighbor);
                    }
                }
            }
        }
        
        for(int i=1;i<=n;i++) {
            if(dist[i]==INT_MAX)    return -1;
            dist_max = max(dist_max, dist[i]);
        }
        return dist_max;
    }
};
