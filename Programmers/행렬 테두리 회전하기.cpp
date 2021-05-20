// 출제의도: "구햔", Time Complexity: O(n*(rows+columns)), Space Complexity: O(1). (n: queries.size)
// 첫 풀이는 배열을 추가하여 회전된 모습을 저장 후, 원래 배열(matrix)에 copy하는 형태로 구현. 연산은 3*10^8 수준으로 매우 많아 간신히 통과.
// copy를 사용하지 않고, 제자리(in-place) 회전이 가능하다는 사실을 깨닫고 재구현.

#include <string>
#include <vector>
#include <climits>
#include <iostream>ㅇ
using namespace std;

typedef pair<int,int>   Pos;

int matrix[101][101];

void setMatrix(int rows, int columns) {
    for(int i=1;i<=rows;i++) {
        for(int j=1;j<=columns;j++) {
            matrix[i][j] = columns*(i-1)+j;
        }
    }
}

int rotate_edge_of_rectangle(vector<int> query) {
    int min_edge_of_rectangle = INT_MAX;
    Pos left_top(query[0],query[1]), right_bottom(query[2],query[3]);
    int val_left_top = matrix[left_top.first][left_top.second]; 
    
    for(int i=left_top.first;i<right_bottom.first;i++) {
        min_edge_of_rectangle = min(min_edge_of_rectangle,matrix[i][left_top.second]);
        matrix[i][left_top.second] = matrix[i+1][left_top.second];
    }
    for(int i=left_top.second;i<right_bottom.second;i++) {
        min_edge_of_rectangle = min(min_edge_of_rectangle,matrix[right_bottom.first][i]);
        matrix[right_bottom.first][i] = matrix[right_bottom.first][i+1];
    }
    for(int i=right_bottom.first;i>left_top.first;i--) {
        min_edge_of_rectangle = min(min_edge_of_rectangle,matrix[i][right_bottom.second]);
        matrix[i][right_bottom.second] = matrix[i-1][right_bottom.second];
    }
    for(int i=right_bottom.second;i>left_top.second;i--) {
        min_edge_of_rectangle = min(min_edge_of_rectangle,matrix[left_top.first][i]);
        matrix[left_top.first][i] = matrix[left_top.first][i-1];
    }
    matrix[left_top.first][left_top.second+1] = val_left_top;
    return min_edge_of_rectangle;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    setMatrix(rows,columns);
    for(int i=0;i<queries.size();i++) {
        answer.push_back(rotate_edge_of_rectangle(queries[i]));
    }
    return answer;
}
