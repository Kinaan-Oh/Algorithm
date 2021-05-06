// 출제의도: "bfs or dfs", Time Complexity: O(mn), Space Complexity: O(mn).

#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int>   Pos;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[101][101]; // idx: 1~100

bool isOutOfBound(vector<vector<int>> &picture, Pos pos) {
    int m = picture.size();
    int n = picture[0].size();
    if(pos.first<0 || pos.first>=m || pos.second<0 || pos.second>=n)    return true;
    return false;
}

void dfs(vector<vector<int>> &picture, int &size_of_one_area, Pos pos) {
    for(int i=0;i<4;i++) {
        Pos next = Pos(pos.first+dx[i], pos.second+dy[i]);
        if(isOutOfBound(picture,next) || visited[next.first][next.second] || picture[next.first][next.second]!=picture[pos.first][pos.second])  continue;
        
        visited[next.first][next.second] = true;
        dfs(picture,++size_of_one_area,next);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    fill(&visited[0][0],&visited[0][0]+101*101,false);
    for(int i=0;i<picture.size();i++) {
        for(int j=0;j<picture[0].size();j++) {
            if(!visited[i][j] && picture[i][j]!=0) {
                number_of_area++;
                int size_of_one_area=1;
                visited[i][j]=true;
                dfs(picture, size_of_one_area, Pos(i,j));
                max_size_of_one_area = max(max_size_of_one_area, size_of_one_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
