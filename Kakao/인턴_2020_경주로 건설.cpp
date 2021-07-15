// 출제의도: "bfs, dp"
// 이 문제의 경우 board상 임의의 한 지점에 대한 탐색여부에 대한 결정은 단순히 과거에 방문(visited)사실만으로 판단이 불가. 과거에 방문이 되었더라도, 1. 방향(dir) 2. 비용 을 고려하여 탐색여부를 결정. 
// 즉, 임의 지점에서 현재 방향에 따라 미래 비용(코너링 횟수)이 좌우됨. 따라서, 반드시 방향을 고려해주어야 함.(2020 공채 블록 이동하기 문제도 방향 성분을 고려해야하는 되는 문제)
// 이 문제에서 주의사항은, 초기위치(0,0)에서 이동할 경우 코너는 형성되지 않는다는 것을 고려해주어야함.

// [7/15] 코드 개선

#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>>    board;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}; // 0:east, 1:south, 2:west, 3:north
int cost[25][25][4];    // [x][y][dir]

struct Pos {
    int x, y;
    
    Pos(int X,int Y): x(X),y(Y) {}
    
    Pos operator+(Pos target) {
        return Pos(x+target.x, y+target.y);
    }
    
    bool operator==(Pos target) {
        return x==target.x && y==target.y;
    }
    
    bool is_out_of_bound() {
        int N = board.size();
        if(x<0 || x>=N || y<0 || y>=N)  return true;
        return false;
    }
};

struct Car {
    Pos pos;
    int cost;
    int dir;    // 0:east, 1:south, 2:west, 3:north     
    
    Car(Pos p, int c,int d): pos(p),cost(c),dir(d) {}  
};

int bfs() {
    int N = board.size();
    Pos dest = Pos(N-1,N-1);
    queue<Car>  que;
    cost[0][0][0] = 0, cost[0][0][1] = 0, cost[0][0][2] = 0, cost[0][0][3] = 0;
    que.push(Car(Pos(0,0),0,0));
    
    while(!que.empty()) {
        Car cur = que.front();
        
        que.pop();
        if(cur.pos == dest)    continue;
        
        for(int dir=0;dir<4;dir++) {
            Pos next_pos = cur.pos + Pos(dx[dir],dy[dir]);
            if(next_pos.is_out_of_bound() || board[next_pos.x][next_pos.y])    continue;
            
            int cost_corner = (abs(cur.dir-dir)==1 || abs(cur.dir-dir)==3) && !(cur.pos==Pos(0,0)) ? 500 : 0;
            int next_cost = cur.cost + 100 + cost_corner;

            if(next_cost>=cost[next_pos.x][next_pos.y][dir])    continue;
            
            cost[next_pos.x][next_pos.y][dir] = next_cost;
            que.push(Car(next_pos, next_cost, dir));
        }
    }
    
    return min(cost[N-1][N-1][0], cost[N-1][N-1][1]);
}

int solution(vector<vector<int>> param0) {
    board = param0;
    fill(&cost[0][0][0], &cost[0][0][0]+25*25*4, INT_MAX);
    int answer = bfs();
    return answer;
}

// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <climits>
// #include <iostream>

// using namespace std;

// typedef pair<int,int>   Pos;

// struct Car {
//     Pos pos;
//     int dir;
//     int cost;
//     Car(Pos p,int D,int C=0):pos(p),dir(D),cost(C){}
// };

// int dx[4] = {1,0,-1,0};     // dir: South East North West
// int dy[4] = {0,1,0,-1};     
// int cost[25][25][4];    // [x][y][dir]
// int answer = INT_MAX;

// bool is_out_of_bound(int sz, Pos pos) {
//     if(pos.first<0 || pos.first>=sz || pos.second<0 || pos.second>=sz)  return true;
//     return false;
// }

// void bfs(vector<vector<int>> &board) {
//     int sz_of_board = board.size();
//     Pos dest = Pos(sz_of_board-1,sz_of_board-1);
//     queue<Car>  que;
//     cost[0][0][0] = cost[0][0][1] = 0;
//     if(!board[1][0]) {
//         cost[1][0][0] = 100;
//         que.push(Car(Pos(1,0),0,100));
//     }
//     if(!board[0][1]) {
//         cost[0][1][1] = 100;
//         que.push(Car(Pos(0,1),1,100));
//     }
    
//     while(!que.empty()) {
//         Car car_cur = que.front();
//         que.pop();
//         if(car_cur.pos == dest)  answer = min(answer, car_cur.cost);
        
//         for(int i=0;i<4;i++) {
//             Pos pos_next = Pos(car_cur.pos.first+dx[i], car_cur.pos.second+dy[i]);
//             int cost_next = car_cur.dir!=i ? car_cur.cost+600 : car_cur.cost+100;
//             if(is_out_of_bound(sz_of_board,pos_next) || cost[pos_next.first][pos_next.second][i]<=cost_next || board[pos_next.first][pos_next.second]) continue;
            
//             cost[pos_next.first][pos_next.second][i] = cost_next;
//             que.push(Car(pos_next,i,cost_next));
//         }
//     }
// }

// int solution(vector<vector<int>> board) {
//     fill(&cost[0][0][0],&cost[0][0][0]+25*25*4,INT_MAX);
//     bfs(board);
//     return answer;
// }
