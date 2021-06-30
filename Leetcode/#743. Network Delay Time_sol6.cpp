// "다익스트라", Time Complexity: O(ElgV), Space Complexity: O(E+V). (V: vertex의 갯수, E: edge의 갯수)
// sol1과 다르게 1) heap 자료구조 대신 balanced bst(binary search tree) 자료구조 set 선택. 2) 해시 테이블(unordered_map)을 이용한 인접 리스트 구현.
// 1)의 경우 heap의 pop이 O(lgV)만큼 걸리는 반면, bst의 erase는 Amortized O(1)이 걸린다는 장점이 있다. 또한, heap의 경우 중복 삽입 문제로 비효율적인 반면, set은 자동으로 중복을 제거한다.
// 2)의 경우 vector을 이용한 구현은 key가 Int가 아닌 경우(예를 들면 문자열) 처리가 번거로운 반면, 해시 테이블을 이용하면 처리가 간단해지고 성능은 동일하다.
// 결론: "set"과 "hash table"을 이용한 다익스트라 구현은 구현 난이도/성능 등 모든 면에서 sol1보다 우월하다.


class Solution {
private:
    int dist[101];  // 1~100
    unordered_map<int, vector<pair<int,int>>>  adjList;  // (weight, neighbor)
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dist_max = 0;
        fill(&dist[0],&dist[0]+101,INT_MAX);
        for(int i=0;i<times.size();i++) {
            int u = times[i][0], v = times[i][1], weight = times[i][2];
            adjList[u].push_back({weight,v});
        }
        
        set<pair<int,int>>  set;    // (dist, node)
        dist[k] = 0;
        set.insert({0,k});
        
        while(!set.empty()) {
            auto cur = set.begin();
            int distance = (*cur).first;
            int node = (*cur).second;
            set.erase(cur);
            
            for(int i=0;i<adjList[node].size();i++) {
                int neighbor = adjList[node][i].second, weight = adjList[node][i].first;
                
                if(dist[node]+weight<dist[neighbor]) {
                    dist[neighbor] = dist[node]+weight;
                    set.insert({dist[neighbor], neighbor});
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
