//  출제의도: "해시, 경우의수", Time Complexity: O(clothes.size), Space Complexity: O(clothes.size).

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string,int>   ht; // [type:index]
int type_of_clothes[30];    // idx: 1~30

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int num_of_type=1;
    for(int i=0;i<clothes.size();i++) {
        if(ht[clothes[i][1]]==0) {
            ht[clothes[i][1]] = num_of_type++; 
        }
        type_of_clothes[ht[clothes[i][1]]]++;
    }
    for(int i=1;i<num_of_type;i++) {
        answer *= (type_of_clothes[i]+1);
    }
    answer -= 1; 
    return answer;
}
