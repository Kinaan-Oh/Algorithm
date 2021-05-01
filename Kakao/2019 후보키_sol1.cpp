#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> &superkey1, vector<int> &superkey2) {
    return superkey1.size()<superkey2.size();
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size(), col = relation[0].size();
    vector<vector<int>> superkeys;
    for(int comb=1;comb<(1<<col);comb++) {
        set<string>  tuples;  
        vector<int> selectedAttributes;
        bool select=true;
        for(int i=0;i<row;i++) {
            string tuple;
            for(int j=0;j<col;j++) {
                if(comb&(1<<j)) {
                    tuple += (" "+relation[i][j]);
                    if(select)  selectedAttributes.push_back(j);
                }
            }
            select=false;
            tuples.insert(tuple);
        }
        if(tuples.size()==row)  superkeys.push_back(selectedAttributes);
    }
    sort(superkeys.begin(),superkeys.end(),compare);
    for(int i=0;i<superkeys.size();i++) {
        bool isCandidateKey = true;
        for(int j=0;j<superkeys.size();j++) {
            if(j==i)    continue;
            if(includes(superkeys[i].begin(),superkeys[i].end(),superkeys[j].begin(),superkeys[j].end())) {
                isCandidateKey = false;
                break;
            } 
        }
        if(isCandidateKey)  answer++;
    }
    return answer;
}
