// 출제의도: "다중집합 교집합/합집합 정의"

#include <string>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(),str1.end(),str1.begin(),::tolower);
    transform(str2.begin(),str2.end(),str2.begin(),::tolower);
    
    vector<string>  A, B;
    for(int i=0;i<str1.size();i++) {
        string elem = str1.substr(i,2);
        if(isalpha(elem[0])&&isalpha(elem[1]))  A.push_back(elem);
    }
    for(int i=0;i<str2.size();i++) {
        string elem = str2.substr(i,2);
        if(isalpha(elem[0])&&isalpha(elem[1]))  B.push_back(elem);
    }
    
    unordered_map<string,int>   ht_A, ht_B;
    set<string> elem_in_A_or_B;
    for(int i=0;i<A.size();i++) {
        ht_A[A[i]]++;
        elem_in_A_or_B.insert(A[i]);
    }
    for(int i=0;i<B.size();i++) {
        ht_B[B[i]]++;
        elem_in_A_or_B.insert(B[i]);
    }
    if(A.size()==0&&B.size()==0)    return 65536;
    
    int numerator=0, denominator=0;
    for(auto it=elem_in_A_or_B.begin();it!=elem_in_A_or_B.end();it++) {
        numerator += min(ht_A[*it],ht_B[*it]);
        denominator += max(ht_A[*it],ht_B[*it]);
    }
    
    answer = ((double)numerator/denominator)*65536;
    return answer;
}
