// "다익스트라", Time Complexity: O(ElgV), Space Complexity: O(E+V). (V: vertex의 갯수, E: edge의 갯수)
// sol1과 다르게 1) heap 자료구조 대신 balanced bst(binary search tree) 자료구조 set 선택. 2) 해시 테이블(unordered_map)을 이용한 인접 리스트 구현.
// 1)의 경우 heap의 pop이 O(lgV)만큼 걸리는 반면, bst의 erase는 Amortized O(1)이 걸린다는 장점이 있다. 또한, heap의 경우 중복 삽입 문제로 비효율적인 반면, set은 자동으로 중복을 제거한다.
// 2)의 경우 vector을 이용한 구현은 key가 Int가 아닌 경우(예를 들면 문자열) 처리가 번거로운 반면, 해시 테이블을 이용하면 처리가 간단해지고 성능은 동일하다.
// 결론: "set"과 "hash table"을 이용한 다익스트라 구현은 구현 난이도/성능 등 모든 면에서 sol1보다 우월하다.

// 12/21 Refactor: 좀더 간결하게 개선. vector 대신 deq으로 변경.(이 문제에서는 vector로도 충분하지만, 그래프 문제에서 deq 시간개선측면에서 유리한 경우가 많음)

class Solution {
private:
    int dist[101];
    int answer;
    unordered_map<int, deque<pair<int, int>>> adjList;  //  (neighbor, weight)
    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        init(times);
        
        set<pair<int, int>> bst;    // (dist, node)
        bst.insert({0, k});
        
        while(!bst.empty()) {
            auto begin = bst.begin();
            int distance = (*begin).first; int node = (*begin).second;
            bst.erase(begin);
            
            if(dist[node]!=INT_MAX)    continue;
            dist[node] = distance;
            
            for(auto edge: adjList[node]) {
                bst.insert({distance+edge.second, edge.first});
            }
        }
        
        for(int i=1;i<=n;i++) {
            if(dist[i]==INT_MAX)    return -1;
            answer = max(answer, dist[i]);
        }
        return answer;
    }
    
    void init(vector<vector<int>>& times) {
        fill(dist, dist+101, INT_MAX);
        answer = 0;
        
        for(auto time: times) {
            adjList[time[0]].push_back({time[1], time[2]});
        }
    }
};
