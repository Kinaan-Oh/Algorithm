// 자동완성_failed.cpp의 접두사 비교 반복을 O(N)에서 O(1)로 개선(접두사 기준 양옆만 검사해주면 됨.). Time Complexity: ?(구하지는 못하였음.) << O(L^2)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> words) {
    int answer = 0;
    sort(words.begin(),words.end());
    for(int i=0;i<words.size();i++)
    {
        string search = words[i];
        
        for(int j=1;j<=search.length();j++)
        {
            bool found=false;
            string prefix = search.substr(0,j);
            
            if(i>0 && words[i-1].find(prefix)==0)   found=true;
            if(i<words.size()-1 && words[i+1].find(prefix)==0)    found=true;
            
            if(!found) {
                answer += prefix.length();
                break;
            }
            if(found && j==search.length()) answer += search.length();
        }
    }
    return answer;
}
