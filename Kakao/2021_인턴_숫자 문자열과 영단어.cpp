// HashTable/String, Time Complexity: O(l), Space Complexity: O(1) (l: s.length)

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void setString2Num(unordered_map<string, int> &string2num) {
    string2num["zero"] = 0;
    string2num["one"] = 1;
    string2num["two"] = 2;
    string2num["three"] = 3;
    string2num["four"] = 4;
    string2num["five"] = 5;
    string2num["six"] = 6;
    string2num["seven"] = 7;
    string2num["eight"] = 8;
    string2num["nine"] = 9;
}

int solution(string s) {
    int answer = 0;
    unordered_map<string, int> string2num;
    string tmp;
    
    setString2Num(string2num);
    
    for(auto c: s) {
        tmp += c;
        
        if(string2num.find(tmp) != string2num.end()) {
            answer = answer*10 + string2num[tmp];
            tmp.clear();
        } else if(isdigit(c)) {
            answer = answer*10 + stoi(tmp);
            tmp.clear();
        }
    }
    return answer;
}
