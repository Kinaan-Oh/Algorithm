// "플로이드 워셜", Time Complexity: O(V^3), Space Complexity: O(V^2).
// 모든 정점 사이의 최단 거리를 구하는 알고리즘. 
// 경유할 수 있는 정점들의 집합을 1~k번이라 할 때, k:1->n 순으로 문제 크기를 확장해 나가면서 모든 정점 사이의 최단 거리를 구한다.
// 최종적으로 k: n에서 1~n번 정점을 경유할 때의 모든 정점 사이의 최단거리를 구하게 된다. dist 배열은 엄밀히 말해 3차원 배열 dist[k][i][j]이 필요하지만, 슬라이딩 윈도우 기법을 이용하여 공간 복잡도를
// O(V^3)에서 O(V^2)으로 최적화 할 수 있다. 이는 dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]) 에서 dist[i][k] = dist[i][k], dist[k][j] = dist[k][j]로 k번째 행과 열의
// 정보를 손상하지 않고 dist를 업데이트 하기 때문에 가능하다.
// Time Complexity는 O(V^3)으로 큰 편이지만, 실제 실행시간은 다익스트라(O(ElgV))와 벨만포드 SPFA(O(VE),A(E))와 비슷하거나 약간 느렸다. Dense한 그래프(edge의 갯수가 V의 2차 다항식)인 경우,
// 다익스트라는 O(V^2lgV), 벨만포드 SPFA는 O(V^3),A(V^2)으로 성능이 떨어지기 때문에 해당 테스트 케이스에서는 비슷한 성능을 보였다.

class Solution {
private:
    int dist[101][101];    // 1_100
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dist_max = 0;
        fill(&dist[0][0], &dist[0][0]+101*101, INT_MAX/3);
        
        for(int i=0;i<times.size();i++) {
            int u = times[i][0], v = times[i][1], weight = times[i][2];
            dist[u][v] = weight;
        }
        for(int i=1;i<=n;i++)   dist[i][i] = 0;
        
        for(int k=1;k<=n;k++) {
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        
        for(int i=1;i<=n;i++) {
            if(dist[k][i]==INT_MAX/3)   return -1;
            dist_max = max(dist_max, dist[k][i]);
        }
        return dist_max;
    }
};
