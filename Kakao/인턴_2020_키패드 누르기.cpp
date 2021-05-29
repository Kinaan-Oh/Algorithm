// 출제의도: "구현, 맨허튼 거리"

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int manhattan_dist(int finger, int target) {
    return abs((finger-1)/3-(target-1)/3) + abs((finger-1)%3-(target-1)%3);
}

string move_finger_closer(int dist_left, int dist_right, string hand) {
    if(dist_left<dist_right)    return "L";
    else if(dist_left>dist_right)   return "R";
    else {
        if(hand=="left") return  "L";
        else    return "R";
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left=10, right=12;
    for(int i=0;i<numbers.size();i++) {
        if(!numbers[i])    numbers[i]=11;
        
        switch(numbers[i]%3) {
            case 0:
                right = numbers[i];
                answer += "R";
                break;
                
            case 1:
                left = numbers[i];
                answer += "L";
                break;
                
            case 2:
                int dist_left = manhattan_dist(left,numbers[i]);
                int dist_right = manhattan_dist(right,numbers[i]);
                answer += move_finger_closer(dist_left, dist_right, hand);
                if(answer.back()=='L') left = numbers[i];
                else    right = numbers[i];
                break;
        }
    }
    
    return answer;
}
