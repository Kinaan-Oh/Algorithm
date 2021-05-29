// 출제의도: "완전탐색, 순열/조합"
// user_id, banned_id 크기가 8이하로 매우 작으므로 완전탐색 가능.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool match_str(string user, string banned) {
    if(user.size()!=banned.size())  return false;
    
    for(int i=0;i<user.size();i++) {
        if(isalpha(banned[i]) && user[i]!=banned[i])    return false;
    }
    return true;
}

bool match(vector<string> user, vector<string> banned) {
    sort(user.begin(),user.end());
    do {
        bool is_match=true;
        for(int i=0;i<user.size();i++) {
            if(!match_str(user[i],banned[i])) {
                is_match=false;
                break;
            }
        }
        if(is_match)    return true;
    } while(next_permutation(user.begin(),user.end()));
    
    return false;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int sz_user = user_id.size(), sz_banned = banned_id.size();
    vector<int> select = vector<int>(sz_user-sz_banned,0);
    for(int i=0;i<sz_banned;i++)    select.push_back(1);
    
    do {
        vector<string> selected;
        for(int i=0;i<sz_user;i++) {
            if(select[i])   selected.push_back(user_id[i]);
        }
        if(match(selected,banned_id))   answer++;
    } while(next_permutation(select.begin(),select.end()));
    
    return answer;
}
