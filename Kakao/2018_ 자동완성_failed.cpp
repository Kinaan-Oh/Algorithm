// Brute Force. Time Complexity: O(L^2)) (search.substr(0,j)를 고려하여 시간 복잡도 구하는 것이 어려웠음. j가 외부 for문에 종속이라 N-1차 함수의 최대값을 구하는 문제로 변환되지만, 나는 
// 풀지 못하였음. search.substr(0,j)의 최대값을 L-N으로 잡을 수 있지만, 이 경우 너무 높은 경계를 잡게되어 O(L^2)이 됨.)

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
