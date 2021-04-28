// TIme Complexity: O(NlgN+L)

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
