// Time Complextiy: O(LN)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int compare(vector<string> words, string word)
{
    int input=-1;
    for(int i=0;i<words.size();i++)
    {
        if(words[i]==word) continue;
        
        int overlap = min(word.length(),words[i].length());
        bool found=false;
        for(int j=0;j<overlap;j++)
        {
            if(word[j]!=words[i][j]) {
                found=true;
                input = max(input, j+1);
                break;
            }
        }
        if(!found) {
            int prefix = word.length()<=words[i].length() ? overlap : overlap+1;
            input = max(input, prefix);
        }
    }
    return input;
}

int solution(vector<string> words) {
    int answer = 0;
    for(int i=0;i<words.size();i++)
    {
        int input=-1;
        input = max(input, compare(words,words[i]));
        answer += input;
    }
    return answer;
}
