// Dijkstra, Time Complexity: O(ElgV), Space Complexity: O(V+E) (V: num of vertices, E: num of edges)
// 논리: Within K Stops 조건으로 인해 Relaxation이 실패했지만, 더 적은 stop으로 도달한 경우 promising하다(Shortest Path Within K Stops을 만들어 낼 가능성이 있다) 간주.

typedef tuple<int,int,int>    ti; // (node, distance, stops)

class Solution {
private:
    unordered_map<int,vector<pair<int,int>>>  adjList;  // node: (neighbor, weight)
    unordered_map<int,int>  distance;
    unordered_map<int,int>  stops;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(auto flight: flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }
        for(int i=0;i<n;i++) {
            distance[i] = INT_MAX;
            stops[i] = INT_MAX;
        }
        return dijkstra(src, dst, k);
    }
    
    int dijkstra(int src, int dst, int k) {
        auto compare = [](ti &a, ti &b) {
            return get<1>(a)>get<1>(b);
        };
        priority_queue<ti, vector<ti>, decltype(compare)>  minHeap(compare);
        
        minHeap.push({src, 0, -1});
        
        while(!minHeap.empty()) {
            auto [cn, cd, cs] = minHeap.top(); // (currentNode, currentDist, CurrnetStops)
            minHeap.pop();
            
            if(cn==dst) return cd;
            if(cs==k)   continue;
            
            distance[cn] = cd;
            stops[cn] = cs;

            for(auto &[nn, w]: adjList[cn]) {
                if(cd+w<distance[nn] || cs+1<stops[nn]) {
                    minHeap.push({nn, cd+w, cs+1});
                } 
            }
        }
        return -1;
    }
};
