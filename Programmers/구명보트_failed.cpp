// 출제의도 : "greedy", Time Complexity: O(n^3), Space Complexity: O(1).
// 보트에 태울 수 있는 모든 조합을 따짐.

#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

bool get_people_aboard(vector<int> &people, int limit) {
    bool if_people_in_island = false;
    int max_boat_weight = INT_MIN;
    vector<int> passenger;
    
    for(int i=0;i<people.size();i++) {
        if(people[i]>limit)   continue;
        
        if_people_in_island = true;
        int boat_weight = people[i];
        if(boat_weight>max_boat_weight) {
            max_boat_weight = boat_weight;
            passenger = {i};
        }
            
        for(int j=i+1;j<people.size();j++) {
            if(boat_weight+people[j]>limit) continue;
            
            if(boat_weight+people[j]>max_boat_weight) {
                max_boat_weight = boat_weight+people[j];
                passenger = {i,j};
            }
        }
    }
    
    for(int i=0;i<passenger.size();i++) {
        people[passenger[i]] = limit+1;
    }
    return if_people_in_island;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    while(get_people_aboard(people,limit)) {
        answer++;
    }
    return answer;
}
