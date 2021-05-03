// 출제의도: "구현"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int,int>   Pos;

struct Type {
    vector<Pos> body;
    vector<Pos> check;
};

struct Block {
    int type;
    Pos top;
    Block(int Type, Pos Top):type(Type),top(Top){}
};

vector<Type> type(5);

bool isOutOfBound(vector<vector<int>> &board, Pos pos) {
    int N = board.size();
    if(pos.first<0 || pos.first>=N || pos.second<0 || pos.second>=N)   return true;
    return false;
}

int getType(vector<vector<int>> &board, Pos pos) {
    int no = board[pos.first][pos.second];
    for(int i=0;i<type.size();i++) {
        int cnt=1;
        for(int j=0;j<type[i].body.size();j++) {
            Pos next = Pos(pos.first+type[i].body[j].first,pos.second+type[i].body[j].second);
            if(!isOutOfBound(board,next) && board[next.first][next.second]==no)  cnt++;
        }
        if(cnt==4)  return i;
    }
    return -1;
}

bool isPossibleToPop(vector<vector<int>> &board, Block block) {
    if(block.type==-1)  return false;
    
    for(int i=0;i<type[block.type].check.size();i++) {
        Pos check = Pos(block.top.first+type[block.type].check[i].first,block.top.second+type[block.type].check[i].second);
        for(int i=check.first;i>=0;i--) {
            if(board[i][check.second]!=0) {
                return false;
            }
        }
    }
    return true;
}

void pop(vector<vector<int>> &board, Block block) {
    board[block.top.first][block.top.second] = 0;
    for(int i=0;i<type[block.type].body.size();i++) { 
        board[block.top.first+type[block.type].body[i].first][block.top.second+type[block.type].body[i].second] = 0;
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int answer_prev = -1;
    vector<Block> blocks;
    
    type[0].body = {Pos(1,0),Pos(1,1),Pos(1,2)};
    type[0].check = {Pos(0,1),Pos(0,2)};
    type[1].body = {Pos(1,0),Pos(2,0),Pos(2,-1)};
    type[1].check = {Pos(0,-1),Pos(1,-1)};
    type[2].body = {Pos(1,0),Pos(2,0),Pos(2,1)};
    type[2].check = {Pos(0,1),Pos(1,1)};
    type[3].body = {Pos(1,0),Pos(1,-1),Pos(1,-2)};
    type[3].check = {Pos(0,-1),Pos(0,-2)};
    type[4].body = {Pos(1,0),Pos(1,-1),Pos(1,1)};
    type[4].check = {Pos(0,1),Pos(0,-1)};
    
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[0].size();j++) {
            int type = getType(board,Pos(i,j));
            if(board[i][j]!=0 && type!=-1) {
                blocks.push_back(Block(type,Pos(i,j)));
            }
        }
    }
    while(answer!=answer_prev)
    {
        answer_prev = answer;
        for(int i=0;i<blocks.size();i++) {
            if(isPossibleToPop(board,blocks[i])) {
                answer++;
                pop(board,blocks[i]);
                blocks[i].type=-1;
            }
        }
    }
    return answer;
}
