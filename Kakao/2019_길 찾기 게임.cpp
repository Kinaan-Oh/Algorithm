// 출제의도: "정렬, 트리 삽입/순회", Time Complexity: O(nodeinfo_length^2)(이진트리의 높이가 nodeinfo_length가 되는 경우 삽입복잡도가 최악), Space Complexity: O(node_info.length).

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct nodeInfo {
    int no;
    int x, y;
    nodeInfo():no(0),x(0),y(0){}
    nodeInfo(int No, int X, int Y):no(No),x(X),y(Y){}
};

struct Tree {
    nodeInfo info;
    Tree *left, *right;
    Tree():left(nullptr),right(nullptr){}
    Tree(nodeInfo info) {
        this->info = info;
        left = nullptr;
        right = nullptr;
    }
    void insert(nodeInfo &info) {
        if(this->info.no==0) {
            this->info = info;
            return;
        }
        
        if(info.x<this->info.x) {
            if(left)    left->insert(info);
            else    left = new Tree(info);
        }
        else {
            if(right)    right->insert(info);
            else    right = new Tree(info);
        }
    }
    
    void preorder(vector<int> &visited) {
        visited.push_back(info.no);
        if(left)    left->preorder(visited);
        if(right)   right->preorder(visited);
    }
    
    void postorder(vector<int> &visited) {
        if(left)    left->postorder(visited);
        if(right)   right->postorder(visited);
        visited.push_back(info.no);
    }
};

bool compare(nodeInfo &info1, nodeInfo &info2) {
    if(info1.y==info2.y)    return info1.x<info2.x;
    return info1.y>info2.y;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<int> preorder, postorder;
    vector<nodeInfo> nodeInfos;
    Tree btree;
    for(int i=0;i<nodeinfo.size();i++) {
        nodeInfos.push_back(nodeInfo(i+1,nodeinfo[i][0],nodeinfo[i][1]));
    }
    sort(nodeInfos.begin(),nodeInfos.end(),compare);
    for(int i=0;i<nodeInfos.size();i++) {
        btree.insert(nodeInfos[i]);
    }
    btree.preorder(preorder);
    btree.postorder(postorder);
    answer = {preorder, postorder};
    return answer;
}
