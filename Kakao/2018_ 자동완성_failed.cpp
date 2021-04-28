// Brute Force. Time Complexity: O(L^2)) ( 정확히는 O(L^2+(L-N)^2)) = O(L^2) )

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> words) {
    int answer = 0;
    for(int i=0;i<words.size();i++)
    {
        string search = words[i];
        for(int j=1;j<=search.length();j++)
        {
            string prefix = search.substr(0,j);
            bool found=false;
            for(int k=0;k<words.size();k++)
            {
                if(k==i)    continue;
                if(words[k].find(prefix)==0) {
                    found=true;
                    break;
                }
            }
            
            if(!found) {
                answer += prefix.length();
                break;
            }
            if(found && j==search.length()) {
                answer += search.length();
                break;
            }
        }
    }
    return answer;
}
