// "Prefix Sum", Time Complexity: O()n^2, Space Complexity: O(n).

#include <string>
#include <vector>

using namespace std;

int sum[10000]; // sum[i]: 1~i까지 합
// i~j까지 합: sum[j]-sum[i-1]

int solution(int n) {
    int answer = 1;
    for(int i=1;i<=n;i++)   sum[i] = sum[i-1] + i;
    
    for(int sz=2;sz<=n;sz++) {
        for(int i=1;i+sz-1<=n;i++) {
            if(sum[i+sz-1]-sum[i-1]>n)  break;
            
            if(sum[i+sz-1]-sum[i-1]==n) {
                answer ++;
            }
        }
    }
    return answer;
}
