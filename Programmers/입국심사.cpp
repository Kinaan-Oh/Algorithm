// 출제의도: "이분탐색", Time Complexity: O(lg(n*times의 최대값)).

#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long low=1 ,high=0;
    for(int i=0;i<times.size();i++) {
        if(high<times[i]*n) {
            high = times[i]*n;
        }
    }
    while(low<high) {
        long long mid = (low+high)/2;
        long long num = 0;
        for(int i=0;i<times.size();i++) {
            num += (mid/times[i]);
        }
        if(num<n)   low = mid+1;
        else    high = mid;
    }
    answer = high;
    return answer;
}
