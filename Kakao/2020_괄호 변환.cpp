// 출제의도: "문제이해/ 구현()". 괄호 방향을 뒤집다를 순서를 뒤집다로 잘못 이해하여 오랜 시간이 걸림.

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool isCorrect(string p) {
    unordered_map<char,int> ht;
    for(int i=0;i<p.length();i++) {
        ht[p[i]]++;
        if(ht['(']<ht[')']) return false;
    }
    return true;
}

string turn(string u) {
    string turned;
    for(int i=0;i<u.length();i++) {
        turned += u[i]=='(' ? ")" : "(";
    }
    return turned;
}

string correct(string p) {
    if(p.length()==0)   return "";
    string u, v;
    unordered_map<char,int>   ht;
    for(int i=0;i<p.length();i++) {
        ht[p[i]]++;
        if(ht['(']==ht[')']) {
            u = p.substr(0,i+1);
            v = p.substr(i+1);
            break;
        }
    }
    if(isCorrect(u))    return u+correct(v);
    u = u.substr(1,u.length()-2);
    return "("+correct(v)+")"+turn(u);
}

string solution(string p) {
    string answer = "";
    answer = isCorrect(p) ? p : correct(p);
    return answer;
}
