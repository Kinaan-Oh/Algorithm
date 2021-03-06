// 정렬(NlgN)을 이용하여 018_ 자동완성_failed.cpp의 반복비교(O(N))을 양옆 비교(O(1))로 개선. TIme Complexity: O(NlgN+L), Space Complexity: O(1)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int compare(string word1, string word2)
{
    int overlap = min(word1.length(), word2.length());
    for(int i=0;i<overlap;i++)
    {
        if(word1[i]!=word2[i])  return (i+1);
    }
    return word1.length()<=word2.length() ? overlap : overlap+1;
}

int solution(vector<string> words) {
    int answer = 0;
    sort(words.begin(),words.end());
    for(int i=0;i<words.size();i++)
    {
        int input=-1;
        if(i>0) input = max(input, compare(words[i],words[i-1]));
        if(i<words.size()-1)    input = max(input, compare(words[i],words[i+1]));
        answer += input;
    }
    return answer;
}
