// String, Time Complexity: O(l), Space Complexity: O(l) (l: new_id.length)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string stage1(string s) {
    string result = s;
    
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string stage2(string s) {
    string result;
    
    for(auto c: s) {
        if(isalpha(c) || isdigit(c) || c=='-' || c=='_' || c=='.') {
            result += c;
        }
    }
    return result;
}

string stage3(string s) {
    string result;
    
    for(int i=0;i<s.size()-1;i++) {
        if(s[i]=='.' && s[i]==s[i+1]) {
            continue;
        }
        result += s[i];
    }
    result += s.back();
    return result;
}

string stage4(string s) {
    string result;
    
    for(int i=0;i<s.size();i++) {
        if(i==0 && s[i]=='.')  continue;
        else if(i==s.size()-1 && s[i]=='.')   continue;
        result += s[i];
    }
    return result;
}

string stage5(string s) {
    string result = s;
    
    if(s.empty())  result = "a";
    return result;
}

string stage6(string s) {
    string result = s;
    
    if(s.length()>=16) {
        result = result.substr(0,15);
        if(result.back()=='.')  result.pop_back();
    }
    return result;
}

string stage7(string s) {
    string result = s;
    
    if(s.length()>0 && s.length()<=2) {
        while(result.length()<3) {
            result += s.back();
        }
    }
    return result;
}

string solution(string new_id) {
    string answer = "";
    
    new_id = stage1(new_id);
    new_id = stage2(new_id);
    new_id = stage3(new_id);
    new_id = stage4(new_id);
    new_id = stage5(new_id);
    new_id = stage6(new_id);
    answer = stage7(new_id);
    return answer;
}
