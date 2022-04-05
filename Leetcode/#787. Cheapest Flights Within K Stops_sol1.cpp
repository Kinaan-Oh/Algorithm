// BFS, Time Complexity: O(EK), Space Complexity: O(V^2+VK)
// 3가지 케이스 Prunning 필요. 1) dst에 도달한 경우 2) k번 경유한 경우 3) 현지점 이미 더 저렴한 비용으로 도달했던 경우

class Solution {
private:
    unordered_map<int,vector<pair<int,int>>>  adjList;  // node: (neighbor, weight)
    unordered_map<int,int>  distance;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(auto flight: flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }
        for(int i=0;i<n;i++) {
            distance[i] = INT_MAX;
        }
        return bfs(src, dst, k);
    }
    
    int bfs(int src, int dst, int k) {
        int answer = INT_MAX;
        queue<tuple<int,int,int>>    que; // (node, dist, stops)
        
        que.push({src, 0, -1});
        
        while(!que.empty()) {
            auto [cn, cd, cs] = que.front(); // (currentNode, currentDist, CurrnetStops)
            que.pop();
            
            if(cn==dst) {
                answer = min(answer, cd);
                continue;
            }
            if(cs==k || cd>=distance[cn])   continue;
            
            distance[cn] = cd;
            for(auto &[nn, w]: adjList[cn]) {
                que.push({nn, cd+w, cs+1});
            }
        }
        return answer==INT_MAX ? -1 : answer;
    }
};
