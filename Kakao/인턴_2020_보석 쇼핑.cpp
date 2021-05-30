// 출제의도: "Sliding window", Time Complexity: O(n), Space Complexity: O(n). (n: gems.size)

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <iostream>

using namespace std;

int sz_of_window(vector<int> window) {
    if(!window.size())  return  INT_MAX;
    return window[1]-window[0]+1;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_set<string>   hash_set;
    int type_of_gems;
    for(int i=0;i<gems.size();i++) {
        hash_set.insert(gems[i]);
    }
    type_of_gems = hash_set.size();
    
    int left=0, right=0;    // window: [left,right]
    unordered_map<string,int>   num_of_gems;
    int type_in_window=1;
    num_of_gems[gems[left]]++;
    
    while(true) {
        if(type_in_window<type_of_gems) {
            if(right+1>=gems.size()) break;
            
            if(num_of_gems[gems[++right]]++==0) type_in_window++;
        }
        
        else if(type_in_window==type_of_gems) {
            if(sz_of_window({left,right})<sz_of_window(answer)) answer = {left+1,right+1};
                
            if(--num_of_gems[gems[left]]==0)  type_in_window--;
            left++;
        }
    }
    return answer;
}
