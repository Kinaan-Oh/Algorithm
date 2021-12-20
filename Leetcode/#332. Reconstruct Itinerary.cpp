// 출제의도: DFS in DAG
// 임의 한 edge(ticket)는 한번만 경유하는 것이 포인트.
// 인접리스트에서 경유중인 edge를 삭제하면 되지만, deque를 사용한다면 삭제/추가 time complexity를 O(1)으로 개선할 수 있음.
// 대체로 multiset/priority queue를 사용했지만 삭제/추가 time complexity는 O(lgn)으로 나의 구현보다 좋지 못함.
// 정답을 찾는 즉시 탐색을 종료해야 시간제한에 걸리지 않음.

class Solution {
private:
    unordered_map<string, deque<string>> adjList;
    vector<string> path;
    vector<string> answer;
    int num_of_edges;
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        init(tickets);
        dfs("JFK");
        
        return answer;
    }
    
    bool dfs(string node) {
        path.push_back(node);
        if(answer.empty() && path.size() == num_of_edges+1) {
            answer = path;
            return true;
        }
        
        int num_of_neighbors = adjList[node].size();
        bool ret = false;
        
        for(int i=0;i<num_of_neighbors;i++) {
            string next_node = adjList[node][i];
            adjList[node].erase(adjList[node].begin()+i);
            ret = dfs(next_node);
            if(ret) return ret;
            adjList[node].insert(adjList[node].begin()+i, next_node);
        }
        
        path.pop_back();
        return ret;
    }
    
    void init(vector<vector<string>>& tickets) {
        num_of_edges = tickets.size();
        sort(tickets.begin(), tickets.end());
        
        for(auto ticket: tickets) {
            adjList[ticket[0]].push_back(ticket[1]);
        }
    }
};
