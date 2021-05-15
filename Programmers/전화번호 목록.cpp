// 출제의도: "트라이 or 정렬 or 해시테이블". Time Complexity: O(L), L: phone_book의 모든 문자열 길이의 합.
// 트라이-> Time Complexity: O(L), 정렬-> Time Complexity: O(NlgN+L)

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,bool>  ht;
    for(int i=0;i<phone_book.size();i++)    ht[phone_book[i]]=true;
    for(int i=0;i<phone_book.size();i++) {
        string phone_number;
        for(int j=0;j<phone_book[i].size();j++) {
            phone_number += phone_book[i][j];
            
            if(ht[phone_number] && phone_number!=phone_book[i]) {
                answer = false;
                break;
            }
        }
    }
    return answer;
}
