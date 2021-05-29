// 출제의도: "완전탐색, 순열/조합"
// user_id, banned_id 크기가 8이하로 매우 작으므로 완전탐색 가능.
// sol1과는 다르게 비트마스크를 이용하여 조합을 구현.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> get_selected_user_id(vector<string> &user_id, int select) {
    vector<string>  selected;
    int sz_user = user_id.size();
    for(int i=0;i<sz_user;i++) {
        if(select&(1<<i)) {
            selected.push_back(user_id[sz_user-1-i]);
        }
    }
    return selected;
}

bool match_id(string user_id, string banned_id) {
    if(user_id.length()!=banned_id.length())    return false;
    for(int i=0;i<user_id.length();i++) {
        if(isalpha(banned_id[i]) && user_id[i]!=banned_id[i])   return false;
    }
    return true;
}

bool match(vector<string> &user_id, vector<string> &banned_id) {
    int sz_user = user_id.size();
    for(int i=0;i<sz_user;i++) {
        if(!match_id(user_id[i],banned_id[i]))    return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int sz_user = user_id.size(), sz_banned = banned_id.size();
    for(int select=0;select<(1<<sz_user);select++) {
        vector<string>  selected = get_selected_user_id(user_id,select);
        
        if(selected.size()==sz_banned) {
            sort(selected.begin(),selected.end());
            do {
                if(match(selected,banned_id))   {
                    answer++;
                    break;
                }
            } while(next_permutation(selected.begin(),selected.end()));
        }
    }
    
    return answer;
}
