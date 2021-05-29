// Time Complexity: O(n), Space Complexity: O(n). (n: s.length)

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> parse(string s) {
    vector<int> parsed;
    int front=0;
    for(int i=0;i<s.size();i++) {
         if(s[i]==',') {
             parsed.push_back(stoi(s.substr(front,i)));
             front = i+1;
         }
    }
    parsed.push_back(stoi(s.substr(front)));
    return parsed;
}

bool compare(vector<int> v1, vector<int> v2) {
    return v1.size()<v2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int,bool> visited;
    vector<vector<int>> subsets;
    s = s.substr(1,s.length()-2);
    int front, end;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='{')   front = i;
        else if(s[i]=='}') {
            end = i;
            subsets.push_back(parse(s.substr(front+1,end-front-1)));
        }
    }
  
    sort(subsets.begin(),subsets.end(),compare);
    for(int i=0;i<subsets.size();i++) {
        for(int j=0;j<subsets[i].size();j++) {
            if(!visited[subsets[i][j]]) {
                answer.push_back(subsets[i][j]);
                visited[subsets[i][j]] = true;
            }
        }
    }
    return answer;
}
