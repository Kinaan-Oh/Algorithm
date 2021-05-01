// Brute Force. Time Complexity: O(k*food_times.length).

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int next(vector<int> &food_times, int begin) {
    for(int i=0;i<food_times.size();i++) {
        int next = (begin+i)%food_times.size();
        if(food_times[next])    return next;
    }
    return -1;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int cur=-1;
    long long time=0; 
    while(time<=k) {
        cur = next(food_times,cur+1);
        if(cur==-1)    break;
        food_times[cur]--;
        time+=1;
    }
    if(cur==-1) answer=-1;
    else    answer = cur+1;
    return answer;
}
