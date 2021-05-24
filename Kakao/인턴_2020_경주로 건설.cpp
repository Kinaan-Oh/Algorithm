// 출제의도: "bfs, dp"
// 이 문제의 경우 board상 임의의 한 지점에 대한 탐색여부에 대한 결정은 단순히 과거에 방문(visited)사실만으로 판단이 불가. 과거에 방문이 되었더라도, 1. 방향(dir) 2. 비용 을 고려하여 탐색여부를 결정. 
// 여기서, 2. 비용 은 "일반적인 bfs에서 과거에 방문된 지점에 대한 비용은 나중에 방문할 경우 반드시 더 비싸다" 라는 가정이 성립되지 않음. 코너링의 비용이 500으로 이동비용(100) 보다 훨씬 비싸므로,
// hop(홉)이 더 많다고 해서 비용이 반드시 비싸다고 할 수는 없게 됨. 따라서, 해당 지점에 대해 방문 비용을 저장해놓고, 나중에 더 저렴한 비용으로 방문(충분히 가능하다)하게 되면 업데이트하고 탐색을 진행함.
// 이 문제에서 주의사항은, 초기위치(0,0)에서 이동할 경우 코너는 형성되지 않는다는 것을 고려해주어야함.

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

typedef pair<int,int>   Pos;

struct Car {
    Pos pos;
    int dir;
    int cost;
    Car(Pos p,int D,int C=0):pos(p),dir(D),cost(C){}
};

int dx[4] = {1,0,-1,0};     // dir: South East North West
int dy[4] = {0,1,0,-1};     
int cost[25][25][4];    // [x][y][dir]
int answer = INT_MAX;

bool is_out_of_bound(int sz, Pos pos) {
    if(pos.first<0 || pos.first>=sz || pos.second<0 || pos.second>=sz)  return true;
    return false;
}

void bfs(vector<vector<int>> &board) {
    int sz_of_board = board.size();
    Pos dest = Pos(sz_of_board-1,sz_of_board-1);
    queue<Car>  que;
    cost[0][0][0] = cost[0][0][1] = 0;
    if(!board[1][0]) {
        cost[1][0][0] = 100;
        que.push(Car(Pos(1,0),0,100));
    }
    if(!board[0][1]) {
        cost[0][1][1] = 100;
        que.push(Car(Pos(0,1),1,100));
    }
    
    while(!que.empty()) {
        Car car_cur = que.front();
        que.pop();
        if(car_cur.pos == dest)  answer = min(answer, car_cur.cost);
        
        for(int i=0;i<4;i++) {
            Pos pos_next = Pos(car_cur.pos.first+dx[i], car_cur.pos.second+dy[i]);
            int cost_next = car_cur.dir!=i ? car_cur.cost+600 : car_cur.cost+100;
            if(is_out_of_bound(sz_of_board,pos_next) || cost[pos_next.first][pos_next.second][i]<=cost_next || board[pos_next.first][pos_next.second]) continue;
            
            cost[pos_next.first][pos_next.second][i] = cost_next;
            que.push(Car(pos_next,i,cost_next));
        }
    }
}

int solution(vector<vector<int>> board) {
    fill(&cost[0][0][0],&cost[0][0][0]+25*25*4,INT_MAX);
    bfs(board);
    return answer;
}
