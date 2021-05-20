// 출제의도: "구현", Time Complexity: O(n*30000), Space Complexity: O(1). (n: queries.size)
// 연산 10^4(queries.size) * c*10^4(copy)(c<10)으로 10^8보다 크지만 10^9보다 작음. 아슬아슬하게 통과. copy 복잡도를 O(row*columns)로 개선 가능하고, copy없이 해결할 수도 있음.

#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

typedef pair<int,int>   Pos;

int matrix[101][101];   // idx:1~100

void setMatrix(int rows, int columns) {
    for(int i=1;i<=rows;i++) {
        for(int j=1;j<=columns;j++) {
            matrix[i][j] = columns*(i-1)+j;
        }
    }
}

int rotate_edge_of_rectangle(vector<int> query) {
    int min_edge_of_rectangle=INT_MAX;
    int matrix_rotated[101][101];
    copy(&matrix[0][0],&matrix[0][0]+101*101,&matrix_rotated[0][0]);
    Pos leftTop(query[0],query[1]), rightBottom(query[2],query[3]);
    
    for(int i=leftTop.second;i<rightBottom.second;i++) {
        matrix_rotated[leftTop.first][i+1] = matrix[leftTop.first][i];
        min_edge_of_rectangle = min(min_edge_of_rectangle,matrix[leftTop.first][i]);
    }
    for(int i=leftTop.first;i<rightBottom.first;i++) {
        matrix_rotated[i+1][rightBottom.second] = matrix[i][rightBottom.second];
        min_edge_of_rectangle = min(min_edge_of_rectangle,matrix[i][rightBottom.second]);
    }
    for(int i=rightBottom.second;i>leftTop.second;i--) {
        matrix_rotated[rightBottom.first][i-1] = matrix[rightBottom.first][i];
        min_edge_of_rectangle = min(min_edge_of_rectangle,matrix[rightBottom.first][i]);
    }
    for(int i=rightBottom.first;i>leftTop.first;i--) {
        matrix_rotated[i-1][leftTop.second] = matrix[i][leftTop.second];
        min_edge_of_rectangle = min(min_edge_of_rectangle,matrix[i][leftTop.second]);
    }
    copy(&matrix_rotated[0][0],&matrix_rotated[0][0]+101*101,&matrix[0][0]);
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
