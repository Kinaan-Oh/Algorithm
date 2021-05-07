// 출제의도: "구현", Time Complexity: O((M+N)^2*(M^2+N^2)), Space Complexty: O((M+N)^2).

#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int,int>   Pos;
int M, N;

void rotate_clockwise_90(vector<vector<int>> &key) {
    vector<vector<int>> key_rotated = key;
    for(int i=0;i<M;i++) {
        for(int j=0;j<M;j++) {
            key_rotated[j][M-1-i] = key[i][j]; 
        }
    }
    key = key_rotated;
}

void map_key(vector<vector<int>> &key_union_lock, vector<vector<int>> &key, Pos left_top) {
    for(int i=0;i<M;i++) {
        for(int j=0;j<M;j++) {
            key_union_lock[left_top.first+i][left_top.second+j] += key[i][j];
        }
    }
}

void map_lock(vector<vector<int>> &key_union_lock, vector<vector<int>> &lock) {
    for(int i=M-1;i<=N+M-2;i++) {
        for(int j=M-1;j<=N+M-2;j++) {
            key_union_lock[i][j] = lock[i-(M-1)][j-(M-1)];
        }
    }
}

bool check_key_fits_lock(vector<vector<int>> &key_union_lock) {
    for(int i=M-1;i<=N+M-2;i++) {
        for(int j=M-1;j<=N+M-2;j++) {
            if(key_union_lock[i][j]!=1)   return false;
        }
    }
    return true;
}

bool insert_key_into_lock(vector<vector<int>> &key, vector<vector<int>> &lock) {
    for(int i=0;i<=N+M-2;i++) {
        for(int j=0;j<=N+M-2;j++) {
            vector<vector<int>> key_union_lock(N+2*M-2,vector<int>(N+2*M-2,0));
            map_lock(key_union_lock, lock);
            map_key(key_union_lock,key,Pos(i,j));
            if(check_key_fits_lock(key_union_lock))   return true;
        }
    }
    return  false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    M = key.size();
    N = lock.size();
    for(int d=90;d<=360;d+=90) {
        rotate_clockwise_90(key);
        if(insert_key_into_lock(key,lock)) {
            answer = true;
            break;
        }
    }
    return answer;
}
