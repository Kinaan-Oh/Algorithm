#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<int> s[9];  // index: 1~8

void makeSet(int i, int j)
{
    for(auto it_i=s[i].begin();it_i!=s[i].end();it_i++)
    {
        for(auto it_j=s[j].begin();it_j!=s[j].end();it_j++)
        {
            s[i+j].insert((*it_i) + (*it_j));
            s[i+j].insert((*it_i) - (*it_j));
            s[i+j].insert((*it_i) * (*it_j));
            if(*it_j)    s[i+j].insert((*it_i) / (*it_j));
        }
    }
}

int solution(int N, int number) {
    int answer = -1;
    int consecutiveN = N;
    s[1].insert(consecutiveN);
    for(int i=2;i<=8;i++)
    {
        consecutiveN = (consecutiveN*10)+N;
        for(int j=1;j<i;j++)    
        {
            s[i].insert(consecutiveN);
            makeSet(j,i-j);
        }
    }
    
    for(int i=1;i<=8;i++)   
    {
        if(s[i].find(number)!=s[i].end())   
        {
            answer=i;
            break;
        }
    }
    return answer;
}
