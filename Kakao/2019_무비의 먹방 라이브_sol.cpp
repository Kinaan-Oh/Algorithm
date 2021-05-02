// [문제 풀이 논리]
// (Idea) food_times를 순회하면서 1씩 감소시키는 것(Brute Force: O(k*food_times.length))보다 food_times 원소들 중 최솟값(0이 아닌)을 찾아 그 만큼 한번에 감소시키는 것이 시간 복잡도를 개선.
// 그러나, food_times 원소들 중 최솟값(0이 아닌)을 1)찾고, 2)감소 시키는데 O(food_times.length) 만큼 걸리고 전체 시간복잡도는 O(food_length^2)로 개선되었지만 시간초과로 더 개선해야 함.
// food_times 원소들 중 최솟값(0이 아닌)을 찾는 로직을 개선하기 위해, "정렬" 을 생각해볼 수 있음. 
// 따라서, food_times를 1번 정렬(O(food_times.length*lg(food_times.length))하면, 최솟값을 찾는 로직은 전부 합쳐 O(food_times.length)로 개선 가능.
// 그러나, food_times를 감소시키는데 O(food_times.length)이기 때문에 전체 시간복잡도는 여전히 O(food_time.length^2).
// (Idea) food_times를 감소시키지 않고 문제를 해결해야만 함. 이미 정렬한 food_times를 활용한다면, food_times를 감소시킬 필요 없이 문제 해결이 가능함.
// "정렬된 food_times에서 0이 아닌 food_time의 갯수를 O(1)으로 쉽게 파악할 수 있음!" (food_times 감소 로직의 목적은 0이 아닌 food_time만 방문하기 위함이었으므로, 감소가 더이상 필요없음.)
// food_times의 k%(0이 아닌 food_time의 갯수)번째 를 구하면 됨: O(food_times)
// 따라서 전체 시간복잡도를 O(food_times.lengthlg(food_times.length) + food_times.length) = O(food_times.length * lg(food_times_.length)) 로 개선할 수 있음.
// 설계를 했더라도 실제 구현은 매우 어려움.(높은 수준의 구현력을 요구)
// 정리하면 출제의도는 "정렬 및 구현".
// 주의사항: 효율성 2번 테스트 케이스의 경우, long long 자료형을 사용하지 않으면 rectangle이 그 값을 수용하지 못하여 fail. "자료형 활용 능력" 또한 출제 의도에 포함. 

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int update(vector<int> &food_times_sorted, int cur) {
    int height_cur = food_times_sorted[cur];
    for(;cur<food_times_sorted.size();cur++) {
        if(food_times_sorted[cur]>height_cur)   return cur;
    }
    return -1;
}

int solution(vector<int> food_times, long long k) {
    vector<int> food_times_sorted = food_times;
    sort(food_times_sorted.begin(),food_times_sorted.end());
    int sz = food_times.size();
    int height_prev=0, height_cur=food_times_sorted[0];
    int cur=0;
    while(true) {
        long long rectangle = ((long long)height_cur-height_prev)*(sz-cur);
        if(k-rectangle>=0) {
            k -= rectangle;
        }
        else {
            k %= (sz-cur);
            break;
        }
        
        cur = update(food_times_sorted, cur);
        if(cur==-1) return -1;
        height_prev = height_cur;
        height_cur = food_times_sorted[cur];
    }
    
    for(int i=0;i<food_times.size();i++) {
        if(food_times[i]>=height_cur) {
            if(--k<0)   return i+1;
        }
    }
}
