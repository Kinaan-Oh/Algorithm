// 출제 의도: "gcd, floor/ceil, long long 타입캐스팅". Time Complexity: O(lg(w+h)+w).

#include <iostream>
#include <cmath>

using namespace std;

//a>b
int gcd(int a, int b) { 
    if(b==0)    return a;
    return gcd(b,a%b);
}

long long solution(int w,int h) {
    long long answer = 1;
    int gcd_of_w_h = gcd(max(w,h),min(w,h));
    int unit_x = w/gcd_of_w_h;
    long long sum=0;
    for(int i=0;i<unit_x;i++) {
        int bottom = floor(((double)h/w)*i);
        int top = ceil(((double)h/w)*(i+1));
        sum += top-bottom;
    }
    answer = (long long)w*h-sum*gcd_of_w_h;
    return answer;
}
