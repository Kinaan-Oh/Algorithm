// 출제의도: "해시, 정렬", Time Complexity: O(nlgn), Space Complexity: O(n).

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string,int>  sum_of_genre; // [genre,count]
unordered_map<string,int> num_of_genre; // [genre,count]
vector<string>  genres_copied;
vector<int> plays_copied;

bool compare(int id1, int id2) {
    if(sum_of_genre[genres_copied[id1]]==sum_of_genre[genres_copied[id2]]) {
        if(plays_copied[id1]==plays_copied[id2]) {
            return id1<id2;
        }
        return plays_copied[id1]>plays_copied[id2];
    }
    return sum_of_genre[genres_copied[id1]]>sum_of_genre[genres_copied[id2]];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<int> id;
    genres_copied = genres;
    plays_copied = plays;
    for(int i=0;i<genres.size();i++) {
        sum_of_genre[genres[i]] += plays[i];
    }
    for(int i=0;i<genres.size();i++)    id.push_back(i);
    sort(id.begin(),id.end(),compare);
    for(int i=0;i<id.size();i++) {
        if(num_of_genre[genres[id[i]]]<2) {
            answer.push_back(id[i]);
            num_of_genre[genres[id[i]]]++;
        }
    }
    return answer;
}
