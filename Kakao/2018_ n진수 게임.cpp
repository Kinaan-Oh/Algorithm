#include <string>
#include <vector>
#include <iostream>

using namespace std;

string encode[6] = {"A","B","C","D","E","F"};

string getNextNumber(int num, int radix)
{
    if(num==0)  return "0"; 
    string number;
    while(num!=0)
    {
        if(num%radix<10)    number = to_string(num%radix) + number;
        else    number = encode[num%radix-10] + number;    
        num /= radix;
    }
    return number;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string number;
    int num=0;
    while(number.size()<m*t)
    {
        number += getNextNumber(num++,n);
    }
    for(int i=0;i<t;i++)    answer += number[m*i+(p-1)];
    return answer;
}
