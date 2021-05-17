// Floyd-Warshall. Time Complexity: O(n^3+m), Space Complexity: O(n^2).

#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int dist[101][101]; // idx: 1~100

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    fill(&dist[0][0],&dist[0][0]+101*101,INT_MAX/2);
    for(int i=0;i<results.size();i++) {
        dist[results[i][0]][results[i][1]]=1;
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(dist[i][k]==1&&dist[k][j]==1) {
                    dist[i][j] = 1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) {
        int num_of_relation=0;
        for(int j=1;j<=n;j++) {
            if(dist[i][j]==1)   num_of_relation++;
            if(dist[j][i]==1)   num_of_relation++;
        }
        answer = num_of_relation==n-1 ? answer+1 : answer;
    }
    
    return answer;
}
