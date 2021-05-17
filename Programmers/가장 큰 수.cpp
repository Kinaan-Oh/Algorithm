//  출제의도: "정렬", Time Complexity: O(nlgn)(n:numbers.length)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string num1, string num2) {
    return num1+num2>num2+num1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>  numbers_string;
    for(int i=0;i<numbers.size();i++) {
        numbers_string.push_back(to_string(numbers[i]));
    }
    sort(numbers_string.begin(),numbers_string.end(),compare);
    for(int i=0;i<numbers_string.size();i++)    answer += numbers_string[i];
    if(answer[0]=='0')  answer = "0";
    return answer;
}
