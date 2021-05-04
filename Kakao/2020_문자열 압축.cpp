// 출제의도: "문자열/구현", Time Complexity: O(s.length^2).

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int compress(string s, int sz) {
    string compressed;
    int front=0;
    int cnt;
    vector<string>  slices;
    for(int i=0;i<s.size()/sz+1;i++) {
        string slice = s.substr(sz*i,sz);
        if(slice.size()>0)    slices.push_back(slice);
    }
    for(int i=0;i<slices.size();i++) { 
        if(slices[front]!=slices[i]) {
            cnt = i-front;
            if(cnt>1)   compressed+= (to_string(cnt)+slices[front]);
            else compressed+=slices[front];
            front = i;
        }
    }
    cnt = slices.size()-front;
    if(cnt>1)   compressed+= (to_string(cnt)+slices[front]);
    else compressed+=slices[front];
    return compressed.length();
}

int solution(string s) {
    int answer = 1001;
    for(int i=1;i<=s.size();i++) {
        answer = min(answer,compress(s,i));
    }
    return answer;
}
