// "이분탐색", Time Complexity: O(nlgn), Space Complexity: O(n). (n: stones.size)
// 1개씩 제거하지 않고 stone 크기만큼 제거하는 아이디어는 "무지의 먹방 라이브" 문제와 동일.
// 처음에는 stones의 크기가 작은 것에서 큰 순서대로 is_possible을 호출하여 구현하였으나 Time Complexity가 O(n^2)로 효율성을 통과하지 못함.
// is_possible이 false을 리턴하는 최초의 stone을 찾기 위해 "이분 탐색"을 사용하면 O(nlgn)으로 개선할 수 있음. 

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_possible(vector<int> &stones,int p,int k) {
    int consecutive_zero=0;
    int cnt=0;
    for(int i=0;i<stones.size();i++) {
        if(stones[i]<=p)   cnt++;
        else {
            consecutive_zero = max(consecutive_zero, cnt);
            cnt=0;
        }
    }
    consecutive_zero = max(consecutive_zero, cnt);
    return  consecutive_zero<k;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    vector<int> sorted = stones;
    sort(sorted.begin(),sorted.end());
    unique(sorted.begin(),sorted.end());
    
    int left=0, right=sorted.size()-1;
    while(left<right) {
        int mid = (left+right)/2;
        if(is_possible(stones,sorted[mid],k))   left = mid+1;
        else    right = mid;
    }
    answer = sorted[left];
    return answer;
}
