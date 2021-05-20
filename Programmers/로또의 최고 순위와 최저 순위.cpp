// 출제의도: "정렬" , Time Complexity: O(nlgn), Space Complexity: O(1) (n: lottos.size)

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<int,int>  to_rank;   // [num_of_match:rank]

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    for(int i=6;i>=0;i--) {
        to_rank[i] = i>1 ? 7-i : 6;
    }
    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(),win_nums.end());
    
    int num_of_unknown=0;
    int num_of_match=0;
    int left=0, right=win_nums.size();
    for(int i=0;i<lottos.size();i++) {
        if(lottos[i]==0) {
            num_of_unknown++;
            continue;
        }  
        else {
            for(;lottos[i]>=win_nums[left] && left<right;left++) {
                if(lottos[i]==win_nums[left]) {
                    num_of_match++;
                    break;
                }
            }
        }
    }
    answer = {to_rank[num_of_match+num_of_unknown], to_rank[num_of_match]};
    return answer;
}
