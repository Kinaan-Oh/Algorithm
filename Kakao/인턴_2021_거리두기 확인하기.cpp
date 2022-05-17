// Implementation, Time Complexity: O((mn)^2) ~= O(1), Space Complexity: O(mn) ~= O(1) (m: place.size(5), n:place[0].size(5))
// m, n이 5로 매우 작기때문에 Brute Force가 출제의도.

#include <string>
#include <vector>

using namespace std;

int distance(pair<int,int> p1, pair<int,int> p2) {
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto place: places) {
        vector<pair<int,int>> people;
        bool result = true;
        
        for(int i=0;i<place.size();i++) {
            for(int j=0;j<place[0].size();j++) {
                if(place[i][j]=='P') {
                    people.push_back({i, j});
                }
            }
        }
        
        for(int i=0;i<people.size();i++) {
            for(int j=i+1;j<people.size();j++) {
                if(distance(people[i], people[j])==1) {
                    result = false;
                    break;
                } else if(distance(people[i], people[j])==2) {
                    if(people[i].first==people[j].first &&
                       place[people[i].first][people[i].second+1]=='O') {
                        result = false;
                        break;
                    } else if(people[i].second==people[j].second &&
                              place[people[i].first+1][people[i].second]=='O') {
                        result = false;
                        break;
                    } else if((people[i].first+1==people[j].first && 
                               people[i].second+1==people[j].second) &&
                              (place[people[i].first][people[j].second]=='O' || 
                               place[people[j].first][people[i].second]=='O')) {
                        result = false;
                        break;
                    } else if((people[i].first+1==people[j].first && 
                               people[i].second-1==people[j].second) &&
                              (place[people[i].first][people[j].second]=='O' || 
                               place[people[j].first][people[i].second]=='O')) {
                        result = false;
                        break;
                    } 
                }
            }
        }
        
        answer.push_back(result ? 1 : 0);
    }
    return answer;
}
